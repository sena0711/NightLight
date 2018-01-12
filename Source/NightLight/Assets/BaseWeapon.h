// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Core/TypeClass.h"
#include "BaseWeapon.generated.h"

UCLASS()
class NIGHTLIGHT_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Set the Torch's owning pawn */
	void SetOwningPawn(class ANBCharacter* NewOwner);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
		class USkeletalMeshComponent* WeaponMesh;
private:
	UPROPERTY(EditDefaultsOnly)
		FName MuzzleAttachPoint;
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Owning")
		class ANBCharacter* MyPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		EWeaponType WeaponType;

	//Weapon Config
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		FWeaponData WeaponConfig;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/************************************************************************/
	/* Fire & Damage Handling                                               */
	/************************************************************************/


	bool CanFire() const;

	FVector GetAdjustedAim() const;

	FVector GetMuzzleLocation() const;

	FVector GetMuzzleDirection() const;

	FVector GetCameraDamageStartLocation(const FVector& AimDir) const;

	FHitResult WeaponTrace(const FVector& TraceFrom, const FVector& TraceTo) const;

	/* With PURE_VIRTUAL we skip implementing the function in SWeapon.cpp and can do this in SWeaponInstant.cpp / SFlashlight.cpp instead */
	virtual void FireWeapon() PURE_VIRTUAL(ABaseWeapon::FireWeapon, );

public:	


	void StartFire();

	void StopFire();

//	/* You can assign default values to function parameters, these are then optional to specify/override when calling the function. */
	//void AttachMeshToPawn(EInventorySlot Slot = EInventorySlot::Hands);
	
};
