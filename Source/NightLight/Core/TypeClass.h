#pragma once

#include "Engine/DataTable.h"
#include "TypeClass.generated.h"

UENUM()
enum class EWeaponType : uint8
{
	/*Pistol like weapons*/
	EBullet,
	/*Shotgun like weapons*/
	ESpread,
	/*Misslie like weapons*/
	EProjectile,
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Key,

	Health,

	Battery,

	Bullets,

	Torch,

	Weapon,

	Quest,

	Instruction,

};


/**
*
*/
// Struct of things player can posses. 
USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EItemType ItemType; //itemtype
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 indexNumber; //
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentStackNumber; //


								  //ureal requires oveloading the data. 
		bool operator == (const FInventoryItem& Item) const
		{
			if (ItemType == Item.ItemType)
				return true;
			else return false;
		}
};
