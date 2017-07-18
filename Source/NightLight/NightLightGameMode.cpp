// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "NightLightGameMode.h"
#include "NightLightHUD.h"
#include "NightLightCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANightLightGameMode::ANightLightGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ANightLightHUD::StaticClass();
}
