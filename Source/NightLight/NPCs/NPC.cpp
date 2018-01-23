// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC.h"
#include "GameFramework/CharacterMovementComponent.h"
ANPC::ANPC()
{

}
void ANPC::SetWalkSpeed(float desiredWalkSpeed)
{
	GetCharacterMovement()->MaxWalkSpeed = desiredWalkSpeed;
}