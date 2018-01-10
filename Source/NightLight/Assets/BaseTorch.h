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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Torch")
		class USpotLightComponent* TorchSpotlight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torch")
		class UStaticMeshComponent* TorchCollisionMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torch")
		class UStaticMeshComponent* TorchMesh;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Owning")
		class ANBCharacter* MyPawn;

	//Reduction of energy
	FTimerHandle StartReducingEnergyTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		float MaxEnergy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		float CurrentEnergy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		float EnergyReductionRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		float ReductionTimerRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
		bool IsTorchOn;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/************************************************************************/
	/* Overlap functions                                      */
	/************************************************************************/
	UFUNCTION()
		void OnOverlapEnableInLight(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlapDisableInLight(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "torch")
		void GetEnergy();

	UFUNCTION(BlueprintCallable, Category = "torch")
		void AddEnergy(int EnergyToAdd);

	UFUNCTION(BlueprintCallable, Category = "torch")
		void DrainEnergy();

	UFUNCTION(BlueprintCallable, Category = "torch")
		void SetVisiblity(bool bVisiblity);

	UFUNCTION(BlueprintCallable, Category = "torch")
		bool GetVisiblity();

	/* Set the Torch's owning pawn */
	void SetOwningPawn(class ANBCharacter* NewOwner);
	
};
