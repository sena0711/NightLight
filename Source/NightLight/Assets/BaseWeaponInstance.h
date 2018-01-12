// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseWeapon.h"
#include "BaseWeaponInstance.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ABaseWeaponInstance : public ABaseWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseWeaponInstance();

	/************************************************************************/
	/* Damage Processing                                                    */
	/************************************************************************/

	virtual void FireWeapon() override;

	void DealDamage(const FHitResult& Impact, const FVector& ShootDir);

	void ProcessInstantHit(const FHitResult& Impact, const FVector& Origin, const FVector& ShootDir);

private:

	/************************************************************************/
	/* Visual Handlers                                                      */
	/************************************************************************/

	void SimulateInstantHit(const FVector& ImpactPoint);

	void VisualImpactEffects(const FHitResult& Impact);

//	void VisualTrailEffects(const FVector& EndPoint);

	/* Particle FX played when a surface is hit. */
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ABaseImpactEffect> ImpactTemplate;

	UPROPERTY(EditDefaultsOnly)
		FName TrailTargetParam;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* TrailFX;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* TracerFX;

	/* Minimum firing distance before spawning tracers or trails. */
	UPROPERTY(EditDefaultsOnly)
		float MinimumProjectileSpawnDistance;

	UPROPERTY(EditDefaultsOnly)
		int32 TracerRoundInterval;

	/* Keeps track of number of shots fired */
	int32 BulletsShotCount;


};