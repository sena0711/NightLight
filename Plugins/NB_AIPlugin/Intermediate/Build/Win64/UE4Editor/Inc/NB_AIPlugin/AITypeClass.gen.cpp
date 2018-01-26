// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Framework/AITypeClass.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAITypeClass() {}
// Cross Module References
	NB_AIPLUGIN_API UEnum* Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
// End Cross Module References
	static UEnum* EAIBehaviorType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType, Z_Construct_UPackage__Script_NB_AIPlugin(), TEXT("EAIBehaviorType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAIBehaviorType(EAIBehaviorType_StaticEnum, TEXT("/Script/NB_AIPlugin"), TEXT("EAIBehaviorType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType_CRC() { return 3750874898U; }
	UEnum* Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NB_AIPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAIBehaviorType"), 0, Get_Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAIBehaviorType::Idle", (int64)EAIBehaviorType::Idle },
				{ "EAIBehaviorType::Neutral", (int64)EAIBehaviorType::Neutral },
				{ "EAIBehaviorType::Suspicious", (int64)EAIBehaviorType::Suspicious },
				{ "EAIBehaviorType::Agression", (int64)EAIBehaviorType::Agression },
				{ "EAIBehaviorType::Flee", (int64)EAIBehaviorType::Flee },
				{ "EAIBehaviorType::Helping", (int64)EAIBehaviorType::Helping },
				{ "EAIBehaviorType::Behavior01", (int64)EAIBehaviorType::Behavior01 },
				{ "EAIBehaviorType::Behavior02", (int64)EAIBehaviorType::Behavior02 },
				{ "EAIBehaviorType::Behavior03", (int64)EAIBehaviorType::Behavior03 },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Agression.ToolTip", "attacking mode" },
				{ "Flee.ToolTip", "Runnning away from an AI." },
				{ "Helping.ToolTip", "Move towards an AI" },
				{ "ModuleRelativePath", "Public/Framework/AITypeClass.h" },
				{ "Neutral.ToolTip", "passive patrolling mode" },
				{ "Suspicious.ToolTip", "hearing or seeing someone." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NB_AIPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EAIBehaviorType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EAIBehaviorType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
