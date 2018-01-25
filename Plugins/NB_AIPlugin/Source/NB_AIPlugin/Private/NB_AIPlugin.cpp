// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "NB_AIPlugin.h"

#define LOCTEXT_NAMESPACE "FNB_AIPluginModule"

void FNB_AIPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FNB_AIPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNB_AIPluginModule, NB_AIPlugin)