// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrabable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"



ABaseGrabable::ABaseGrabable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHoldable = true;
	PickupMesh->SetSimulatePhysics(false);
	SecondaryMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondaryMesh"));
	SecondaryMesh->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	SecondaryMesh->SetSimulatePhysics(false);
	SecondaryMesh->SetupAttachment(PickupMesh);
}
// Called every frame
void ABaseGrabable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
FVector ABaseGrabable::GetLocationOfMesh()
{
	SecondaryMesh->GetComponentLocation();

	return GetActorLocation();
}

