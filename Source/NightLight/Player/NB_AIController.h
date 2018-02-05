// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/NB_BaseAIController.h"
#include "NB_AIController.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ANB_AIController : public ANB_BaseAIController
{
	GENERATED_BODY()
public:
		ANB_AIController();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName PlayerCharacterKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName AIStateKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName MoveToLocationKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName SelfActorKeyName;
	

public:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void Possess(class APawn* InPawn) override;
	//virtual void UnPossess() override;

	//sets AI State and also black board key
	UFUNCTION(BlueprintCallable, Category = "BlackBoard")
		void SetAIBehaviorStateAndKey(EAIBehaviorType NewState);

};
