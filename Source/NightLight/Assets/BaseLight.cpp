// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLight.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseLight::ABaseLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightSourceMesh = CreateDefaultSubobject<UStaticMeshComponent>("LightSourceMesh");

	LightVolumeCollision = CreateDefaultSubobject<UStaticMeshComponent>("LightVolumeCollision");
	LightVolumeCollision->SetRelativeLocation(FVector(0.0, 0.0, 0.0));

}

// Called when the game starts or when spawned
void ABaseLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

