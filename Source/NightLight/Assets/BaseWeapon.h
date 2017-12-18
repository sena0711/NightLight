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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
		class USkeletalMeshComponent* WeaponMesh;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Owning")
		class ANBCharacter* MyPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
		EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		UTexture2D* WeaponImage2D;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Set the Torch's owning pawn */
	void SetOwningPawn(class ANBCharacter* NewOwner);


	
};
