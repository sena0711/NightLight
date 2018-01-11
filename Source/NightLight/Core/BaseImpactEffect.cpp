// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseImpactEffect.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/Material.h"
//#include "Components/SceneComponent.h"
//#include "Sound/SoundBase.h"
#include "Components/PrimitiveComponent.h"
#include "Sound/SoundCue.h"

// Sets default values
ABaseImpactEffect::ABaseImpactEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bAutoDestroyWhenFinished = true;
	DecalLifeSpan = 10.0f;
	DecalSize = 16.0f;
}

void ABaseImpactEffect::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	/* Figure out what we hit (SurfaceHit is setting during actor instantiation in weapon class) */
	UPhysicalMaterial* HitPhysMat = SurfaceHit.PhysMaterial.Get();
	EPhysicalSurface HitSurfaceType = UPhysicalMaterial::DetermineSurfaceType(HitPhysMat);

	UParticleSystem* ImpactFX = GetImpactFX(HitSurfaceType);
	if (ImpactFX)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactFX, GetActorLocation(), GetActorRotation());
	}

	USoundCue* ImpactSound = GetImpactSound(HitSurfaceType);
	if (ImpactSound)
	{

		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}

	if (DecalMaterial)
	{
		FRotator RandomDecalRotation = SurfaceHit.ImpactNormal.Rotation();
		RandomDecalRotation.Roll = FMath::FRandRange(-180.0f, 180.0f);

		UGameplayStatics::SpawnDecalAttached(DecalMaterial, FVector(DecalSize, DecalSize, 1.0f),
			SurfaceHit.Component.Get(), SurfaceHit.BoneName,
			SurfaceHit.ImpactPoint, RandomDecalRotation, EAttachLocation::KeepWorldPosition,
			DecalLifeSpan);
	}
}

UParticleSystem* ABaseImpactEffect::GetImpactFX(EPhysicalSurface SurfaceType) const
{

	return DefaultFX;
	
}


USoundCue* ABaseImpactEffect::GetImpactSound(EPhysicalSurface SurfaceType) const
{
	return nullptr;
}