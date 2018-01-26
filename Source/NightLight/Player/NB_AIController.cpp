// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_AIController.h"
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
	if(APawn* PlayerCharacter = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())
	{
		SetObjectKey(PlayerCharacterKeyName,PlayerCharacter);
	}
	
	
}
