// Fill out your copyright notice in the Description page of Project Settings.

#include "NB_BaseCharacter.h"
//#include "..\..\Public\Framework\NB_BaseCharacter.h"


// Sets default values
ANB_BaseCharacter::ANB_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsAlive = true;
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

// Called when the game starts or when spawned
void ANB_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANB_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ANB_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ANB_BaseCharacter::GetbIsAlive()
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

bool ANB_BaseCharacter::GainHealth(float GainValue)
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

void ANB_BaseCharacter::ReduceHealth(float ReductionValue)
{
	if (GetbIsAlive() == true)
	{
		CurrentHealth = CurrentHealth - ReductionValue;
	}
	if (CurrentHealth < 0.0)
	{
		CurrentHealth = 0.0;
	}
}

bool ANB_BaseCharacter::GainStamina(float GainValue)
{
	if (CurrentStamina < MaxStamina)
	{
		CurrentStamina = CurrentStamina + GainValue;
		return true;
	}
	else
	{
		return false;
	}
}

void ANB_BaseCharacter::ReduceStamina(float ReductionValue)
{
	if (GetbIsAlive() == true)
	{
		if (CurrentStamina > 0.0)
		{
			CurrentStamina = CurrentStamina - ReductionValue;
			if (CurrentStamina < 0.0)
			{
				CurrentStamina = 0.0;
			}
		}
		else
		{
			CurrentStamina = 0.0f;
		}
	}
}

