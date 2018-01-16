
#include "NBHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "../Player/NBPlayerController.h"
#include "../Player/NBCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "CanvasItem.h"
#include "Engine/Texture2D.h"

ANBHUD::ANBHUD()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/UI/HUD/HUDMain"));
	CrosshairTex = CrosshiarTexObj.Object;

	//CrosshairIcon = UCanvas::MakeIcon(CrosshairTex, 3798, 231, 1013, 1007);
	//CrosshairIcon = UCanvas::MakeIcon(CrosshairTex, 1579, 107, 1320, 1239);
	CrosshairIcon = UCanvas::MakeIcon(CrosshairTex, 771, 690, 81, 89);
}

void ANBHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawCrossHair();
}

void ANBHUD::DrawCrossHair()
{
	/*Variables to get center postion*/
	FVector OutStartTrace = FVector::ZeroVector;
	FRotator DummyRot;
	// Draw very simple crosshair

	//get controller to check player
	ANBPlayerController* PCOwner = Cast<ANBPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PCOwner)
	{
		ANBCharacter* Pawn = Cast<ANBCharacter>(PCOwner->GetPawn());
		//if player is alive shows cursor
		if (Pawn && Pawn->GetbIsAlive())
		{
			PCOwner->GetPlayerViewPoint(OutStartTrace, DummyRot);
		}
	}
	float CenterX = Canvas->ClipX / 2;
	float CenterY = Canvas->ClipY / 2;
	float ScaleUI = Canvas->ClipY / 1080.0f;
	float MinHudScale = 0.2;
	ScaleUI = ScaleUI*MinHudScale;

	//Draw Icon

	Canvas->SetDrawColor(255, 255, 255, 150);

	Canvas->DrawIcon(CrosshairIcon,
		CenterX - CrosshairIcon.UL*ScaleUI / 2.0f,
		CenterY - CrosshairIcon.VL*ScaleUI / 2.0f, ScaleUI);
}
