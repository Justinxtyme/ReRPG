#pragma once
#include "CoreMinimal.h"
#include "weapon.h"
#include "entt/entt.hpp"
#include "item.h"
#include "armor.h"
#include "InventoryData.generated.h"

struct ArmorStatsComponent;
class ItemFactory;


UCLASS(BlueprintType)
class UWeaponData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	WeaponType Type_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	Handling Handling_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	DmgType DamageType_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	int32 BaseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	float RarityMod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	TMap<FString, float> Scaling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	TArray<FName> GrantedAbilities;
};

UCLASS(BlueprintType)
class UArmorData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor")
	ArmorClass ArmorClass_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor")
	ArmorType ArmorType_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor")
	int32 BaseDefense;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor")
	float RarityMod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor")
	TArray<FName> GrantedAbilities;
};


USTRUCT(BlueprintType)
struct FItemStack
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemID ItemID = EItemID::Potion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count = 0;
};

USTRUCT(BlueprintType)
struct FEquippedArmor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemID ItemID = EItemID::BlessedClothHood;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ArmorType Slot = ArmorType::Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UArmorData> ArmorClass;
};

USTRUCT(BlueprintType)
struct FEquippedWeapon
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemID ItemID = EItemID::SteelDagger;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WeaponSlot Slot = WeaponSlot::MainHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UWeaponData> WeaponClass;
};

// Editor-facing defaults (authoring only)
USTRUCT(BlueprintType)
struct FInventoryDefaults
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemStack> DefaultStackables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEquippedArmor> DefaultArmor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEquippedWeapon> DefaultWeapons;
};

// Example: attach to an Actor just for authoring
UCLASS()
class UInventoryAuthoringComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Inventory")
	FInventoryDefaults Defaults;
};



WeaponStatsComponent MakeWeaponStats(const UWeaponData* Data);

ArmorStatsComponent MakeArmorStats(const UArmorData* Data);

void BuildInventoryFromDefaults(entt::registry& Registry, const entt::entity Entity, const FInventoryDefaults& Defaults, ItemFactory IFactory);