// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Behaivour/NB_BT_FollwingAI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_BT_FollwingAI() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_UNB_BT_FollwingAI_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_UNB_BT_FollwingAI();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
// End Cross Module References
	void UNB_BT_FollwingAI::StaticRegisterNativesUNB_BT_FollwingAI()
	{
	}
	UClass* Z_Construct_UClass_UNB_BT_FollwingAI_NoRegister()
	{
		return UNB_BT_FollwingAI::StaticClass();
	}
	UClass* Z_Construct_UClass_UNB_BT_FollwingAI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
				(UObject* (*)())Z_Construct_UPackage__Script_NB_AIPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Behaivour/NB_BT_FollwingAI.h" },
				{ "ModuleRelativePath", "Public/Behaivour/NB_BT_FollwingAI.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNB_BT_FollwingAI>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNB_BT_FollwingAI::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
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
	IMPLEMENT_CLASS(UNB_BT_FollwingAI, 2805813500);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNB_BT_FollwingAI(Z_Construct_UClass_UNB_BT_FollwingAI, &UNB_BT_FollwingAI::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("UNB_BT_FollwingAI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNB_BT_FollwingAI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
