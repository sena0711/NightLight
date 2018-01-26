// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Framework/NB_BaseCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_BaseCharacter() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseCharacter_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseCharacter_GainHealth();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseCharacter_GainStamina();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseCharacter_GetbIsAlive();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseCharacter_ReduceHealth();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseCharacter_ReduceStamina();
	NB_AIPLUGIN_API UEnum* Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType();
// End Cross Module References
	void ANB_BaseCharacter::StaticRegisterNativesANB_BaseCharacter()
	{
		UClass* Class = ANB_BaseCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GainHealth", (Native)&ANB_BaseCharacter::execGainHealth },
			{ "GainStamina", (Native)&ANB_BaseCharacter::execGainStamina },
			{ "GetbIsAlive", (Native)&ANB_BaseCharacter::execGetbIsAlive },
			{ "ReduceHealth", (Native)&ANB_BaseCharacter::execReduceHealth },
			{ "ReduceStamina", (Native)&ANB_BaseCharacter::execReduceStamina },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ANB_BaseCharacter_GainHealth()
	{
		struct NB_BaseCharacter_eventGainHealth_Parms
		{
			float GainValue;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((NB_BaseCharacter_eventGainHealth_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(NB_BaseCharacter_eventGainHealth_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GainValue = { UE4CodeGen_Private::EPropertyClass::Float, "GainValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseCharacter_eventGainHealth_Parms, GainValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GainValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseCharacter, "GainHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseCharacter_eventGainHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseCharacter_GainStamina()
	{
		struct NB_BaseCharacter_eventGainStamina_Parms
		{
			float GainValue;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((NB_BaseCharacter_eventGainStamina_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(NB_BaseCharacter_eventGainStamina_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GainValue = { UE4CodeGen_Private::EPropertyClass::Float, "GainValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseCharacter_eventGainStamina_Parms, GainValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GainValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseCharacter, "GainStamina", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseCharacter_eventGainStamina_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseCharacter_GetbIsAlive()
	{
		struct NB_BaseCharacter_eventGetbIsAlive_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((NB_BaseCharacter_eventGetbIsAlive_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(NB_BaseCharacter_eventGetbIsAlive_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseCharacter, "GetbIsAlive", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseCharacter_eventGetbIsAlive_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseCharacter_ReduceHealth()
	{
		struct NB_BaseCharacter_eventReduceHealth_Parms
		{
			float ReductionValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReductionValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReductionValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseCharacter_eventReduceHealth_Parms, ReductionValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReductionValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseCharacter, "ReduceHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseCharacter_eventReduceHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseCharacter_ReduceStamina()
	{
		struct NB_BaseCharacter_eventReduceStamina_Parms
		{
			float ReductionValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReductionValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReductionValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseCharacter_eventReduceStamina_Parms, ReductionValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReductionValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseCharacter, "ReduceStamina", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseCharacter_eventReduceStamina_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANB_BaseCharacter_NoRegister()
	{
		return ANB_BaseCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ANB_BaseCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_NB_AIPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ANB_BaseCharacter_GainHealth, "GainHealth" }, // 4234958116
				{ &Z_Construct_UFunction_ANB_BaseCharacter_GainStamina, "GainStamina" }, // 4179740586
				{ &Z_Construct_UFunction_ANB_BaseCharacter_GetbIsAlive, "GetbIsAlive" }, // 3805349414
				{ &Z_Construct_UFunction_ANB_BaseCharacter_ReduceHealth, "ReduceHealth" }, // 3341641428
				{ &Z_Construct_UFunction_ANB_BaseCharacter_ReduceStamina, "ReduceStamina" }, // 1878223011
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Framework/NB_BaseCharacter.h" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CurrentState = { UE4CodeGen_Private::EPropertyClass::Enum, "CurrentState", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000020001, 1, nullptr, STRUCT_OFFSET(ANB_BaseCharacter, CurrentState), Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType, METADATA_PARAMS(NewProp_CurrentState_MetaData, ARRAY_COUNT(NewProp_CurrentState_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxStamina = { UE4CodeGen_Private::EPropertyClass::Float, "MaxStamina", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000015, 1, nullptr, STRUCT_OFFSET(ANB_BaseCharacter, MaxStamina), METADATA_PARAMS(NewProp_MaxStamina_MetaData, ARRAY_COUNT(NewProp_MaxStamina_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentStamina_MetaData[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
				{ "ToolTip", "Status." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentStamina = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentStamina", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000015, 1, nullptr, STRUCT_OFFSET(ANB_BaseCharacter, CurrentStamina), METADATA_PARAMS(NewProp_CurrentStamina_MetaData, ARRAY_COUNT(NewProp_CurrentStamina_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth = { UE4CodeGen_Private::EPropertyClass::Float, "MaxHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000015, 1, nullptr, STRUCT_OFFSET(ANB_BaseCharacter, MaxHealth), METADATA_PARAMS(NewProp_MaxHealth_MetaData, ARRAY_COUNT(NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
				{ "Category", "Status" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseCharacter.h" },
				{ "ToolTip", "Status." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000015, 1, nullptr, STRUCT_OFFSET(ANB_BaseCharacter, CurrentHealth), METADATA_PARAMS(NewProp_CurrentHealth_MetaData, ARRAY_COUNT(NewProp_CurrentHealth_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentState,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentState_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxStamina,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentStamina,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentHealth,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANB_BaseCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANB_BaseCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANB_BaseCharacter, 836640212);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANB_BaseCharacter(Z_Construct_UClass_ANB_BaseCharacter, &ANB_BaseCharacter::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("ANB_BaseCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANB_BaseCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
