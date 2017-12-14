#pragma once

#include "Engine/DataTable.h"
#include "TypeClass.generated.h"


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

	FInventoryItem()
	{
		MaxStackNumber = 30;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID; // Unique ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EItemType ItemType; //itemtype
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 indexNumber; //
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxStackNumber; //stack number
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentStackNumber; //
};
