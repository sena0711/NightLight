// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWeaponInstance.h"
#include "../Core/BaseImpactEffect.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseWeaponInstance::ABaseWeaponInstance()
{

}

void ABaseWeaponInstance::FireWeapon()
{
	const FVector AimDir = GetAdjustedAim();
	const FVector CameraPos = GetCameraDamageStartLocation(AimDir);
	const FVector EndPos = CameraPos + (AimDir * WeaponConfig.WeaponRange);

	/* Check for impact by tracing from the camera position */
	FHitResult Impact = WeaponTrace(CameraPos, EndPos);

	const FVector MuzzleOrigin = GetMuzzleLocation();

	FVector AdjustedAimDir = AimDir;
	if (Impact.bBlockingHit)
	{
		/* Adjust the shoot direction to hit at the crosshair. */
		AdjustedAimDir = (Impact.ImpactPoint - MuzzleOrigin).GetSafeNormal();

		/* Re-trace with the new aim direction coming out of the weapon muzzle */
		Impact = WeaponTrace(MuzzleOrigin, MuzzleOrigin + (AdjustedAimDir * WeaponConfig.WeaponRange));
	}
	else
	{
		/* Use the maximum distance as the adjust direction */
		Impact.ImpactPoint = FVector_NetQuantize(EndPos);
	}

	//ProcessInstantHit(Impact, MuzzleOrigin, AdjustedAimDir)
}

void ABaseWeaponInstance::DealDamage(const FHitResult & Impact, const FVector & ShootDir)
{
}

void ABaseWeaponInstance::ProcessInstantHit(const FHitResult & Impact, const FVector & Origin, const FVector & ShootDir)
{
	// Handle damage

	// Play FX locally
	SimulateInstantHit(Impact.ImpactPoint);
}

void ABaseWeaponInstance::SimulateInstantHit(const FVector & ImpactPoint)
{
	const FVector MuzzleOrigin = GetMuzzleLocation();

	/* Adjust direction based on desired crosshair impact point and muzzle location */
	const FVector AimDir = (ImpactPoint - MuzzleOrigin).GetSafeNormal();

	const FVector EndTrace = MuzzleOrigin + (AimDir * WeaponConfig.WeaponRange);
	const FHitResult Impact = WeaponTrace(MuzzleOrigin, EndTrace);

	if (Impact.bBlockingHit)
	{
		VisualImpactEffects(Impact);
	}
}

void ABaseWeaponInstance::VisualImpactEffects(const FHitResult & Impact)
{
	if (ImpactTemplate && Impact.bBlockingHit)
	{
		// TODO: Possible re-trace to get hit component that is lost during replication.

		/* This function prepares an actor to spawn, but requires another call to finish the actual spawn progress. This allows manipulation of properties before entering into the level */
		ABaseImpactEffect* EffectActor = GetWorld()->SpawnActorDeferred<ABaseImpactEffect>(ImpactTemplate, FTransform(Impact.ImpactPoint.Rotation(), Impact.ImpactPoint));
		if (EffectActor)
		{
			EffectActor->SurfaceHit = Impact;
			UGameplayStatics::FinishSpawningActor(EffectActor, FTransform(Impact.ImpactNormal.Rotation(), Impact.ImpactPoint));
		}
	}
}

