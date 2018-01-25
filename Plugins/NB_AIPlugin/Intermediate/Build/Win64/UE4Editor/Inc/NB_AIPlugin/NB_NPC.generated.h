// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
struct FVector;
#ifdef NB_AIPLUGIN_NB_NPC_generated_h
#error "NB_NPC.generated.h already included, missing '#pragma once' in NB_NPC.h"
#endif
#define NB_AIPLUGIN_NB_NPC_generated_h

#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHearNoise) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_PawnInstigator); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHearNoise(Z_Param_PawnInstigator,Z_Param_Out_Location,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnSeePlayer) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_Pawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnSeePlayer(Z_Param_Pawn); \
		P_NATIVE_END; \
	}


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHearNoise) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_PawnInstigator); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHearNoise(Z_Param_PawnInstigator,Z_Param_Out_Location,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnSeePlayer) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_Pawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnSeePlayer(Z_Param_Pawn); \
		P_NATIVE_END; \
	}


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANB_NPC(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_NPC(); \
public: \
	DECLARE_CLASS(ANB_NPC, ANB_BaseCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_NPC) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_INCLASS \
private: \
	static void StaticRegisterNativesANB_NPC(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_NPC(); \
public: \
	DECLARE_CLASS(ANB_NPC, ANB_BaseCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_NPC) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANB_NPC(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANB_NPC) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_NPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_NPC); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_NPC(ANB_NPC&&); \
	NO_API ANB_NPC(const ANB_NPC&); \
public:


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_NPC(ANB_NPC&&); \
	NO_API ANB_NPC(const ANB_NPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_NPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_NPC); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANB_NPC)


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BehaviorTree() { return STRUCT_OFFSET(ANB_NPC, BehaviorTree); } \
	FORCEINLINE static uint32 __PPO__AudioLoopComp() { return STRUCT_OFFSET(ANB_NPC, AudioLoopComp); } \
	FORCEINLINE static uint32 __PPO__PawnSensingComp() { return STRUCT_OFFSET(ANB_NPC, PawnSensingComp); }


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_12_PROLOG
#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_PRIVATE_PROPERTY_OFFSET \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_RPC_WRAPPERS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_INCLASS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_PRIVATE_PROPERTY_OFFSET \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_INCLASS_NO_PURE_DECLS \
	NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NightLight_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Framework_NB_NPC_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS