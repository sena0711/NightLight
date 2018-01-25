// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/NB_BaseCharacter.h"
#include "NB_NPC.generated.h"

/**
 * 
 */
UCLASS()
class NB_AIPLUGIN_API ANB_NPC : public ANB_BaseCharacter
{
	GENERATED_BODY()
		// Sets default values for this character's properties
		ANB_NPC();
protected:
		/* The thinking part of the brain, steers our zombie and makes decisions based on the data we feed it from the Blackboard */
		/* Assigned at the Character level (instead of Controller) so we may use different zombie behaviors while re-using one controller. */
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	/* Plays the idle, wandering or hunting sound */
	UPROPERTY(VisibleAnywhere, Category = "Sound")
		UAudioComponent* AudioLoopComp;

	//AI seeing, Sensing component
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;
		/* Triggered by pawn sensing component when a pawn is spotted */
		/* When using functions as delegates they need to be marked with UFUNCTION(). We assign this function to FSeePawnDelegate */
public :

	UFUNCTION()
		virtual void OnSeePlayer(APawn* Pawn);

	UFUNCTION()
		virtual void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);


	
};
