// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseMovable.h"
#include "BaseGrabable.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ABaseGrabable : public ABaseMovable
{
	GENERATED_BODY()

protected:
	ABaseGrabable();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Text)
		FName InteractText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Text)
		FName NameOfItem;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void IncrementEngagingCurrentValue(float IncrementVal);

	//ShowWarning On screen
	FTimerHandle AddEngagingValueTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		bool bEngagingComplete;
	/*When enging is on it will increment its value machine*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		bool bEngagingOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float EngagingBarMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float EngagingCurrentValue;



private:
	/*PrivateValue used for incrementation*/
	float IncrementValue;
	float IncrementRate;
	UFUNCTION()
		void AddToEngagingCurrentValue();

	
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		bool bHoldable;

	/************************************************************************/
	/* SpawnClass                                                       */
	/************************************************************************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		class ABaseGrabable *SpawnObject;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void SpawnGrabable(TSubclassOf <class ABaseGrabable> SpawnObj);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		TSubclassOf <class ABaseGrabable> SpawnClassOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		TSubclassOf <class ABaseGrabable> SpawnClassTwo;

	UFUNCTION(BlueprintImplementableEvent)
		void WhenEngagingComplete();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		FVector GetLocationOfMesh();

	UFUNCTION(BlueprintImplementableEvent)
		void WhenRightClicked();
	UFUNCTION(BlueprintImplementableEvent)
		void WhenInteracted();

	UFUNCTION(BlueprintImplementableEvent)
		void WhenRightClickReleased();
	UFUNCTION(BlueprintImplementableEvent)
		void WhenInteractReleased();

	UFUNCTION(BlueprintImplementableEvent)
		void InFocus();

	UFUNCTION(BlueprintImplementableEvent)
		void NotInFocus();

};
