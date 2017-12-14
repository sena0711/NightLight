// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTorch.generated.h"

UCLASS()
class NIGHTLIGHT_API ABaseTorch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTorch();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Config")
		class USpotLightComponent* TorchSpotlight;



protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Owning")
		class ANBCharacter* MyPawn;

	//Reduction of energy
	FTimerHandle StartReducingEnergyTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		float MaxEnergy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		float CurrentEnergy;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "torch")
		void GetEnergy();

	UFUNCTION(BlueprintCallable, Category = "torch")
		void AddEnergy(int EnergyToAdd);

	UFUNCTION(BlueprintCallable, Category = "torch")
		void DrainEnergy(float EnergyToAdd);

	/* Set the Torch's owning pawn */
	void SetOwningPawn(class ANBCharacter* NewOwner);
	
};
