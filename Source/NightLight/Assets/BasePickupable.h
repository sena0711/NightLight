// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseGrabable.h"
#include "../Core/TypeClass.h"
#include "../Assets/BaseWeapon.h"
#include "BasePickupable.generated.h"

/**
 * 
 */

UCLASS()
class NIGHTLIGHT_API ABasePickupable : public ABaseGrabable
{
	GENERATED_BODY()
protected:
		ABasePickupable();

		//vectorlength/ volumeMultiplierValue
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			FName InteractText;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			FName NameOfItem;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			EItemType ItemType;
		/*If the itemtype is weapon Which weapon*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			TSubclassOf <class ABaseWeapon> WeaponToHold;
		/*Related Value - float*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			float PickedUpValue;

public:

	//UFUNCTION(BlueprintImplementableEvent)
	virtual void Interact(class ANBPlayerController* playerController);

	EItemType GetItemType();

	TSubclassOf <class ABaseWeapon> GetWeaponToHold();
	//stack goes up. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
		int32 NumberOfItems;

	UFUNCTION(BlueprintCallable, Category = "Status")
		float GetPickedUpValue();

	UFUNCTION(BlueprintCallable, Category = "Status")
		FName GetNameOfItem();

	//UFUNCTION(BlueprintImplementableEvent)
	//	void NotInFocus();
	
};
