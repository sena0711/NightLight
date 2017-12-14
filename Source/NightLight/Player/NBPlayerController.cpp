// Fill out your copyright notice in the Description page of Project Settings.

#include "NBPlayerController.h"
#include "Assets/BasePickupable.h"
#include "Core/TypeClass.h"
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
	int32 stackNumber = interactedItem->NumberOfItems;

	switch (eItemType)
	{
	case EItemType::Key:
		//add key numbers
		AddItemToArray(eItemType, stackNumber);
		break;
	case EItemType::Health:
		//add health pack numbers
		AddItemToArray(eItemType, stackNumber);
		break;
	case EItemType::Battery:
		//add battery numbers
		AddItemToArray(eItemType, stackNumber);
		break;
	case EItemType::Bullets:
		//add bullet numbers
		break;
	case EItemType::Torch:
		// assigns current torch and spawns torch
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
void ANBPlayerController::AddItemToArray(EItemType eItemType, int32 addingStacks)
{
	//initialize item to add.
	int32 index;
	FInventoryItem itemToAdd;
	itemToAdd.ItemType = eItemType;
	itemToAdd.CurrentStackNumber = addingStacks;
	itemToAdd.indexNumber = 0;

	//if the array is empty add new item
	if (InventoryItems.Num() == 0)
	{
		index = InventoryItems.Add(itemToAdd);
	}
	//if array is not empty search the array get index and incurse stack number
	else
	{
		index = SearchInventoryItemsByType(eItemType);
		int32 stackNumber = InventoryItems[index].CurrentStackNumber;
		InventoryItems[index].CurrentStackNumber = stackNumber + addingStacks;
	}
	//set index number. 
	InventoryItems[index].indexNumber = index;
}

int32 ANBPlayerController::SearchInventoryItemsByType(EItemType eItemType)
{
	int32 index = NULL;
	//search
	for (int32 b = 0; b < InventoryItems.Num(); b++)
	{
		if (InventoryItems[b].ItemType == eItemType)
		{
			index = b;
			break;
		}
	}

	return index;
}

void ANBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &ANBPlayerController::Interact);
}

