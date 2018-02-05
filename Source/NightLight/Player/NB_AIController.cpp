// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_AIController.h"
#include "NB_AICharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANB_AIController::ANB_AIController()
{
	PlayerCharacterKeyName = "PlayerCharacter";
	AIStateKeyName = "AIState";
	MoveToLocationKeyName = "MoveToLocation";
	SelfActorKeyName = "SelfActor";


}

void ANB_AIController::BeginPlay()
{
	Super::BeginPlay();
	//Set blackBoard Key as the controller begins. 
	ResetBlackBoardKeys(PlayerCharacterKeyName, AIStateKeyName, MoveToLocationKeyName);
}
void ANB_AIController::SetAIBehaviorStateAndKey(EAIBehaviorType NewState)
{
	ANB_AICharacter* AICharacter = Cast<ANB_AICharacter>(GetPawn());
	AICharacter->SetCurrentBehaviorState(NewState);
	SetAIStateKey(AIStateKeyName, NewState);
}
