// Fill out your copyright notice in the Description page of Project Settings.

#include "NBCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "../Assets/BaseGrabable.h"
#include "../Assets/BasePickupable.h"
#include "../Assets/BaseTorch.h"
#include "NBPlayerController.h"

//////////////////////////////////////////////////////////////////////////
// ANBCharacter

ANBCharacter::ANBCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//	bUseControllerRotationYaw

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	CameraSensitivity = 0.5f;
	DefaultCameraSensitivity = CameraSensitivity;
	MaxInteractDistance = 300.0f;
	HoldingCameraSensitivity = CameraSensitivity*0.5;
	TurnValue = 1.0f;
	HoldingObject = false;
	LookingDirection = ELookingDirection::NoChange;


	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bRotateActor = false;
	bStopRightMouseInput = false;
	bStopLeftMouseInput = false;
	bStopUpMouseInput = false;
	bStopDownMouseInput = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandler"));
}


void ANBCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CheckForGrabableItem();
}


//////////////////////////////////////////////////////////////////////////
// Input

void ANBCharacter::CheckForGrabableItem()
{

	ANBPlayerController* playerController = Cast<ANBPlayerController>(GetController());
	if (playerController)
	{

		FHitResult Hit = GetHitResultInView();
		HitResultFromCameraCenter = Hit;
		//// trun off the current grabable
		if (playerController->CurrentGrabable != nullptr)
		{
			if (playerController->CurrentGrabable != Cast<ABaseGrabable>(Hit.GetActor()))
			{
				playerController->CurrentGrabable->NotInFocus();
			}
		}
	
		if (ABasePickupable* pickupable = Cast<ABasePickupable>(Hit.GetActor()))
		{
			if (HoldingObject == false)
			{
				playerController->CurrentPickupable = pickupable;
			}
		
			
			//playerController->CurrentGrabable = Cast<ABaseGrabable>(pickupable);
		}
		if (ABaseGrabable* grabable = Cast<ABaseGrabable>(Hit.GetActor()))
		{
			if (HoldingObject == false)
			{
				playerController->CurrentGrabable = grabable;
			}
			playerController->CurrentGrabable->InFocus();


			return;
		}
		// If we didn't hit anything, or thing we hit was on to a interactable set current interactable nullptr. 
		else
		{
			if (playerController->CurrentGrabable != nullptr)
			{
				playerController->CurrentGrabable->NotInFocus();
			}
			if (HoldingObject == false)
			{
				playerController->CurrentPickupable = nullptr;
				playerController->CurrentGrabable = nullptr;
			}
		}
	}

}

FHitResult ANBCharacter::GetHitResultInView()
{
	FVector CamLoc;
	FRotator CamRot;
	FHitResult Hit(ForceInit);

	if (Controller != nullptr)
	{
		Controller->GetPlayerViewPoint(CamLoc, CamRot);
		const FVector TraceStart = CamLoc;
		const FVector Direction = CamRot.Vector();
		const FVector TraceEnd = TraceStart + (Direction * MaxInteractDistance);

		FCollisionQueryParams TraceParams(TEXT("TraceUsableActor"), true, this);
		TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = false;

		/* Not tracing complex uses the rough collision instead making tiny objects easier to select. */
		TraceParams.bTraceComplex = false;


		GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, TraceParams);

	}

	return Hit;
}

void ANBCharacter::UpdateSlide(float Value)
{
	FVector CamLoc;
	FRotator CamRot;
	FVector PhysicsHandleLocation;
	FRotator PhysicsHandleRotation;

	if (Controller != nullptr)
	{
		Controller->GetPlayerViewPoint(CamLoc, CamRot);
		const FVector TraceStart = CamLoc;
		const FVector Direction = CamRot.Vector();

		PhysicsHandle->GetTargetLocationAndRotation(PhysicsHandleLocation, PhysicsHandleRotation);
		PhysicsHandle->SetTargetLocation((Direction * (Value* -1.0f)) + PhysicsHandleLocation);
	}
}

void ANBCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ANBCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANBCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &ANBCharacter::AddMouseYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ANBCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &ANBCharacter::AddMousePitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ANBCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ANBCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ANBCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ANBCharacter::OnResetVR);

	// Essential GamePlay functionality
	PlayerInputComponent->BindAction("HoldObject", IE_Pressed, this, &ANBCharacter::HoldObject);
	PlayerInputComponent->BindAction("HoldObject", IE_Released, this, &ANBCharacter::ReleaseObject);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ANBCharacter::HoldFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ANBCharacter::ReleaseFire);

}
void ANBCharacter::SpawnTorch()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = Instigator;
	// if current weapon is empty assign current weapon
	if (TorchClass != nullptr)
	{
		if (CurrentTorch == nullptr)
		{
			CurrentTorch = GetWorld()->SpawnActor<ABaseTorch>(TorchClass, SpawnParams);
			AttachTorchToGun();
			CurrentTorch->SetOwningPawn(this);
		}
	}
	else
	{
		//Torch class in player character bp needs to be set. 
	}
}
void ANBCharacter::SpawnWeapon(TSubclassOf <class ABaseWeapon> WeaponClass)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = Instigator;
	// if current weapon is empty assign current weapon
	if (CurrentWeapon == nullptr)
	{
		CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass, SpawnParams);
		AttachTorchToGun();
		CurrentWeapon->SetOwningPawn(this);
	}


}
void ANBCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ANBCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ANBCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ANBCharacter::HoldObject()
{
//	CameraSensitivity = HoldingCameraSensitivity;

	ANBPlayerController* playerController = Cast<ANBPlayerController>(GetController());
	if (playerController)
	{
		if (playerController->CurrentGrabable != nullptr)
		{
			HoldingObject = true;
			playerController->CurrentGrabable->WhenGrabbed();
			ABaseGrabable* GrabbingMesh = playerController->CurrentGrabable;
			PhysicsHandle->GrabComponentAtLocation(Cast<UPrimitiveComponent>(GrabbingMesh->PickupMesh), "", GrabbingMesh->GetLocationOfMesh());
		}
	}
}

void ANBCharacter::ReleaseObject()
{
	CameraSensitivity = DefaultCameraSensitivity;
	PhysicsHandle->ReleaseComponent();
	HoldingObject = false;
}

void ANBCharacter::HoldFire()
{

}

void ANBCharacter::ReleaseFire()
{
}

void ANBCharacter::PlayAnimation(UAnimMontage * montageToPlay)
{
	if (montageToPlay)
	{
		PlayAnimMontage(montageToPlay);
	}
}


void ANBCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ANBCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ANBCharacter::AddMouseYawInput(float Value)
{
	TurnValue = Value * CameraSensitivity;
	if (TurnValue != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		//moving right
		if (TurnValue > 0.0)
		{
			if (bStopRightMouseInput)
			{

			}
			else
			{
				PC->AddYawInput(TurnValue);
			}

		}
		//moving left
		else
		{
			if (bStopLeftMouseInput)
			{

			}
			else
			{
				PC->AddYawInput(TurnValue);
			}
		}
	}
}

void ANBCharacter::AddMousePitchInput(float Value)
{
	if (Value == 0.0)
	{
		LookingDirection = ELookingDirection::NoChange;
	}
	else if (Value > 0.0)
	{
		LookingDirection = ELookingDirection::LookingDown;
	}
	else if (Value < 0.0)
	{
		LookingDirection = ELookingDirection::LookingUp;
	}
	
	float TurnValue = Value * CameraSensitivity;
	if (TurnValue != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		//Looking Down
		if (TurnValue > 0.0)
		{
			if (bStopDownMouseInput)
			{

			}
			else
			{
				PC->AddPitchInput(TurnValue);
			}

		}
		//Looking Up
		else
		{
			if (bStopUpMouseInput)
			{

			}
			else
			{
				PC->AddPitchInput(TurnValue);
			}
		}
	}
}

void ANBCharacter::MoveForward(float Value)
{
	if (Controller != NULL)
	{
		if (Value != 0.0f)
		{
			// find out which way is forward
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Value);
			bRotateActor = true;
		}

		else
		{
			bRotateActor = false;
		}
	}
}

void ANBCharacter::MoveRight(float Value)
{
	if (Controller != NULL)
	{
		if (Value != 0.0f)
		{
			//bUseControllerRotationYaw = false;
			// find out which way is right
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			// add movement in that direction
			AddMovementInput(Direction, Value);
			
		}

	}

}
