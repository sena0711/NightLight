// Fill out your copyright notice in the Description page of Project Settings.

#include "NBPlayerController.h"
#include "Assets/BasePickupable.h"




ANBPlayerController::ANBPlayerController()
{

}

void ANBPlayerController::Interact()
{
	if (CurrentPickupable)
	{
		CurrentPickupable->Interact(this);
	}
}

void ANBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &ANBPlayerController::Interact);
}
