// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NB_BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class NB_AIPLUGIN_API ANB_BaseAIController : public AAIController
{
	GENERATED_BODY()
public:
	ANB_BaseAIController();

	/* Called whenever the controller possesses a character bot */

protected:
	// Behavior tree component
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBehaviorTreeComponent* BehaviorTreeComp;
	// Blackboard component reference
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBlackboardComponent* BlackboardComp;

public :
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Possess(class APawn* InPawn) override;
	virtual void UnPossess() override;

	void SetObjectKey(FName ObjectKeyName, APawn* ObjectReference);

	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorTreeComp; }
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

};
