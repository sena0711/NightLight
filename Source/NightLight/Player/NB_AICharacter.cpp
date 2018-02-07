// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_AICharacter.h"



ANB_AICharacter::ANB_AICharacter()
{
	NPCPersonality = ENPCPersonality::Shy;
	SetCurrentBehaviorState(EAIBehaviorType::Neutral);
	IsTalking = false; 
	IsReadyToTalk = false;
}

ENPCPersonality ANB_AICharacter::GetNPCPersonality()
{
	return NPCPersonality;
}

