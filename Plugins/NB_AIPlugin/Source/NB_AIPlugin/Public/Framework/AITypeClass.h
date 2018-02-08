

#pragma once

#include "NB_AIPlugin.h"
#include "Engine.h"
#include "ModuleManager.h"
#include "Internationalization.h"
#include "AITypeClass.generated.h"


UENUM()
enum class EAIBehaviorType : uint8
{
	Idle,
	// passive patrolling mode
	Neutral,
	//hearing or seeing someone. 
	Suspicious,
	//attacking mode
	Agression,
	//Runnning away from an AI.
	Flee,
	//Move towards an AI
	Following,

	Behavior01,

	Behavior02,

	Behavior03,
};

//class NB_AIPLUGIN_API AITypeClass
//{
//public:
//	AITypeClass();
//	~AITypeClass();
//};
