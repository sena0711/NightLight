// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Behaivour/NB_ZoneActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_ZoneActor() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_ZoneActor_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_ZoneActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_ZoneActor_GetRandomPointInVolume();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	void ANB_ZoneActor::StaticRegisterNativesANB_ZoneActor()
	{
		UClass* Class = ANB_ZoneActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetRandomPointInVolume", (Native)&ANB_ZoneActor::execGetRandomPointInVolume },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ANB_ZoneActor_GetRandomPointInVolume()
	{
		struct NB_ZoneActor_eventGetRandomPointInVolume_Parms
		{
			FVector ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NB_ZoneActor_eventGetRandomPointInVolume_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BlackBoard" },
				{ "ModuleRelativePath", "Public/Behaivour/NB_ZoneActor.h" },
				{ "ToolTip", "sets keys in the blackboard" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_ZoneActor, "GetRandomPointInVolume", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(NB_ZoneActor_eventGetRandomPointInVolume_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANB_ZoneActor_NoRegister()
	{
		return ANB_ZoneActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ANB_ZoneActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_NB_AIPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ANB_ZoneActor_GetRandomPointInVolume, "GetRandomPointInVolume" }, // 204635925
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Behaivour/NB_ZoneActor.h" },
				{ "ModuleRelativePath", "Public/Behaivour/NB_ZoneActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoneComponent_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Behaivour/NB_ZoneActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ZoneComponent = { UE4CodeGen_Private::EPropertyClass::Object, "ZoneComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(ANB_ZoneActor, ZoneComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(NewProp_ZoneComponent_MetaData, ARRAY_COUNT(NewProp_ZoneComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoneComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANB_ZoneActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANB_ZoneActor::StaticClass,
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
	IMPLEMENT_CLASS(ANB_ZoneActor, 2371616196);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANB_ZoneActor(Z_Construct_UClass_ANB_ZoneActor, &ANB_ZoneActor::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("ANB_ZoneActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANB_ZoneActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
