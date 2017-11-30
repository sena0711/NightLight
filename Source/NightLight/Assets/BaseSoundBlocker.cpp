// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseSoundBlocker.h"


// Sets default values
ABaseSoundBlocker::ABaseSoundBlocker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseSoundBlocker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSoundBlocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

