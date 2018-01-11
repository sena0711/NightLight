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

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
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
		void WhenInteracted();
	UFUNCTION(BlueprintImplementableEvent)
		void InFocus();

	UFUNCTION(BlueprintImplementableEvent)
		void NotInFocus();

};
