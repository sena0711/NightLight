#pragma once

#include "Engine/DataTable.h"
#include "TypeClass.generated.h"

#define NOTEXISTING 100
#define EXISTINGBULLETTYPES 2


UENUM(BlueprintType)
enum class ENPCPersonality : uint8
{
	Neutral,

	Shy,

	Confident,

	Formal,

	Aggresive,
};
UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	Idle,
	Firing,
	Equipping,
	Reloading
};

/*WeaponTypeDecides how the weapon shoots*/
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EMelee,
	/*Pistol like weapons*/
	EBullet,
	/*Shotgun like weapons*/
	ESpread,
	/*Misslie like weapons*/
	EProjectile,
};


//TableRowBase for Weapon Data TABLE. 
USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

public:

	/** clip size */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		int32 MaxAmmoPerClip;

	/** Current Ammo Inside Clip */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		int32 CurrentAmmo;

	/** Cost of ammo on each shot */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		int32 ShotCost;

	/** time between two consecutive shots */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		float TimeBetweenShots;

	/** Weapon Image displayed in UI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		UTexture2D* WeaponImage;

	/** Projectile travel length */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		float WeaponRange;


	/** defaults */
	FWeaponData()
	{
		MaxAmmoPerClip = 20;
		CurrentAmmo = 4;
		ShotCost = 1;
		TimeBetweenShots = 0.2f;

	}
};

/*Bullet Type decides how bullets are like*/
UENUM(BlueprintType)
enum class EBulletType : uint8
{	/*Standard Bullets*/
	EStandard,
	/* Bullet with small led light */
	ELight,
};

//Struct of Bullets Player can possess. 
USTRUCT(BlueprintType)
struct FBulletItem
{
	GENERATED_BODY()

public:
	/** max ammo */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		int32 CurrentPossesed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		EBulletType BulletType;

	/** Weapon Image displayed in UI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
		UTexture2D* BulletImage;

	//ureal requires oveloading the data. 
	bool operator == (const FBulletItem& Item) const
	{
		if (BulletType == Item.BulletType)
			return true;
		else return false;
	}
};

/*Quest Item Type*/
UENUM(BlueprintType)
enum class EQuestType : uint8
{
	EFruit,

	EDefault
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Key,

	Health,

	Battery,

	StandardBullets,

	LightBullets,

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
