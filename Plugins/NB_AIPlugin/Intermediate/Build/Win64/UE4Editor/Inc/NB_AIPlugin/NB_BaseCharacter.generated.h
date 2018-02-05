// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EAIBehaviorType : uint8;
#ifdef NB_AIPLUGIN_NB_BaseCharacter_generated_h
#error "NB_BaseCharacter.generated.h already included, missing '#pragma once' in NB_BaseCharacter.h"
#endif
#define NB_AIPLUGIN_NB_BaseCharacter_generated_h

#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrentBehaviorState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EAIBehaviorType*)Z_Param__Result=this->GetCurrentBehaviorState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentBehaviorState) \
	{ \
		P_GET_ENUM(EAIBehaviorType,Z_Param_AIState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetCurrentBehaviorState(EAIBehaviorType(Z_Param_AIState)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceStamina) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ReductionValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReduceStamina(Z_Param_ReductionValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGainStamina) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_GainValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GainStamina(Z_Param_GainValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ReductionValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReduceHealth(Z_Param_ReductionValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGainHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_GainValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GainHealth(Z_Param_GainValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetbIsAlive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetbIsAlive(); \
		P_NATIVE_END; \
	}


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentBehaviorState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EAIBehaviorType*)Z_Param__Result=this->GetCurrentBehaviorState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentBehaviorState) \
	{ \
		P_GET_ENUM(EAIBehaviorType,Z_Param_AIState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetCurrentBehaviorState(EAIBehaviorType(Z_Param_AIState)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceStamina) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ReductionValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReduceStamina(Z_Param_ReductionValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGainStamina) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_GainValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GainStamina(Z_Param_GainValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ReductionValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReduceHealth(Z_Param_ReductionValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGainHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_GainValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GainHealth(Z_Param_GainValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetbIsAlive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetbIsAlive(); \
		P_NATIVE_END; \
	}


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANB_BaseCharacter(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_BaseCharacter(); \
public: \
	DECLARE_CLASS(ANB_BaseCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_BaseCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesANB_BaseCharacter(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_BaseCharacter(); \
public: \
	DECLARE_CLASS(ANB_BaseCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_BaseCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANB_BaseCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANB_BaseCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_BaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_BaseCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_BaseCharacter(ANB_BaseCharacter&&); \
	NO_API ANB_BaseCharacter(const ANB_BaseCharacter&); \
public:


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_BaseCharacter(ANB_BaseCharacter&&); \
	NO_API ANB_BaseCharacter(const ANB_BaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_BaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_BaseCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANB_BaseCharacter)


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurrentHealth() { return STRUCT_OFFSET(ANB_BaseCharacter, CurrentHealth); } \
	FORCEINLINE static uint32 __PPO__MaxHealth() { return STRUCT_OFFSET(ANB_BaseCharacter, MaxHealth); } \
	FORCEINLINE static uint32 __PPO__CurrentStamina() { return STRUCT_OFFSET(ANB_BaseCharacter, CurrentStamina); } \
	FORCEINLINE static uint32 __PPO__MaxStamina() { return STRUCT_OFFSET(ANB_BaseCharacter, MaxStamina); } \
	FORCEINLINE static uint32 __PPO__CurrentState() { return STRUCT_OFFSET(ANB_BaseCharacter, CurrentState); }


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_10_PROLOG
#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_RPC_WRAPPERS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_INCLASS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_INCLASS_NO_PURE_DECLS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_BaseCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
