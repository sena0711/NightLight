// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePickupable.h"
//#include "../Core/TypeClass.h"
//#include "../Assets/BaseWeapon.h"
#include "Player/NBPlayerController.h"





ABasePickupable::ABasePickupable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractText = "F :to Pickup";
	NameOfItem = "Item";
	NumberOfItems = 1;
	PickedUpValue = 50;
	QuestType = EQuestType::EDefault;
}

void ABasePickupable::Interact(class ANBPlayerController * playerController)
{
	playerController->PossessInteractedItem(this);
}

EItemType ABasePickupable::GetItemType()
{
	return ItemType;
}

EQuestType ABasePickupable::
GetQuestType()
{
	return QuestType;
}

TSubclassOf<class ABaseWeapon> ABasePickupable::GetWeaponToHold()
{
	return WeaponToHold;
}

float ABasePickupable::GetPickedUpValue()
{
	return PickedUpValue;
}

FName ABasePickupable::GetNameOfItem()
{
	switch (ItemType)
	{
	case EItemType::Key:
		NameOfItem = "Key";
		break;
	case EItemType::Health:
		NameOfItem = "Health";
		break;
	case EItemType::Battery:
		NameOfItem = "Battery";
		break;
	case EItemType::StandardBullets:
		NameOfItem = "StandardBullets";
		break;
	case EItemType::LightBullets:
		NameOfItem = "LightBullets";
		break;
	case EItemType::Torch:
		NameOfItem = "Torch";
		break;
	case EItemType::Weapon:
		NameOfItem = "Weapon";
		break;
	case EItemType::Quest:
		NameOfItem = "Quest";
		break;
	case EItemType::Instruction:
		NameOfItem = "Instruction";
		break;
	default:
		break;
	}
	return NameOfItem;
}
