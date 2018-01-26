// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Framework/NB_BaseNPCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_BaseNPCharacter() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseNPCharacter_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseNPCharacter();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseCharacter();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseNPCharacter_OnHearNoise();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseNPCharacter_OnSeePlayer();
	ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ANB_BaseNPCharacter::StaticRegisterNativesANB_BaseNPCharacter()
	{
		UClass* Class = ANB_BaseNPCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHearNoise", (Native)&ANB_BaseNPCharacter::execOnHearNoise },
			{ "OnSeePlayer", (Native)&ANB_BaseNPCharacter::execOnSeePlayer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ANB_BaseNPCharacter_OnHearNoise()
	{
		struct NB_BaseNPCharacter_eventOnHearNoise_Parms
		{
			APawn* PawnInstigator;
			FVector Location;
			float Volume;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Volume = { UE4CodeGen_Private::EPropertyClass::Float, "Volume", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseNPCharacter_eventOnHearNoise_Parms, Volume), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location = { UE4CodeGen_Private::EPropertyClass::Struct, "Location", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NB_BaseNPCharacter_eventOnHearNoise_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_Location_MetaData, ARRAY_COUNT(NewProp_Location_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PawnInstigator = { UE4CodeGen_Private::EPropertyClass::Object, "PawnInstigator", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseNPCharacter_eventOnHearNoise_Parms, PawnInstigator), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Volume,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Location,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnInstigator,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Framework/NB_BaseNPCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseNPCharacter, "OnHearNoise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00C20400, sizeof(NB_BaseNPCharacter_eventOnHearNoise_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseNPCharacter_OnSeePlayer()
	{
		struct NB_BaseNPCharacter_eventOnSeePlayer_Parms
		{
			APawn* Pawn;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Pawn = { UE4CodeGen_Private::EPropertyClass::Object, "Pawn", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseNPCharacter_eventOnSeePlayer_Parms, Pawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Pawn,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Framework/NB_BaseNPCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseNPCharacter, "OnSeePlayer", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020400, sizeof(NB_BaseNPCharacter_eventOnSeePlayer_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANB_BaseNPCharacter_NoRegister()
	{
		return ANB_BaseNPCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ANB_BaseNPCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ANB_BaseCharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_NB_AIPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ANB_BaseNPCharacter_OnHearNoise, "OnHearNoise" }, // 2116399491
				{ &Z_Construct_UFunction_ANB_BaseNPCharacter_OnSeePlayer, "OnSeePlayer" }, // 732271160
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Framework/NB_BaseNPCharacter.h" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseNPCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AudioLoopComp_MetaData[] = {
				{ "Category", "Sound" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseNPCharacter.h" },
				{ "ToolTip", "Plays the idle, wandering or hunting sound" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AudioLoopComp = { UE4CodeGen_Private::EPropertyClass::Object, "AudioLoopComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a0009, 1, nullptr, STRUCT_OFFSET(ANB_BaseNPCharacter, AudioLoopComp), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(NewProp_AudioLoopComp_MetaData, ARRAY_COUNT(NewProp_AudioLoopComp_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PawnSensingComp_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseNPCharacter.h" },
				{ "ToolTip", "AI seeing, Sensing component" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PawnSensingComp = { UE4CodeGen_Private::EPropertyClass::Object, "PawnSensingComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a0009, 1, nullptr, STRUCT_OFFSET(ANB_BaseNPCharacter, PawnSensingComp), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(NewProp_PawnSensingComp_MetaData, ARRAY_COUNT(NewProp_PawnSensingComp_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTree_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseNPCharacter.h" },
				{ "ToolTip", "Assigned at the Character level (instead of Controller) so we may use different zombie behaviors while re-using one controller." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BehaviorTree = { UE4CodeGen_Private::EPropertyClass::Object, "BehaviorTree", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(ANB_BaseNPCharacter, BehaviorTree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(NewProp_BehaviorTree_MetaData, ARRAY_COUNT(NewProp_BehaviorTree_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AudioLoopComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnSensingComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BehaviorTree,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANB_BaseNPCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANB_BaseNPCharacter::StaticClass,
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
	IMPLEMENT_CLASS(ANB_BaseNPCharacter, 746524544);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANB_BaseNPCharacter(Z_Construct_UClass_ANB_BaseNPCharacter, &ANB_BaseNPCharacter::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("ANB_BaseNPCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANB_BaseNPCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
