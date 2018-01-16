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
	/*When enging is on it will increment its value machine*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		bool bEngagingOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Engaging)
		float EngagingBarMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Engaging)
		float EngagingCurrentValue;

	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		void IncrementEngagingCurrentValue(float IncrementVal);

	//ShowWarning On screen
	FTimerHandle AddEngagingValueTimerHandle;
private:
	/*PrivateValue used for incrementation*/
	float IncrementValue;
	float IncrementRate;
	UFUNCTION()
		void AddToEngagingCurrentValue();


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		bool bHoldable;
	//we use this for things like door
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colllision")
		class UStaticMeshComponent* SecondaryMesh;


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
