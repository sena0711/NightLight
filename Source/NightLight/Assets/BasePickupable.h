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

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			EItemType ItemType;
		/*If the itemtype is weapon Which weapon*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
			TSubclassOf <class ABaseWeapon> WeaponToHold;
		/*Related Value - float*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
			float PickedUpValue;
		/*If the itemtype is bullet Which bullet*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
			EBulletType BulletTypes;
		/*If the itemtype Quest which Quest*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
			EQuestType QuestType;

public:

	//UFUNCTION(BlueprintImplementableEvent)
	virtual void Interact(class ANBPlayerController* playerController);

	EItemType GetItemType();

	EQuestType GetQuestType();

	TSubclassOf <class ABaseWeapon> GetWeaponToHold();

	//stack goes up. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
		int32 NumberOfItems;

	UFUNCTION(BlueprintCallable, Category = "Status")
		float GetPickedUpValue();

	UFUNCTION(BlueprintCallable, Category = "Status")
		FName GetNameOfItem();

	
};
