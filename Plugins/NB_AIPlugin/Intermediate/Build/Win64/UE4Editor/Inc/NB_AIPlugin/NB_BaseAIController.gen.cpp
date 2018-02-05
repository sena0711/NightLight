// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Framework/NB_BaseAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNB_BaseAIController() {}
// Cross Module References
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseAIController_NoRegister();
	NB_AIPLUGIN_API UClass* Z_Construct_UClass_ANB_BaseAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_NB_AIPlugin();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseAIController_ResetBlackBoardKeys();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseAIController_SetAIStateKey();
	NB_AIPLUGIN_API UEnum* Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseAIController_SetObjectKey();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	NB_AIPLUGIN_API UFunction* Z_Construct_UFunction_ANB_BaseAIController_SetVectorKey();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
// End Cross Module References
	void ANB_BaseAIController::StaticRegisterNativesANB_BaseAIController()
	{
		UClass* Class = ANB_BaseAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetBlackBoardKeys", (Native)&ANB_BaseAIController::execResetBlackBoardKeys },
			{ "SetAIStateKey", (Native)&ANB_BaseAIController::execSetAIStateKey },
			{ "SetObjectKey", (Native)&ANB_BaseAIController::execSetObjectKey },
			{ "SetVectorKey", (Native)&ANB_BaseAIController::execSetVectorKey },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ANB_BaseAIController_ResetBlackBoardKeys()
	{
		struct NB_BaseAIController_eventResetBlackBoardKeys_Parms
		{
			FName ObjectKeyName;
			FName AIStateKeyName;
			FName VectorKeyName;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_VectorKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "VectorKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventResetBlackBoardKeys_Parms, VectorKeyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_AIStateKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "AIStateKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventResetBlackBoardKeys_Parms, AIStateKeyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ObjectKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "ObjectKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventResetBlackBoardKeys_Parms, ObjectKeyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_VectorKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AIStateKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectKeyName,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BlackBoard" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
				{ "ToolTip", "sets All keys in the blackboard" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseAIController, "ResetBlackBoardKeys", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseAIController_eventResetBlackBoardKeys_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseAIController_SetAIStateKey()
	{
		struct NB_BaseAIController_eventSetAIStateKey_Parms
		{
			FName AIStateKeyName;
			EAIBehaviorType NewState;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_NewState = { UE4CodeGen_Private::EPropertyClass::Enum, "NewState", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventSetAIStateKey_Parms, NewState), Z_Construct_UEnum_NB_AIPlugin_EAIBehaviorType, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_AIStateKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "AIStateKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventSetAIStateKey_Parms, AIStateKeyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewState,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewState_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AIStateKeyName,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BlackBoard" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
				{ "ToolTip", "sets AIState keys in the blackboard" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseAIController, "SetAIStateKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseAIController_eventSetAIStateKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseAIController_SetObjectKey()
	{
		struct NB_BaseAIController_eventSetObjectKey_Parms
		{
			FName ObjectKeyName;
			APawn* ObjectReference;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ObjectReference = { UE4CodeGen_Private::EPropertyClass::Object, "ObjectReference", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventSetObjectKey_Parms, ObjectReference), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ObjectKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "ObjectKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventSetObjectKey_Parms, ObjectKeyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectReference,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectKeyName,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BlackBoard" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
				{ "ToolTip", "sets keys in the blackboard" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseAIController, "SetObjectKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NB_BaseAIController_eventSetObjectKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANB_BaseAIController_SetVectorKey()
	{
		struct NB_BaseAIController_eventSetVectorKey_Parms
		{
			FName VectorKeyName;
			FVector NewVector;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewVector = { UE4CodeGen_Private::EPropertyClass::Struct, "NewVector", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventSetVectorKey_Parms, NewVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_VectorKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "VectorKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NB_BaseAIController_eventSetVectorKey_Parms, VectorKeyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewVector,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_VectorKeyName,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BlackBoard" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
				{ "ToolTip", "sets AIState keys in the blackboard" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ANB_BaseAIController, "SetVectorKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(NB_BaseAIController_eventSetVectorKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANB_BaseAIController_NoRegister()
	{
		return ANB_BaseAIController::StaticClass();
	}
	UClass* Z_Construct_UClass_ANB_BaseAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AAIController,
				(UObject* (*)())Z_Construct_UPackage__Script_NB_AIPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ANB_BaseAIController_ResetBlackBoardKeys, "ResetBlackBoardKeys" }, // 1067501298
				{ &Z_Construct_UFunction_ANB_BaseAIController_SetAIStateKey, "SetAIStateKey" }, // 1939857498
				{ &Z_Construct_UFunction_ANB_BaseAIController_SetObjectKey, "SetObjectKey" }, // 3227834276
				{ &Z_Construct_UFunction_ANB_BaseAIController_SetVectorKey, "SetVectorKey" }, // 3715567202
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "Framework/NB_BaseAIController.h" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlackboardComp_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
				{ "ToolTip", "Blackboard component reference" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BlackboardComp = { UE4CodeGen_Private::EPropertyClass::Object, "BlackboardComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a0009, 1, nullptr, STRUCT_OFFSET(ANB_BaseAIController, BlackboardComp), Z_Construct_UClass_UBlackboardComponent_NoRegister, METADATA_PARAMS(NewProp_BlackboardComp_MetaData, ARRAY_COUNT(NewProp_BlackboardComp_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTreeComp_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Framework/NB_BaseAIController.h" },
				{ "ToolTip", "Behavior tree component" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BehaviorTreeComp = { UE4CodeGen_Private::EPropertyClass::Object, "BehaviorTreeComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a0009, 1, nullptr, STRUCT_OFFSET(ANB_BaseAIController, BehaviorTreeComp), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(NewProp_BehaviorTreeComp_MetaData, ARRAY_COUNT(NewProp_BehaviorTreeComp_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BlackboardComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BehaviorTreeComp,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANB_BaseAIController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANB_BaseAIController::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900280u,
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
	IMPLEMENT_CLASS(ANB_BaseAIController, 935714359);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANB_BaseAIController(Z_Construct_UClass_ANB_BaseAIController, &ANB_BaseAIController::StaticClass, TEXT("/Script/NB_AIPlugin"), TEXT("ANB_BaseAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANB_BaseAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
