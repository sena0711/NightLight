// Fill out your copyright notice in the Description page of Project Settings.
#include "../../Public/Behaivour/NB_BT_GetTargetPoint.h"
#include "NB_TargetPoint.h"
#include "Framework/NB_BaseAIController.h"
#include "Framework/NB_BaseNPCharacter.h"


EBTNodeResult::Type UNB_BT_GetTargetPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	ANB_BaseAIController* AIController = Cast<ANB_BaseAIController>(OwnerComp.GetAIOwner());
	ANB_BaseNPCharacter* AICharacter = Cast<ANB_BaseNPCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	//if characterisvalid
	//1. Get the Set patrol points in Character-> TArray<AMyTargetPoint*> PatrolTargetPoints
	if (AIController)
	{	
		UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComp();
		if (AICharacter->PatrolTargetPoints.Num() != 0)
		{
			if (ANB_TargetPoint* ATarGetPoint = Cast<ANB_TargetPoint>(AICharacter->PatrolTargetPoints[0]))
			{
				TArray<ANB_TargetPoint*> AvailableTargetPoints = AICharacter->PatrolTargetPoints;
				//2. Set First one to the way point going to the point will be handled in behaviour tree
				AIController->SetVectorKey(AIController->MoveToLocationKeyName, AvailableTargetPoints[0]->GetTargetLocation());
			}
			
		}
		return EBTNodeResult::Succeeded;
	}

	else
	{

		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}