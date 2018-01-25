// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_BaseAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"




ANB_BaseAIController::ANB_BaseAIController()
{
	
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void ANB_BaseAIController::BeginPlay()
{
}

void ANB_BaseAIController::Possess(APawn * InPawn)
{
}

void ANB_BaseAIController::UnPossess()
{
}
