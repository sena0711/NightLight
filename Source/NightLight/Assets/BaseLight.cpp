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

}

// Called when the game starts or when spawned
void ABaseLight::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseLight::OnOverlapEnableInLight(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

void ABaseLight::OnEndOverlapDisableInLight(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

// Called every frame
void ABaseLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

