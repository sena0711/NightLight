// Fill out your copyright notice in the Description page of Project Settings.

#include "NBPlayerController.h"
#include "Assets/BasePickupable.h"
#include "Core/TypeClass.h"
#include "NBCharacter.h"
#include "TimerManager.h"


ANBPlayerController::ANBPlayerController()
{
	bSearchReturnedNull = true;
	bIsWarningOn = true;
	WarningText = "WriteWarningText";
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
	bool bIsHealthGained = false;

	switch (eItemType)
	{
	case EItemType::Key:
		//add key numbers
		AddItemToArray(eItemType, stackNumber);
		interactedItem->Destroy();
		break;
	case EItemType::Health:
		//gain health if succeeded the item will be destoryed otherwise nothing happens. 
		bIsHealthGained = playerCharacter->GainHealth(interactedItem->GetPickedUpValue());
		if (bIsHealthGained == true)
		{
			interactedItem->Destroy();
		}
		//AddItemToArray(eItemType, stackNumber);
		break;
	case EItemType::Battery:
		//add battery numbers
		AddItemToArray(eItemType, stackNumber);
		interactedItem->Destroy();
		break;
	case EItemType::StandardBullets:
		//add bullet numbers
		AddItemToArray(eItemType, stackNumber);
		interactedItem->Destroy();
		
		break;

	case EItemType::LightBullets:
		//add bullet numbers
		AddItemToArray(eItemType, stackNumber);
		interactedItem->Destroy();
		break;
	case EItemType::Torch:
		// assigns current torch and spawns torch
		if (playerCharacter)
		{
			playerCharacter->SpawnTorch();
		}
		interactedItem->Destroy();
		break;
	case EItemType::Weapon:
		//spawn weapon
		if (playerCharacter)
		{
			if (CurrentPickupable->GetWeaponToHold())
			{
				playerCharacter->SpawnWeapon(CurrentPickupable->GetWeaponToHold());
			}		
		}
		interactedItem->Destroy();
		break;
	case EItemType::Quest:
		
		break;
	case EItemType::Instruction:

		break;
	default:
		break;
	}
}
void ANBPlayerController::SetWarningText(FName fWarningText, float flength = 1.0)
{
	bIsWarningOn = true;
	WarningText = fWarningText;

	GetWorldTimerManager().SetTimer(ShowWarningOnScreenTimerHandle, this, &ANBPlayerController::UnSetWarningText, flength, false);
}
void ANBPlayerController::UnSetWarningText()
{
	GetWorldTimerManager().ClearTimer(ShowWarningOnScreenTimerHandle);

	bIsWarningOn = false;
}
bool ANBPlayerController::GetbIsWarningOn()
{
	return bIsWarningOn;
}
FName ANBPlayerController::GetWarningText()
{
	return WarningText;
}
void ANBPlayerController::BeginPlay()
{
	InitializeBulletItems();
	InitializeBulletItemsUIimages();
}
void ANBPlayerController::AddItemToArray(EItemType eItemType, int32 addingStacks)
{
	//initialize item to add.
	int32 index = 0;
	FInventoryItem itemToAdd;
	itemToAdd.ItemType = eItemType;
	itemToAdd.CurrentStackNumber = addingStacks;
	itemToAdd.indexNumber = 0;

	//if the array is empty add new item
	if (InventoryItems.Num() == 0)
	{
		index = InventoryItems.Add(itemToAdd);
	}
	//if array is not empty
	else
	{
		// search the array get index 
		index = SearchInventoryItemsByType(eItemType);
		if (index == NOTEXISTING)
		{
			index = InventoryItems.Add(itemToAdd);
		}
		else
		{
			int32 stackNumber = InventoryItems[index].CurrentStackNumber;
			InventoryItems[index].CurrentStackNumber = stackNumber + addingStacks;
		}
		
		
	}
	//set index number. 
	InventoryItems[index].indexNumber = index;
}
void ANBPlayerController::InitializeBulletItems()
{
	FBulletItem InitBulletItem;

	for (int32 b = 0; b < EXISTINGBULLETTYPES; b++)
	{
		InitBulletItem.CurrentPossesed = 0;
		InitBulletItem.BulletType = (EBulletType)b;
		BulletItems.Add(InitBulletItem);
	}
}

void ANBPlayerController::SetBullets(EItemType eItemType, int32 addingStacks)
{
	int32 bulletIndex;
	int32 index; 
	if ((eItemType == EItemType::StandardBullets) || (eItemType == EItemType::LightBullets))
	{
		index = SearchInventoryItemsByType(eItemType);
		if (index != NOTEXISTING)
		{		
			bulletIndex = SearchBulletItemsByType(GetBulletTypesFromItemType(eItemType));
			if (bulletIndex != NOTEXISTING)
			{
				//set bullet items
				BulletItems[bulletIndex].CurrentPossesed = InventoryItems[index].CurrentStackNumber;
			}
		}
	}


}


int32 ANBPlayerController::SearchInventoryItemsByType(EItemType eItemType)
{
	bSearchReturnedNull = true;
	int32 index = NOTEXISTING;
	//search and return the index of searched array if not found it will return null
	for (int32 b = 0; b < InventoryItems.Num(); b++)
	{
		if (InventoryItems[b].ItemType == eItemType)
		{
			index = b;
			bSearchReturnedNull = false;
			break;
		}
	}

	return index;
}

int32 ANBPlayerController::SearchBulletItemsByType(EBulletType eItemType)
{	
	int32 index = NOTEXISTING;
	//search and return the index of searched array if not found it will return null
	for (int32 b = 0; b < InventoryItems.Num(); b++)
	{
		if (BulletItems[b].BulletType == eItemType)
		{
			index = b;
			break;
		}
	}
	return index;
}

EBulletType ANBPlayerController::GetBulletTypesFromItemType(EItemType eItemType)
{
	EBulletType matchingBullet;
	matchingBullet = EBulletType::EStandard;
	switch (eItemType)
	{
	case EItemType::StandardBullets:
		matchingBullet = EBulletType::EStandard;
		break;
	case EItemType::LightBullets:
		matchingBullet = EBulletType::ELight;
		break;
	default:
		break;
	}
	return matchingBullet;
}

void ANBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("PickUp", IE_Pressed, this, &ANBPlayerController::Interact);
}

