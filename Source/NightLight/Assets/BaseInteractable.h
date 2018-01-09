// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseGrabable.h"
#include "BaseInteractable.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ABaseInteractable : public ABaseGrabable
{
	GENERATED_BODY()
	

protected:
	ABaseInteractable();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;	
};
