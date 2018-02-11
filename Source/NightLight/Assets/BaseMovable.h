// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseMovable.generated.h"

UCLASS()
class NIGHTLIGHT_API ABaseMovable : public AActor
{
	GENERATED_BODY()
protected:
	// Sets default values for this actor's properties
	ABaseMovable();

public:	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colllision")
	//	class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colllision")
		class UStaticMeshComponent* PickupMesh;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colllision")
		class USoundBase* SoundHit;
	
	//vectorlength/ volumeMultiplierValue
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float volumeMultiplierValue;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
	void WhenHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UFUNCTION(BlueprintCallable, Category = "PickupCondition")
		virtual FVector GetLocationOfMesh();

};
