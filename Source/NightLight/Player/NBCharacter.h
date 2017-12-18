// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/BaseCharacter.h"
#include "NBCharacter.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ELookingDirection : uint8
{
	LookingUp,

	NoChange,

	LookingDown,
};


UCLASS()
class ANBCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ANBCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
		class UPhysicsHandleComponent * PhysicsHandle;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		ELookingDirection LookingDirection;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraSensitivity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float DefaultCameraSensitivity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float HoldingCameraSensitivity;
	/** Max Interact Distance.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		float MaxInteractDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		float TurnValue;

	/** Rotate actor when forward button is pressed.. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		bool bRotateActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool HoldingObject;
	/** HitResult saved as public so bp can use it.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		FHitResult HitResultFromCameraCenter;
protected:
	/** Stops adding right mouse input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bStopRightMouseInput;
	/** Stops adding left mouse input */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bStopLeftMouseInput;

	/** Stops adding right mouse input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bStopUpMouseInput;
	/** Stops adding left mouse input */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bStopDownMouseInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		class ABaseWeapon *CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		class ABaseTorch *CurrentTorch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		TSubclassOf <class ABaseTorch> TorchClass;


	/************************************************************************/
	/* Anim use                                                           */
	/************************************************************************/

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* ReloadAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* EquipAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* FireAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* DrawingAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* PickingUpAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* PushingAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* NoClipAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		class UAnimMontage* EndCrankAnimation;
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

	/** HoldObject. */
	void HoldObject();
	/*ReleaseObject*/
	void ReleaseObject();

	/** HoldObject. */
	void HoldFire();
	/*ReleaseObject*/
	void ReleaseFire();
	/************************************************************************/
	/* Play Animation                                                        */
	/************************************************************************/

	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		void PlayAnimation(class UAnimMontage* montageToPlay);

	/************************************************************************/
	/* Pickups                                                              */
	/************************************************************************/
	
	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		void CheckForGrabableItem();

	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		FHitResult GetHitResultInView();

	UFUNCTION(BlueprintCallable, Category = "Calculation")
		void UpdateSlide(float Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Torch")
		void SpawnTorch();
	UFUNCTION(BlueprintCallable, Category = "Torch")
		void SpawnWeapon(TSubclassOf <class ABaseWeapon> WeaponClass);

	UFUNCTION(BlueprintImplementableEvent)
		void AttachTorchToGun();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface


};

