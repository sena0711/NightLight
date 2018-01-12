// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#define WEAPON_TRACE				ECC_GameTraceChannel1

/** when you modify this, please note that this information can be saved with instances
* also DefaultEngine.ini [/Script/Engine.PhysicsSettings] should match with this list **/
#define SURFACE_DEFAULT				SurfaceType_Default
#define SURFACE_FLESH				SurfaceType1
#define SURFACE_ENEMYBODY			SurfaceType2
#define SURFACE_ENEMYHEAD			SurfaceType3
#define SURFACE_ENEMYLIMB			SurfaceType4
#define SURFACE_METAL				SurfaceType5
#define SURFACE_CONCRETE			SurfaceType6
#define SURFACE_WOOD				SurfaceType7
#define SURFACE_FLOOR				SurfaceType8