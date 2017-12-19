// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsAlive = true;
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ABaseCharacter::GetbIsAlive()
{
	if (CurrentHealth > 0)
	{
		bIsAlive = true;
	}
	else
	{
		bIsAlive = false;
	}

	return bIsAlive;
}

bool ABaseCharacter::GainHealth(float GainValue)
{
	if (CurrentHealth < MaxHealth)
	{
		CurrentHealth = CurrentHealth + GainValue;
		return true;
	}
	else
	{
		return false;
	}
}

void ABaseCharacter::ReduceHealth(float ReductionValue)
{
}

