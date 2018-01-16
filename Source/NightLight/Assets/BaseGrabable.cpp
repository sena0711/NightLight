// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrabable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"



ABaseGrabable::ABaseGrabable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHoldable = true;
	bEngagingOn = false;
	EngagingBarMaxValue = 100.0f;
	EngagingCurrentValue = 0.0f;
	IncrementRate = 0.5f; 


	PickupMesh->SetSimulatePhysics(false);
	SecondaryMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondaryMesh"));
	SecondaryMesh->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	SecondaryMesh->SetSimulatePhysics(false);
	SecondaryMesh->SetupAttachment(PickupMesh);
}
void ABaseGrabable::IncrementEngagingCurrentValue(float Val)
{
	IncrementValue = Val;
	GetWorldTimerManager().SetTimer(AddEngagingValueTimerHandle, this, &ABaseGrabable::AddToEngagingCurrentValue, IncrementRate, true);
}

void ABaseGrabable::AddToEngagingCurrentValue()
{
	if (EngagingCurrentValue > EngagingBarMaxValue)
	{
		EngagingCurrentValue = EngagingBarMaxValue;
		bEngagingOn = false; 
		GetWorldTimerManager().ClearTimer(AddEngagingValueTimerHandle);
	}
	else if (EngagingCurrentValue < 0.0f)
	{
		EngagingCurrentValue = 0.0f;
		bEngagingOn = false;
		GetWorldTimerManager().ClearTimer(AddEngagingValueTimerHandle);
	}
	else
	{

		EngagingCurrentValue = EngagingCurrentValue + IncrementValue;
	}
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

