// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "NBHUD.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EHUDState : uint8
{
	Playing,
	Spectating,
	MatchEnd
};

UCLASS()
class NIGHTLIGHT_API ANBHUD : public AHUD
{
	GENERATED_BODY()

public:
	ANBHUD();

	/* Current HUD state */
	EHUDState CurrentState;

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** On crosshair indicator that we hit someone. */
	UPROPERTY()
		FCanvasIcon CrosshairIcon;
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	void DrawCrossHair();

};
