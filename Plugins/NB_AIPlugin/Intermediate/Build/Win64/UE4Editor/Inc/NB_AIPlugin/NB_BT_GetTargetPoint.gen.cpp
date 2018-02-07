// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Behaivour/NB_BT_GetTargetPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_BT_GetTargetPoint() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_UNB_BT_GetTargetPoint_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_UNB_BT_GetTargetPoint();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
// End Cross Module References
	void UNB_BT_GetTargetPoint::StaticRegisterNativesUNB_BT_GetTargetPoint()
	{
	}
	UClass* Z_Construct_UClass_UNB_BT_GetTargetPoint_NoRegister()
	{
		return UNB_BT_GetTargetPoint::StaticClass();
	}
	UClass* Z_Construct_UClass_UNB_BT_GetTargetPoint()
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
				{ "IncludePath", "Behaivour/NB_BT_GetTargetPoint.h" },
				{ "ModuleRelativePath", "Public/Behaivour/NB_BT_GetTargetPoint.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNB_BT_GetTargetPoint>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNB_BT_GetTargetPoint::StaticClass,
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
	IMPLEMENT_CLASS(UNB_BT_GetTargetPoint, 3530602286);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNB_BT_GetTargetPoint(Z_Construct_UClass_UNB_BT_GetTargetPoint, &UNB_BT_GetTargetPoint::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("UNB_BT_GetTargetPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNB_BT_GetTargetPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
