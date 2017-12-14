// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseGrabable.h"
#include "../Core/TypeClass.h"
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
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
			FName InteractText;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
			EItemType ItemType;



public:

	//UFUNCTION(BlueprintImplementableEvent)
	virtual void Interact(class ANBPlayerController* playerController);

	EItemType GetItemType();
	//stack goes up.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		int32 NumberOfItems;

	//UFUNCTION(BlueprintImplementableEvent)
	//	void NotInFocus();
	
};
