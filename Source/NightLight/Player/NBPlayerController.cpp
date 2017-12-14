// Fill out your copyright notice in the Description page of Project Settings.

#include "NBPlayerController.h"
#include "Assets/BasePickupable.h"
#include "NBCharacter.h"


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

void ANBPlayerController::PossessInteractedItem(ABasePickupable * interactedItem)
{
	ANBCharacter* playerCharacter = Cast<ANBCharacter>(GetCharacter());
	EItemType eItemType = interactedItem->GetItemType();
	switch (eItemType)
	{
	case EItemType::Key:
		//add key numbers
		break;
	case EItemType::Health:
		//add health pack numbers
		break;
	case EItemType::Battery:
		//add battery numbers
		break;
	case EItemType::Bullets:
		//add bullet numbers
		break;
	case EItemType::Torch:
		//spawn torch
		if (playerCharacter)
		{
			playerCharacter->SpawnTorch();
		}
		break;
	case EItemType::Weapon:
		//spawn weapon
		break;
	case EItemType::Quest:

		break;
	case EItemType::Instruction:

		break;
	default:
		break;
	}
}



void ANBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &ANBPlayerController::Interact);
}
