// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePickupable.h"
//#include "../Core/TypeClass.h"
//#include "../Assets/BaseWeapon.h"
#include "Player/NBPlayerController.h"





ABasePickupable::ABasePickupable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractText = "F:toPickup";
	NumberOfItems = 1;
}

void ABasePickupable::Interact(class ANBPlayerController * playerController)
{
	playerController->PossessInteractedItem(this);
	Destroy();
}

EItemType ABasePickupable::GetItemType()
{
	return ItemType;
}

TSubclassOf<class ABaseWeapon> ABasePickupable::GetWeaponToHold()
{
	return WeaponToHold;
}
