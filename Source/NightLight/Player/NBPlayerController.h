// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define NOTEXISTING 100
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interact)
		bool bSearchReturnedNull;



public:
	/************************************************************************/
	/* Interaction With key press                                                      */
	/************************************************************************/

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void Interact();

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void PossessInteractedItem(class ABasePickupable * interactedItem);


	UFUNCTION(BlueprintCallable, Category = "Warning")
		void SetWarningText(FName fWarningText, float flength);

	UFUNCTION(BlueprintCallable, Category = "Warning")
		void UnSetWarningText();

	UFUNCTION(BlueprintCallable, Category = "Warning")
		bool GetbIsWarningOn();

	UFUNCTION(BlueprintCallable, Category = "Warning")
		FName GetWarningText();
protected:



	//ShowWarning On screen
	FTimerHandle ShowWarningOnScreenTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Warning)
		bool bIsWarningOn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Warning)
		FName WarningText;

	/************************************************************************/
	/* Pickups                                                              */
	/************************************************************************/

	/** InventoryItems  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		TArray<FInventoryItem> InventoryItems;

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void AddItemToArray(EItemType eItemType, int32 addingStacks);

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		int32 SearchInventoryItemsByType(EItemType eItemType);


	UFUNCTION(BlueprintCallable, Category = "Interactable")
		virtual void SetupInputComponent() override;

};
