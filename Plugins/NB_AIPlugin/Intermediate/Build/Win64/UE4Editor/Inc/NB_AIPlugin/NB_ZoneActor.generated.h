// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef NB_AIPLUGIN_NB_ZoneActor_generated_h
#error "NB_ZoneActor.generated.h already included, missing '#pragma once' in NB_ZoneActor.h"
#endif
#define NB_AIPLUGIN_NB_ZoneActor_generated_h

#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetRandomPointInVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=this->GetRandomPointInVolume(); \
		P_NATIVE_END; \
	}


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetRandomPointInVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=this->GetRandomPointInVolume(); \
		P_NATIVE_END; \
	}


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANB_ZoneActor(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_ZoneActor(); \
public: \
	DECLARE_CLASS(ANB_ZoneActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_ZoneActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesANB_ZoneActor(); \
	friend NB_AIPLUGIN_API class UClass* Z_Construct_UClass_ANB_ZoneActor(); \
public: \
	DECLARE_CLASS(ANB_ZoneActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NB_AIPlugin"), NO_API) \
	DECLARE_SERIALIZER(ANB_ZoneActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANB_ZoneActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANB_ZoneActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_ZoneActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_ZoneActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_ZoneActor(ANB_ZoneActor&&); \
	NO_API ANB_ZoneActor(const ANB_ZoneActor&); \
public:


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANB_ZoneActor(ANB_ZoneActor&&); \
	NO_API ANB_ZoneActor(const ANB_ZoneActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANB_ZoneActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANB_ZoneActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANB_ZoneActor)


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ZoneComponent() { return STRUCT_OFFSET(ANB_ZoneActor, ZoneComponent); }


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_9_PROLOG
#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_PRIVATE_PROPERTY_OFFSET \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_RPC_WRAPPERS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_INCLASS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_PRIVATE_PROPERTY_OFFSET \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_INCLASS_NO_PURE_DECLS \
	NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NightLight_master_Plugins_NB_AIPlugin_Source_NB_AIPlugin_Public_Behaivour_NB_ZoneActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
