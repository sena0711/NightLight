// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseSwitch.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"




ABaseSwitch::ABaseSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupMesh->SetSimulatePhysics(false);

	bSwitchOnOFF = true;
}

bool ABaseSwitch::GetSwitchOnOff()
{
	return bSwitchOnOFF;
}

void ABaseSwitch::SetSwitchOnOff(bool bSwithchOnOff)
{
	bSwitchOnOFF = bSwithchOnOff;
}

void ABaseSwitch::ToggleSwitchOnOff()
{
	
	/*if it is true becomes false...false to true*/
	bSwitchOnOFF = !bSwitchOnOFF;
}
