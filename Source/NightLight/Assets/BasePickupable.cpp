// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePickupable.h"




ABasePickupable::ABasePickupable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractText = "F:toPickup";

}

void ABasePickupable::Interact(APlayerController * playerController)
{
	switch (ItemType)
	{
	case EItemType::Key:
		//add key to inventory
		break;
	case EItemType::Health:
		// add health to inventory
		break;
	case EItemType::Battery:
		// add battery to inventory
		break;
	case EItemType::Bullets:
		// add bullets to held guns. 
		break;
	case EItemType::Torch:
		// Spawn torch in hand. 
		break;
	case EItemType::Weapon:
		// spawn weapon in hand
		break;
	case EItemType::Quest:
		// add quest item to ui. 
		break;
	default:
		break;
	}

	Destroy();
}
