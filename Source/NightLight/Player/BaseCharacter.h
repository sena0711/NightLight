// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class NIGHTLIGHT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Status. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float MaxHealth;
	/** is character alive use Get bisalive for update */
		bool bIsAlive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/*Checks health and sets bisalive and if alive passes true.*/
	UFUNCTION(BlueprintCallable, Category = "Status")
		bool GetbIsAlive();

	UFUNCTION(BlueprintCallable, Category = "Status")
		bool GainHealth(float GainValue);

	UFUNCTION(BlueprintCallable, Category = "Status")
		void ReduceHealth(float ReductionValue);


};
