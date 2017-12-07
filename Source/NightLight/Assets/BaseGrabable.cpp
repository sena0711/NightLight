// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrabable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"



ABaseGrabable::ABaseGrabable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHoldable = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SceneComponent->SetupAttachment(PickupMesh);
}
// Called every frame
void ABaseGrabable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
FVector ABaseGrabable::GetLocationOfMesh()
{
	return GetActorLocation();
}
