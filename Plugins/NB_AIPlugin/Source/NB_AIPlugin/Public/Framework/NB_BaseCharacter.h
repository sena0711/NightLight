// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NB_BaseCharacter.generated.h"

UCLASS()
class NB_AIPLUGIN_API ANB_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANB_BaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Status. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float MaxHealth;

	/** Status. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float CurrentStamina;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float MaxStamina;
private:
	/** is character alive use Get bisalive for update */
	bool bIsAlive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Status")
		bool GetbIsAlive();

	UFUNCTION(BlueprintCallable, Category = "Status")
		bool GainHealth(float GainValue);

	UFUNCTION(BlueprintCallable, Category = "Status")
		void ReduceHealth(float ReductionValue);

	UFUNCTION(BlueprintCallable, Category = "Status")
		bool GainStamina(float GainValue);

	UFUNCTION(BlueprintCallable, Category = "Status")
		void ReduceStamina(float ReductionValue);
};
