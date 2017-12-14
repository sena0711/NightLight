// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePickupable.h"
#include "Player/NBPlayerController.h"





ABasePickupable::ABasePickupable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractText = "F:toPickup";

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
