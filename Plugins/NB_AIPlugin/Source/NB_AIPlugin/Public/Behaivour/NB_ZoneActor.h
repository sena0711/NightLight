// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NB_ZoneActor.generated.h"

UCLASS()
class NB_AIPLUGIN_API ANB_ZoneActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANB_ZoneActor();

private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBoxComponent* ZoneComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//sets keys in the blackboard
	UFUNCTION(BlueprintCallable, Category = "BlackBoard")
		FVector GetRandomPointInVolume();

	FORCEINLINE UBoxComponent* GetZoneComponent() const { return ZoneComponent; }


};
