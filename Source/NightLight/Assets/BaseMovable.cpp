// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseMovable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseMovable::ABaseMovable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	//RootComponent = SceneComponent;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	PickupMesh->SetupAttachment(SceneComponent);
	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->BodyInstance.SetCollisionProfileName("PhysicsBody");
	PickupMesh->SetNotifyRigidBodyCollision(true);
	PickupMesh->OnComponentHit.AddDynamic(this, &ABaseMovable::WhenHit);

	volumeMultiplierValue = 1000000.0;;

}

// Called when the game starts or when spawned
void ABaseMovable::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseMovable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseMovable::WhenHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	//Get the length (magnitude) of this vector. 
	float vectorLength = 	NormalImpulse.Size();
	double ClampingValue = vectorLength / volumeMultiplierValue;
	float volumeMultiplierFinalValue = FMath::Clamp(ClampingValue, 0.0, 2.0);

	//playsoundAtLocation
	UGameplayStatics::PlaySoundAtLocation(this, SoundHit, Hit.Location, volumeMultiplierFinalValue);
}

FVector ABaseMovable::GetLocationOfMesh()
{
	return FVector();
}

