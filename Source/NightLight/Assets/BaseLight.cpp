// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLight.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseLight::ABaseLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightSourceMesh = CreateDefaultSubobject<UStaticMeshComponent>("LightSourceMesh");
	LightSourceMesh->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	LightSourceMesh->SetNotifyRigidBodyCollision(true);

	LightVolumeCollision = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightVolumeCollision"));
	//TorchCollisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LightVolumeCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	LightVolumeCollision->SetupAttachment(LightSourceMesh);
	LightVolumeCollision->SetRelativeRotation(FRotator(0, 0, 0));
	LightVolumeCollision->SetRelativeLocation(FVector(0, 0, -0));
	LightVolumeCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseLight::OnOverlapEnableInLight);
	LightVolumeCollision->OnComponentEndOverlap.AddDynamic(this, &ABaseLight::OnEndOverlapDisableInLight);
	LightVolumeCollision->bHiddenInGame = true;

	MaxBattery = 100.0f;
	CurrentBattery = MaxBattery;
	bLightOnOFF = true;
}

// Called when the game starts or when spawned
void ABaseLight::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void ABaseLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SetLightOnOff(true);
}

void ABaseLight::OnOverlapEnableInLight(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//TODO : Trigger Condition

	WhenInLight();
}

void ABaseLight::OnEndOverlapDisableInLight(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//TODO :Trigger Condition

	WhenNotInLight();
}

bool ABaseLight::GetLightOnOff()
{
	return bLightOnOFF;
}
void ABaseLight::SetbLightOnOFF(bool bOnOFF)
{
	bLightOnOFF = bOnOFF;
}
bool ABaseLight::ProcessLight(bool bOnOFF)
{
	if (CurrentBattery <= 0.0f)
	{
		//NoBattery Turn Light OFF
		bLightOnOFF = false;
		return bLightOnOFF;
	}
	else
	{	//if switch is connected 
		if (ConnectedSwitch)
		{
			bLightOnOFF = ConnectedSwitch->GetSwitchOnOff();
		}
		else
		{
			SetbLightOnOFF(bOnOFF);
		}
		return bLightOnOFF;
	}

	return bLightOnOFF;
}

