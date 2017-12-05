// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/BaseCharacter.h"
#include "NBCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ANBCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ANBCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
	/** Mouse sensitivity. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float MouseSensitivity;
	/** Rotate actor when forward button is pressed.. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		bool bRotateActor;
	/** Stops adding right mouse input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bStopRightMouseInput;
	/** Stops adding left mouse input */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bStopLeftMouseInput;
protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void AddMouseYawInput(float Value);
	void AddMousePitchInput(float Value);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	/************************************************************************/
	/* Pickups                                                              */
	/************************************************************************/

	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		void CheckForGrabalbeItem();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface


};
