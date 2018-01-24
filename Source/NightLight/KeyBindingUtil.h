// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Classes/InputCoreTypes.h"
#include "GameFramework/PlayerInput.h"
#include "Input/Events.h"
#include "UObject/UObjectGlobals.h"
#include "KeyBindingUtil.generated.h"


USTRUCT(BlueprintType)
struct FInputAction
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		FString ActionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		FKey Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		FString KeyAsString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		uint32 bShift : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		uint32 bCtrl : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		uint32 bAlt : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		uint32 bCmd : 1;

	FInputAction() {}
	FInputAction(const FString InActionName, const FKey InKey, const bool bInShift, const bool bInCtrl, const bool bInAlt, const bool bInCmd)
		: Key(InKey)
		, KeyAsString(Key.GetDisplayName().ToString())
		, bShift(bInShift)
		, bCtrl(bInCtrl)
		, bAlt(bInAlt)
		, bCmd(bInCmd)
	{
		ActionName = InActionName;
	}

	FInputAction(const FInputActionKeyMapping& Action)
		: Key(Action.Key)
		, KeyAsString(Key.GetDisplayName().ToString())
		, bShift(Action.bShift)
		, bCtrl(Action.bCtrl)
		, bAlt(Action.bAlt)
		, bCmd(Action.bCmd)
	{
		ActionName = Action.ActionName.ToString();
	}
};

USTRUCT(BlueprintType)
struct FInputAxis
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		FString AxisName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		FString KeyAsString = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		FKey Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Bindings")
		float Scale = 1;

	FInputAxis() {}
	FInputAxis(const FString InAxisName, FKey InKey, float InScale)
		: AxisName(InAxisName)
		, KeyAsString(InKey.GetDisplayName().ToString())
		, Key(InKey)
		, Scale(InScale)
	{

	}

	FInputAxis(const FInputAxisKeyMapping& Axis)
		: Key(Axis.Key)
		, KeyAsString(Axis.Key.GetDisplayName().ToString())
		, Scale(Axis.Scale)
	{
		AxisName = Axis.AxisName.ToString();
	}
};

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API UKeyBindingUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UKeyBindingUtil(const FObjectInitializer& ObjectInitilializer);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static FInputAxis GetInputAxisFromMouseButtonEvent(const FPointerEvent& MouseEvent);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static FInputAxis GetInputAxisFromMouseAxisEvent(const FPointerEvent& MouseEvent);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static FInputAction GetInputActionFromMouseButtonEvent(const FPointerEvent& MouseEvent);
	
	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static FInputAxis GetInputAxisFromKeyEvent(const FKeyEvent& KeyEvent);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static FInputAction GetInputActionFromKeyEvent(const FKeyEvent& KeyEvent);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static void GetAllBindedInputActions(TArray<FInputAction>& Actions);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static void GetAllBindedInputAxis(TArray<FInputAxis>& InputAxis);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static bool RebindAxisKey(FInputAxis CurrentBinding, FInputAxis NewBinding);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static bool RebindActionKey(FInputAction CurrentBinding, FInputAction NewBinding);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static bool AddActionBinding(FInputAction NewBinding, FInputAction CurrentBinding);

	UFUNCTION(BlueprintPure, Category = "Key Bindings")
		static bool AddAxisBinding(FInputAxis NewBinding, FInputAxis CurrentBinding);


private:
	static void UpdateAxisBinding(const FInputAxis& SrcInputAxis, FInputAxisKeyMapping& DstInputAxis);
	static void UpdateActionBinding(const FInputAction& SrcInputAction, FInputActionKeyMapping& DstInputAction);
};
