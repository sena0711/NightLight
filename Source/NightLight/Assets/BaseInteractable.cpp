// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseInteractable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"




ABaseInteractable::ABaseInteractable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}
void ABaseInteractable::BeginPlay()
{
	PickupMesh->SetSimulatePhysics(false);

}
// Called every frame
void ABaseInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
