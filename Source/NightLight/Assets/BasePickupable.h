// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseGrabable.h"
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
public:

	//	UFUNCTION(BlueprintImplementableEvent)
	//	void InFocus();

	//UFUNCTION(BlueprintImplementableEvent)
	//	void NotInFocus();
	
};
