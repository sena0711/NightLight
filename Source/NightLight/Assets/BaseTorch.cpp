// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTorch.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SpotLightComponent.h"
#include "TimerManager.h"
#include "Player/NBCharacter.h"

// Sets default values
ABaseTorch::ABaseTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxEnergy = 100.0f;
	CurrentEnergy = MaxEnergy;
	EnergyReductionRate = 0.5f;
	ReductionTimerRate = 0.5f;

	TorchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TorchMesh"));
	TorchMesh->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	TorchMesh->SetNotifyRigidBodyCollision(true);
	TorchMesh->SetCollisionObjectType(ECC_WorldDynamic);
	TorchMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	TorchMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	TorchMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	TorchCollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightCollision"));
	TorchCollisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TorchCollisionMesh->SetupAttachment(TorchMesh);
	TorchCollisionMesh->SetRelativeRotation(FRotator(0, 0, 0));
	TorchCollisionMesh->SetRelativeLocation(FVector(0, 0, -0));


	TorchSpotlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	TorchSpotlight->SetupAttachment(TorchMesh);
	TorchSpotlight->SetRelativeRotation(FRotator(0, 0, 0));
	TorchSpotlight->SetRelativeLocation(FVector(0, 0, -0));


}

// Called when the game starts or when spawned
void ABaseTorch::BeginPlay()
{
	Super::BeginPlay();
	SetVisiblity(true);
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

void ABaseTorch::DrainEnergy()
{
	if (CurrentEnergy <= 0)
	{
		CurrentEnergy = 0;
		SetVisiblity(false);
		GetWorldTimerManager().ClearTimer(StartReducingEnergyTimerHandle);

	}
	else
	{
		CurrentEnergy = CurrentEnergy - EnergyReductionRate;
		
	}
}

void ABaseTorch::SetVisiblity(bool bVisiblity)
{
	// if there is energy
	if (CurrentEnergy > 0.0f)
	{
		TorchSpotlight->SetVisibility(bVisiblity);
		//if torch is on drain energy.
		if (bVisiblity == true)
		{
			GetWorldTimerManager().SetTimer(StartReducingEnergyTimerHandle, this, &ABaseTorch::DrainEnergy, ReductionTimerRate, true);
		}
		else // if torch is off stop draining energy.
		{
			GetWorldTimerManager().ClearTimer(StartReducingEnergyTimerHandle);
		}
	}
	else // if there is no energy left toggle visiblity.
	{
		TorchSpotlight->SetVisibility(false);
		GetWorldTimerManager().ClearTimer(StartReducingEnergyTimerHandle);
	}
}

bool ABaseTorch::GetVisiblity()
{
	IsTorchOn = TorchSpotlight->IsVisible();
	return IsTorchOn;
}

void ABaseTorch::SetOwningPawn(ANBCharacter * NewOwner)
{
	if (MyPawn == NewOwner)
	{
		Instigator = NewOwner;
		MyPawn = NewOwner;
	}
}

