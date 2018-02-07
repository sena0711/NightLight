// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
enum class EAIBehaviorType : uint8;
class APawn;
#ifdef NB_AIPLUGIN_NB_BaseAIController_generated_h
#error "NB_BaseAIController.generated.h already included, missing '#pragma once' in NB_BaseAIController.h"
#endif
#define NB_AIPLUGIN_NB_BaseAIController_generated_h

#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetVectorKey) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_VectorKeyName); \
		P_GET_STRUCT(FVector,Z_Param_NewVector); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetVectorKey(Z_Param_VectorKeyName,Z_Param_NewVector); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAIStateKey) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_AIStateKeyName); \
		P_GET_ENUM(EAIBehaviorType,Z_Param_NewState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAIStateKey(Z_Param_AIStateKeyName,EAIBehaviorType(Z_Param_NewState)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectKey) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ObjectKeyName); \
		P_GET_OBJECT(APawn,Z_Param_ObjectReference); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetObjectKey(Z_Param_ObjectKeyName,Z_Param_ObjectReference); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetBlackBoardKeys) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ObjectKeyName); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AIStateKeyName); \
		P_GET_PROPERTY(UNameProperty,Z_Param_VectorKeyName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetBlackBoardKeys(Z_Param_ObjectKeyName,Z_Param_AIStateKeyName,Z_Param_VectorKeyName); \
		P_NATIVE_END; \
	}


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetVectorKey) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_VectorKeyName); \
		P_GET_STRUCT(FVector,Z_Param_NewVector); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetVectorKey(Z_Param_VectorKeyName,Z_Param_NewVector); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAIStateKey) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_AIStateKeyName); \
		P_GET_ENUM(EAIBehaviorType,Z_Param_NewState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAIStateKey(Z_Param_AIStateKeyName,EAIBehaviorType(Z_Param_NewState)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectKey) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ObjectKeyName); \
		P_GET_OBJECT(APawn,Z_Param_ObjectReference); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetObjectKey(Z_Param_ObjectKeyName,Z_Param_ObjectReference); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetBlackBoardKeys) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ObjectKeyName); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AIStateKeyName); \
		P_GET_PROPERTY(UNameProperty,Z_Param_VectorKeyName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetBlackBoardKeys(Z_Param_ObjectKeyName,Z_Param_AIStateKeyName,Z_Param_VectorKeyName); \
		P_NATIVE_END; \
	}


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANB_BaseAIController(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_BaseAIController(); \
public: \
	DECLARE_CLASS(ANB_BaseAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_BaseAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_INCLASS \
private: \
	static void StaticRegisterNativesANB_BaseAIController(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_BaseAIController(); \
public: \
	DECLARE_CLASS(ANB_BaseAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_BaseAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANB_BaseAIController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANB_BaseAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_BaseAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_BaseAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_BaseAIController(ANB_BaseAIController&&); \
	NO_API ANB_BaseAIController(const ANB_BaseAIController&); \
public:


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_BaseAIController(ANB_BaseAIController&&); \
	NO_API ANB_BaseAIController(const ANB_BaseAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_BaseAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_BaseAIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANB_BaseAIController)


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BehaviorTreeComp() { return STRUCT_OFFSET(ANB_BaseAIController, BehaviorTreeComp); } \
	FORCEINLINE static uint32 __PPO__BlackboardComp() { return STRUCT_OFFSET(ANB_BaseAIController, BlackboardComp); }


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_13_PROLOG
#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_PRIVATE_PROPERTY_OFFSET \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_RPC_WRAPPERS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_INCLASS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_PRIVATE_PROPERTY_OFFSET \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_INCLASS_NO_PURE_DECLS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
