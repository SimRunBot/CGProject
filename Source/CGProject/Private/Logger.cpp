// Fill out your copyright notice in the Description page of Project Settings.

#include "CGProject.h"
#include "Logger.h"

ofstream logfile;

// Sets default values
ALogger::ALogger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ALogger::~ALogger()
{
	stop();
}

// Called when the game starts or when spawned
void ALogger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALogger::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

bool ALogger::openFile(FString msg){
	stringstream stringStream;
	stringStream << "/home/leon/Dokumente/"<<TCHAR_TO_UTF8(*msg)<<".txt";
	string file = stringStream.str();
	if (ifstream(file)){
		return false;
	}
	stop();
	logfile.open(file);
	return true;
}

void ALogger::stop(){
	if (logfile.is_open()){
		logfile.close();
	}
}

void ALogger::log(FString msg){
	if (logfile.is_open()){
		logfile << TCHAR_TO_UTF8(*msg) << "\n";
	}
}

