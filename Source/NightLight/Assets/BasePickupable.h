// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseGrabable.h"
#include "BasePickupable.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Key,

	Health,

	Battery,

	Bullets,

	Torch,

	Weapon,

	Quest,

};

UCLASS()
class NIGHTLIGHT_API ABasePickupable : public ABaseGrabable
{
	GENERATED_BODY()
protected:
		ABasePickupable();

		//vectorlength/ volumeMultiplierValue
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
			FName InteractText;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
			EItemType ItemType;

public:

	//UFUNCTION(BlueprintImplementableEvent)
	virtual void Interact(APlayerController* playerController);


	//	UFUNCTION(BlueprintImplementableEvent)
	//	void InFocus();

	//UFUNCTION(BlueprintImplementableEvent)
	//	void NotInFocus();
	
};
