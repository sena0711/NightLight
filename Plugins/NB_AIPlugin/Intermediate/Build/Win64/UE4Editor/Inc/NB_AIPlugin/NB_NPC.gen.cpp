// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Framework/NB_NPC.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_NPC() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_NPC_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_NPC();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseCharacter();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
// End Cross Module References
	void ANB_NPC::StaticRegisterNativesANB_NPC()
	{
	}
	UClass* Z_Construct_UClass_ANB_NPC_NoRegister()
	{
		return ANB_NPC::StaticClass();
	}
	UClass* Z_Construct_UClass_ANB_NPC()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ANB_BaseCharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_NB_AIPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Framework/NB_NPC.h" },
				{ "ModuleRelativePath", "Public/Framework/NB_NPC.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANB_NPC>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANB_NPC::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANB_NPC, 357283719);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANB_NPC(Z_Construct_UClass_ANB_NPC, &ANB_NPC::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("ANB_NPC"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANB_NPC);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
