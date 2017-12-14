// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Core/TypeClass.h"
#include "NBPlayerController.generated.h"


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
	/************************************************************************/
	/* Interaction With key press                                                      */
	/************************************************************************/

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void Interact();

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void PossessInteractedItem(class ABasePickupable * interactedItem);
	
protected:


	/************************************************************************/
	/* Pickups                                                              */
	/************************************************************************/
	/** InventoryItems  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		TArray<FInventoryItem> InventoryItems;
	
	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void AddItemToArray(EItemType eItemType, int32 addingStacks);

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		int32 SearchInventoryItemsByType(EItemType eItemType);


	UFUNCTION(BlueprintCallable, Category = "Interactable")
		virtual void SetupInputComponent() override;

};
