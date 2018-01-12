// Fill out your copyright notice in the Description page of Project Settings.

#include "NightLight.h"
#include "BaseWeapon.h"
#include "Player/NBCharacter.h"
#include "Player/NBPlayerController.h"
#include "Components/SkeletalMeshComponent.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetVisibility(true);
	WeaponMesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	WeaponMesh->bReceivesDecals = true;
	WeaponMesh->CastShadow = true;
	WeaponMesh->SetCollisionObjectType(ECC_WorldDynamic);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	RootComponent = WeaponMesh;

	MuzzleAttachPoint = TEXT("MuzzleSocket");
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ABaseWeapon::CanFire() const
{
	return MyPawn->GetbIsAlive();
}

FVector ABaseWeapon::GetAdjustedAim() const
{
	
	ANBPlayerController* const PC = Instigator ? Cast<ANBPlayerController>(Instigator->Controller) : nullptr;
	FVector FinalAim = FVector::ZeroVector;

	if (PC)
	{
		FVector CamLoc;
		FRotator CamRot;
		PC->GetPlayerViewPoint(CamLoc, CamRot);

		FinalAim = CamRot.Vector();
	}
	else if (Instigator)
	{
		FinalAim = Instigator->GetBaseAimRotation().Vector();
	}

	return FinalAim;
}

FVector ABaseWeapon::GetMuzzleLocation() const
{
	return WeaponMesh->GetSocketLocation(MuzzleAttachPoint);
}

FVector ABaseWeapon::GetMuzzleDirection() const
{
	return WeaponMesh->GetSocketRotation(MuzzleAttachPoint).Vector();
}

FVector ABaseWeapon::GetCameraDamageStartLocation(const FVector & AimDir) const
{
	ANBPlayerController* PC = MyPawn ? Cast<ANBPlayerController>(MyPawn->Controller) : nullptr;
	FVector OutStartTrace = FVector::ZeroVector;

	if (PC)
	{
		FRotator DummyRot;
		PC->GetPlayerViewPoint(OutStartTrace, DummyRot);

		// Adjust trace so there is nothing blocking the ray between the camera and the pawn, and calculate distance from adjusted start
		OutStartTrace = OutStartTrace + AimDir * (FVector::DotProduct((Instigator->GetActorLocation() - OutStartTrace), AimDir));
	}

	return OutStartTrace;
}

FHitResult ABaseWeapon::WeaponTrace(const FVector & TraceFrom, const FVector & TraceTo) const
{
	FCollisionQueryParams TraceParams(TEXT("WeaponTrace"), true, Instigator);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, TraceFrom, TraceTo, WEAPON_TRACE, TraceParams);

	return Hit;
}

void ABaseWeapon::StartFire()
{
	
}

void ABaseWeapon::StopFire()
{
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::SetOwningPawn(ANBCharacter * NewOwner)
{
	if (MyPawn != NewOwner)
	{
		Instigator = NewOwner;
		MyPawn = NewOwner;
	}
}

