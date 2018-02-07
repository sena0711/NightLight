// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Behaivour/NB_ZoneActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"


// Sets default values
ANB_ZoneActor::ANB_ZoneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ZoneComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("ZoneComponent"));
	RootComponent = ZoneComponent;
}

// Called when the game starts or when spawned
void ANB_ZoneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANB_ZoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ANB_ZoneActor::GetRandomPointInVolume()
{
	FVector VectorOrigin = ZoneComponent->Bounds.Origin;
	FVector VectorExtent = ZoneComponent->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(VectorOrigin, VectorExtent);
}

