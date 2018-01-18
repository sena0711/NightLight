// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/BaseGrabable.h"
#include "BaseSwitch.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTLIGHT_API ABaseSwitch : public ABaseGrabable
{
	GENERATED_BODY()
	
protected:
	ABaseSwitch();
	


private:
	/*Switch*/
	UPROPERTY()
		bool bSwitchOnOFF;

public:
	UFUNCTION(BlueprintCallable, Category = "Switch")
	void ToggleSwitchOnOff();
	UFUNCTION(BlueprintCallable, Category = "Switch")
		bool GetSwitchOnOff();
	UFUNCTION(BlueprintCallable, Category = "Switch")
		void SetSwitchOnOff(bool bSwithchOnOff);
};
