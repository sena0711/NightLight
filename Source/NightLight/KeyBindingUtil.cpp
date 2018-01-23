// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyBindingUtil.h"
#include "NightLight.h"
#include "GameFramework/InputSettings.h"
#include "UObject/UObjectGlobals.h"

UKeyBindingUtil::UKeyBindingUtil(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UKeyBindingUtil::UpdateAxisBinding(const FInputAxis& SrcInputAxis, FInputAxisKeyMapping& DstInputAxis)
{
	DstInputAxis.Key = SrcInputAxis.Key;
	DstInputAxis.Scale = SrcInputAxis.Scale;
}

void UKeyBindingUtil::UpdateActionBinding(const FInputAction& SrcInputAction, FInputActionKeyMapping& DstInputAction)
{
	DstInputAction.Key = SrcInputAction.Key;
	DstInputAction.bShift = SrcInputAction.bShift;
	DstInputAction.bCtrl = SrcInputAction.bCtrl;
	DstInputAction.bAlt = SrcInputAction.bAlt;
	DstInputAction.bCmd = SrcInputAction.bCmd;
}

FInputAxis UKeyBindingUtil::GetInputAxisFromMouseButtonEvent(const FPointerEvent& MouseEvent)
{
	FInputAxis InputAxis;

	InputAxis.Key = MouseEvent.GetEffectingButton();
	InputAxis.KeyAsString = InputAxis.Key.GetDisplayName().ToString();

	InputAxis.Scale = 1;

	return InputAxis;
}

FInputAxis UKeyBindingUtil::GetInputAxisFromMouseAxisEvent(const FPointerEvent & MouseEvent)
{
	FInputAxis InputAxis;

	float CurrentHorizontalDistance = FMath::Abs(MouseEvent.GetCursorDelta().X);
	float CurrentVerticalDistance = FMath::Abs(MouseEvent.GetCursorDelta().Y);

	if (CurrentHorizontalDistance > CurrentVerticalDistance)
	{
		InputAxis.Key = FKey(FName("MouseX"));
		InputAxis.Scale = MouseEvent.GetCursorDelta().X >= 0.0f ? 1 : -1;
	}
	else
	{
		InputAxis.Key = FKey(FName("MouseY"));
		InputAxis.Scale = MouseEvent.GetCursorDelta().Y >= 0.0f ? 1 : -1;
	}
	InputAxis.KeyAsString = InputAxis.Key.GetDisplayName().ToString();

	return InputAxis;
}

FInputAction UKeyBindingUtil::GetInputActionFromMouseButtonEvent(const FPointerEvent& MouseEvent)
{
	FInputAction InputAction;

	InputAction.Key = MouseEvent.GetEffectingButton();
	InputAction.KeyAsString = InputAction.Key.GetDisplayName().ToString();

	InputAction.bAlt = MouseEvent.IsAltDown();
	InputAction.bCtrl = MouseEvent.IsControlDown();
	InputAction.bShift = MouseEvent.IsShiftDown();
	InputAction.bCmd = MouseEvent.IsCommandDown();

	return InputAction;
}

FInputAxis UKeyBindingUtil::GetInputAxisFromKeyEvent(const FKeyEvent& KeyEvent)
{
	FInputAxis InputAxis;

	InputAxis.Key = KeyEvent.GetKey();
	InputAxis.KeyAsString = InputAxis.Key.GetDisplayName().ToString();

	InputAxis.Scale = 1;

	return InputAxis;
}

FInputAction UKeyBindingUtil::GetInputActionFromKeyEvent(const FKeyEvent& KeyEvent)
{
	FInputAction InputAction;

	InputAction.Key = KeyEvent.GetKey();
	InputAction.KeyAsString = InputAction.Key.GetDisplayName().ToString();

	InputAction.bAlt = KeyEvent.IsAltDown();
	InputAction.bCmd = KeyEvent.IsCommandDown();
	InputAction.bCtrl = KeyEvent.IsControlDown();
	InputAction.bShift = KeyEvent.IsShiftDown();

	return InputAction;
}

void UKeyBindingUtil::GetAllBindedInputActions(TArray<FInputAction>& InputActions)
{
	InputActions.Empty();

	const UInputSettings* Settings = GetDefault<UInputSettings>();

	if (!Settings)
	{
		return;
	}

	const TArray<FInputActionKeyMapping>& Actions = Settings->ActionMappings;

	for (const FInputActionKeyMapping& Each : Actions)
	{
		InputActions.Add(FInputAction(Each));
	}
}

void UKeyBindingUtil::GetAllBindedInputAxis(TArray<FInputAxis>& InputAxis)
{
	InputAxis.Empty();

	const UInputSettings* Settings = GetDefault<UInputSettings>();

	if (!Settings)
	{
		return;
	}

	const TArray<FInputAxisKeyMapping>& Axis = Settings->AxisMappings;

	for (const FInputAxisKeyMapping& Each : Axis)
	{
		InputAxis.Add(FInputAxis(Each));
	}
}

bool UKeyBindingUtil::RebindAxisKey(FInputAxis CurrentBinding, FInputAxis NewBinding)
{
	UInputSettings* Settings = const_cast<UInputSettings*>(GetDefault<UInputSettings>());

	if (!Settings)
	{
		return false;
	}

	TArray<FInputAxisKeyMapping>& Axis = Settings->AxisMappings;

	bool Found = false;
	for (FInputAxisKeyMapping& Each : Axis)
	{
		// Search by CurrentBinding
		if (Each.AxisName.ToString() == CurrentBinding.AxisName && Each.Key == CurrentBinding.Key)
		{
			UKeyBindingUtil::UpdateAxisBinding(NewBinding, Each);
			Found = true;
			break;
		}
	}

	if (Found)
	{
		// Saves to disk
		const_cast<UInputSettings*>(Settings)->SaveKeyMappings();

		//Rebuilds input, creates a modified input.ini file
		for (TObjectIterator<UPlayerInput> It; It; ++It)
		{
			It->ForceRebuildingKeyMaps(true);
		}
	}

	return Found;
}

bool UKeyBindingUtil::RebindActionKey(FInputAction CurrentBinding, FInputAction NewBinding)
{
	UInputSettings* Settings = const_cast<UInputSettings*>(GetDefault<UInputSettings>());

	if (!Settings)
	{
		return false;
	}

	TArray<FInputActionKeyMapping>& Actions = Settings->ActionMappings;

	bool Found = false;
	for (FInputActionKeyMapping& Each : Actions)
	{
		if (Each.ActionName.ToString() == CurrentBinding.ActionName && Each.Key == CurrentBinding.Key)
		{
			UKeyBindingUtil::UpdateActionBinding(NewBinding, Each);
			Found = true;
			break;
		}
	}

	if (Found)
	{
		const_cast<UInputSettings*>(Settings)->SaveKeyMappings();

		for (TObjectIterator<UPlayerInput> It; It; ++It)
		{
			It->ForceRebuildingKeyMaps(true);
		}
	}
	return Found;
}

