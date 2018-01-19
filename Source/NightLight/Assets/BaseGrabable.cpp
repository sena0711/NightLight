// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrabable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"



ABaseGrabable::ABaseGrabable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHoldable = true;
	bEngagingOn = false;
	EngagingBarMaxValue = 100.0f;
	EngagingCurrentValue = 0.0f;
	IncrementRate = 0.5f;
	bEngagingComplete = false;


	PickupMesh->SetSimulatePhysics(false);
}
void ABaseGrabable::IncrementEngagingCurrentValue(float Val)
{
	if (bEngagingComplete == false)
	{
		IncrementValue = Val;
		GetWorldTimerManager().SetTimer(AddEngagingValueTimerHandle, this, &ABaseGrabable::AddToEngagingCurrentValue, IncrementRate, true);
	}
}

void ABaseGrabable::AddToEngagingCurrentValue()
{
	if (bEngagingComplete == false)
	{
		if (EngagingCurrentValue > EngagingBarMaxValue)
		{
			EngagingCurrentValue = EngagingBarMaxValue;
			bEngagingComplete = true;
			bEngagingOn = false;
			GetWorldTimerManager().ClearTimer(AddEngagingValueTimerHandle);
			WhenEngagingComplete();
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
}
void ABaseGrabable::SpawnGrabable(TSubclassOf<class ABaseGrabable> SpawnObj)
{
	FActorSpawnParameters SpawnParams;
	// if current weapon is empty assign current weapon
	if (SpawnObj != nullptr)
	{
		SpawnObject = GetWorld()->SpawnActor<ABaseGrabable>(SpawnObj, SpawnParams);
		//CurrentWeapon->SetOwningPawn(this);
	}


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

