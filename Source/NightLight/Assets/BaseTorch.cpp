// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTorch.h"


// Sets default values
ABaseTorch::ABaseTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseTorch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseTorch::GetEnergy()
{
}

void ABaseTorch::AddEnergy(int EnergyToAdd)
{
}

void ABaseTorch::DrainEnergy(float EnergyToAdd)
{
}
