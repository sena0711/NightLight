// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NB_BT_GetTargetPoint.generated.h"

/**
 * 
 */
UCLASS()
class NB_AIPLUGIN_API UNB_BT_GetTargetPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
