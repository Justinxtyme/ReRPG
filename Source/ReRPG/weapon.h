//weapon.h
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "item.h"
#include "power.h"
#include <entt/entt.hpp>
#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class WeaponType : uint8 {
    Dagger,
    ShortSword,
    MediumSword,
    LongSword,
    BattleAxe,
    WarHammer,
    ShortBow, 
    LongBow,
    CrossBow
};

UENUM(BlueprintType)
enum class WeaponSlot: uint8 {
    MainHand,
    OffHand,
    TwoHand 
};

UENUM(BlueprintType)
enum class Handling: uint8 {
    OneHanded,
    TwoHanded
};

UENUM(BlueprintType)
enum class DmgType : uint8 {
    Slashing,
    Piercing,
    Blunt,
    Ranged,
    Magic
};

enum class Effects;


struct WeaponStatsComponent {
    WeaponType  type;
    int         damage;
    Handling    handling;
    DmgType     dmgType;
    int         baseDamage;
    float       rarity_mod;
    std::unordered_map<std::string, float> scaling;
    std::vector<AbilityID> grantedAbilities;
};

std::string weaponType2String(WeaponType type);

std::string weaponHandling2String(Handling handle);

std::string damageType2String(DmgType dmg);

void printWeapInfo(entt::entity weap, entt::registry &reg);

void printWeapEffects(entt::entity e, entt::registry& reg);
