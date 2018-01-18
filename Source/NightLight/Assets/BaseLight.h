// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSwitch.h"
#include "BaseLight.generated.h"


UCLASS()
class NIGHTLIGHT_API ABaseLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLight();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UStaticMeshComponent* LightSourceMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UStaticMeshComponent* LightVolumeCollision;
private :

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/************************************************************************/
	/* Overlap functions                                      */
	/************************************************************************/
	UFUNCTION()
		void OnOverlapEnableInLight(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlapDisableInLight(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	/************************************************************************/
	/* LightRelated                           */
	/************************************************************************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interact)
		bool bLightOnOFF;

	UFUNCTION(BlueprintCallable, Category = "Switch")
		bool GetLightOnOff();
	UFUNCTION(BlueprintCallable, Category = "Switch")
		void SetbLightOnOFF(bool bOnOFF);
	UFUNCTION(BlueprintCallable, Category = "Switch")
		bool ProcessLight(bool bOnOFF);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		class ABaseSwitch *ConnectedSwitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float CurrentBattery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float MaxBattery;



public:	


	UFUNCTION(BlueprintImplementableEvent)
		void WhenInLight();
	UFUNCTION(BlueprintImplementableEvent)
		void WhenNotInLight();
	
};
