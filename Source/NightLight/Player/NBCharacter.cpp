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
	MouseSensitivity = 0.1f;
	MaxInteractDistance = 500.0f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bRotateActor = false;
	bStopRightMouseInput = false;
	bStopLeftMouseInput = false;

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
	

		if (ABasePickupable* pickupable = Cast<ABasePickupable>(Hit.GetActor()))
		{
			playerController->CurrentPickupable = pickupable;
		//	playerController->CurrentGrabable = Cast<ABaseGrabable>(pickupable);
		}
		if (ABaseGrabable* grabable = Cast<ABaseGrabable>(Hit.GetActor()))
		{
			playerController->CurrentGrabable = grabable;
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
			playerController->CurrentPickupable = nullptr;
			playerController->CurrentGrabable = nullptr;
			return;
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

	InputComponent->BindAction("HoldObject", IE_Pressed, this, &ANBCharacter::HoldObject);
	InputComponent->BindAction("HoldObject", IE_Released, this, &ANBCharacter::ReleaseObject);

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

	ANBPlayerController* playerController = Cast<ANBPlayerController>(GetController());
	if (playerController)
	{
		if (playerController->CurrentGrabable != nullptr)
		{
			ABaseGrabable* GrabbingMesh = playerController->CurrentGrabable;
			PhysicsHandle->GrabComponentAtLocation(Cast<UPrimitiveComponent>(GrabbingMesh->PickupMesh), "", GrabbingMesh->GetActorLocation());
			
		}
	}



}

void ANBCharacter::ReleaseObject()
{
	PhysicsHandle->ReleaseComponent();
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
	float TurnValue = Value * MouseSensitivity;
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
	float TurnValue = Value * MouseSensitivity;
	if (TurnValue != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		PC->AddPitchInput(TurnValue);
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
		else
		{
			//	bUseControllerRotationYaw = true;
		}
	}

}
