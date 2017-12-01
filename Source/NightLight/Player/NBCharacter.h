// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/BaseCharacter.h"
#include "NBCharacter.generated.h"



/**
 * 
 */
UCLASS(config = Game)
class NIGHTLIGHT_API  ANBCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
		class USkeletalMeshComponent* CharacterMesh;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	UCharacterMovementComponent* MoveComp;
	

public:
	// Sets default values for this character's properties
	ANBCharacter();


	/************************************************************************/
	/* Movement                                                        */
	/************************************************************************/
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		float WalkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		float SprintSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		bool bisFiring;

	/************************************************************************/
	/* Movement Animation                                                       */
	/************************************************************************/

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		bool JumpButtonDown;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		bool CrouchButtonDown;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		bool CanSprint;

protected:

	/************************************************************************/
	/* Basic Movement Functions                                                 */
	/************************************************************************/

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void OnJumpPressed();
	void OnJumpReleased();

	void OnCrouchPressed();
	void OnCrouchReleased();

	void OnSprintPressed();
	void OnSprintReleased();

	/************************************************************************/
	/* Advanced Movenemt functions                                                  */
	/************************************************************************/

	void FireWeapon();
	void PushAI();
	void StopFireWeapon();
	void ReloadWeapon();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface



};
