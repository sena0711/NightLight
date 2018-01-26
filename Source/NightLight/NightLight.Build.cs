// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NightLight : ModuleRules
{
	public NightLight(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "SlateCore"});
       // PublicDependencyModuleNames.AddRange(new string[] { "NB_AIPlugin" });
        PrivateDependencyModuleNames.AddRange(new string[] { "AIModule" });
    }
}
