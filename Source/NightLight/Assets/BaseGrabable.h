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

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bHoldable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colllision")
		class UStaticMeshComponent* SecondaryMesh;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		FVector GetLocationOfMesh();

	UFUNCTION(BlueprintImplementableEvent)
		void InFocus();

	UFUNCTION(BlueprintImplementableEvent)
		void NotInFocus();

};
