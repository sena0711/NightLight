// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_BaseAIController.h"
#include "NB_BaseNPCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"



ANB_BaseAIController::ANB_BaseAIController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void ANB_BaseAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ANB_BaseAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	//Get the possessed character and check if its my own AI character
	class ANB_BaseNPCharacter* ABaseCharacter = Cast<ANB_BaseNPCharacter>(InPawn);
	if (ABaseCharacter)
	{
		// if the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (ABaseCharacter->GetBehaviorTree())
		{
			if (ABaseCharacter->GetBehaviorTree()->BlackboardAsset)
			{
				BlackboardComp->InitializeBlackboard(*(ABaseCharacter->GetBehaviorTree()->BlackboardAsset));
				//Start the behavior tree which corresponds to the specific character
				BehaviorTreeComp->StartTree(*(ABaseCharacter->GetBehaviorTree()));
			}
		}
	}
}

void ANB_BaseAIController::UnPossess()
{
	Super::UnPossess();

	/* Stop any behavior running as we no longer have a pawn to control */
	BehaviorTreeComp->StopTree();
}

void ANB_BaseAIController::SetObjectKey(FName ObjectKeyName, APawn * ObjectReference)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(ObjectKeyName, ObjectReference);
	}
}
