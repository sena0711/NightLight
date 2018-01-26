// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Core/TypeClass.h"
#include "Framework/NB_BaseNPCharacter.h"
#include "NB_AICharacter.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ANB_AICharacter : public ANB_BaseNPCharacter
{
	GENERATED_BODY()
	
public:
	ANB_AICharacter();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* AttackWithRightHandAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* AttackWithLeftHandAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* AttackWithHeadAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* ReactAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* SearchAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* StunAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Status")
		ENPCPersonality NPCPersonality; 
protected:

	////Set AI State  using EBotBehaviorType
	//UFUNCTION(BlueprintCallable, Category = "AI")
	//	void SetAIState(EAIBehaviorType AIState);
	
};
