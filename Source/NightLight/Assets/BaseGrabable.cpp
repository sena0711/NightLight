// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrabable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"



ABaseGrabable::ABaseGrabable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHoldable = true;

	HoldLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HoldLocation"));
	HoldLocation->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	HoldLocation->SetSimulatePhysics(false);
	HoldLocation->SetupAttachment(PickupMesh);
}
// Called every frame
void ABaseGrabable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
FVector ABaseGrabable::GetLocationOfMesh()
{
	HoldLocation->GetComponentLocation();

	return GetActorLocation();
}
