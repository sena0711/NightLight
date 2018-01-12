// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWeaponInstance.h"

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

void ABaseWeaponInstance::SimulateInstantHit(const FVector & ImpactPoint)
{
}

void ABaseWeaponInstance::VisualImpactEffects(const FHitResult & Impact)
{
}

void ABaseWeaponInstance::VisualTrailEffects(const FVector & EndPoint)
{
}
