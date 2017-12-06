// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrabable.h"




ABaseGrabable::ABaseGrabable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
