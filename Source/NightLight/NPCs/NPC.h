// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/BaseCharacter.h"
#include "NPC.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ANPC : public ABaseCharacter
{
	GENERATED_BODY()
protected:
	ANPC();

	UFUNCTION(BlueprintCallable, Category = "Monster")
		void SetWalkSpeed(float desiredWalkSpeed);
	
};
