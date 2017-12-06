// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NBPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ANBPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ANBPlayerController();


	//The interactable that player is currently looking at. 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interact)
		class ABaseGrabable* CurrentGrabable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interact)
		class ABasePickupable* CurrentPickupable;

public:


protected:


	/************************************************************************/
	/* Pickups                                                              */
	/************************************************************************/

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		virtual void SetupInputComponent() override;
};
