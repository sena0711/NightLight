// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTorch.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SpotLightComponent.h"
#include "Player/NBCharacter.h"

// Sets default values
ABaseTorch::ABaseTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxEnergy = 100.0f;
	CurrentEnergy = MaxEnergy;


	TorchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TorchMesh"));
	TorchMesh->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	TorchMesh->SetNotifyRigidBodyCollision(true);
	TorchMesh->SetCollisionObjectType(ECC_WorldDynamic);
	TorchMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	TorchMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	TorchMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);


	TorchSpotlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	TorchSpotlight->SetupAttachment(TorchMesh);
	TorchSpotlight->SetRelativeRotation(FRotator(0, 0, 0));
	TorchSpotlight->SetRelativeLocation(FVector(0, 0, -0));


}

// Called when the game starts or when spawned
void ABaseTorch::BeginPlay()
{
	Super::BeginPlay();
	
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

void ABaseTorch::DrainEnergy(float EnergyToAdd)
{
}

void ABaseTorch::SetOwningPawn(ANBCharacter * NewOwner)
{
	if (MyPawn == NewOwner)
	{
		Instigator = NewOwner;
		MyPawn = NewOwner;
	}
}

