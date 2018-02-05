// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_BaseNPCharacter.h"
#include "Components/AudioComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

ANB_BaseNPCharacter::ANB_BaseNPCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AudioLoopComp = CreateDefaultSubobject<UAudioComponent>(TEXT("NPCSoundComp"));
	AudioLoopComp->bAutoActivate = false;
	AudioLoopComp->bAutoDestroy = false;
	AudioLoopComp->SetupAttachment(RootComponent);

	/* Our sensing component to detect players by visibility and noise checks. */
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;
	
}
void ANB_BaseNPCharacter::OnSeePlayer(APawn * Pawn)
{	
}

void ANB_BaseNPCharacter::OnHearNoise(APawn * PawnInstigator, const FVector & Location, float Volume)
{
}
