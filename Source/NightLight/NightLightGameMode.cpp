// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "NightLightGameMode.h"
#include "Player/NBCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANightLightGameMode::ANightLightGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Player/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
