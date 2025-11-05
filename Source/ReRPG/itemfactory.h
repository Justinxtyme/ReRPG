// ItemFactory.h
#pragma once
#include <memory>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include "weapon.h"
#include "armor.h"
#include "item.h"
#include "component.h"
#include "effects.h"
#include "power.h"
//#include "EntityManager/Public/EntityManagerSubsystem.h"
#include "CoreMinimal.h"

/* TODO: Test out attribute scaling and make sure we are parsing the
         json data correctly   
*/

class UEntityManagerSubsystem;



enum class ItemKind {
    Weapon,
    Armor,
    Consumable,
    KeyItem
};

struct ItemArchetype {
    ItemID id;
    ItemKind kind;

    std::string name;
    float weight;
    std::vector<EffectID> effects;

    std::optional<float> rarityMod;

    //weapon specific stats
    WeaponType weaponType;
    Handling handling;
    DmgType dmgType;
    int baseDamage;
    std::unordered_map<std::string, float> scaling;
    std::vector<AbilityID> weaponAbilities;
    
    //armor specific stats
    ArmorClass armorClass;
    ArmorType armorType;
    int baseDefense;
    std::vector<AbilityID> armorAbilities;
};



class ItemFactory {
    inline static nlohmann::json itemData; // static shared data
    
public:

    // Registry of archetypes
    inline static std::unordered_map<ItemID, ItemArchetype> itemArchetypes;
 
    static void load(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open " + filename);
        }

        nlohmann::json data;
        file >> data;

        for (auto& [key, value] : data.items()) {
            ItemID id;
            try {
                id = itemFromString(key).value();
            } catch (const std::bad_optional_access&) {
                throw std::runtime_error("Failed to parse item ID '" + key + "' from JSON.");
            }

            ItemArchetype arch;
            //arch.id     = id; 
            arch.kind   = parseKind(value["type"]);
            arch.name   = value["Name"];
            arch.weight = value["Weight"];

            // Always collect effects into one vector
            if (value.contains("effects")) {
                for (auto& e : value["effects"]) {
                    arch.effects.push_back(parseEffectID(e));
                }
            }

            if (arch.kind == ItemKind::Weapon) {
                // rarity only for weapons
                if (value.contains("Rarity Mod")) {
                    arch.rarityMod = value["Rarity Mod"].get<float>();
                }

                for (auto& a : value["abilities"]) {
                    arch.weaponAbilities.push_back(parseAbility(a));
                }

                arch.weaponType = parseWeaponType(value["Weapon Type"]);
                arch.handling   = parseHandling(value["Handling"]);
                arch.dmgType    = parseDamageType(value["Damage Type"]);
                arch.baseDamage = value["Base Damage"];

                if (value.contains("Scaling")) {
                    for (auto& [stat, factor] : value["Scaling"].items()) {
                        arch.scaling[stat] = factor;
                    }
                }
            }
            else if (arch.kind == ItemKind::Armor) {
                // rarity only for armor
                if (value.contains("Rarity Mod")) {
                    arch.rarityMod = value["Rarity Mod"].get<float>();
                }

                for (auto& a : value["abilities"]) {
                    arch.armorAbilities.push_back(parseAbility(a));
                }

                arch.armorClass  = parseArmorClass(value["Armor Class"]);
                arch.armorType   = parseArmorType(value["Armor Type"]);
                arch.baseDefense = value["Base Defense"];
            }

            itemArchetypes[id] = std::move(arch);
        }
    }


    static entt::entity create(entt::registry &reg, ItemID id) {
        auto it = itemArchetypes.find(id);
        if (it == itemArchetypes.end()) {
            throw std::runtime_error("Unknown ItemID");
        }
        const ItemArchetype &arch = it->second;
        
        entt::entity e = reg.create();

        // Base item component: always present
        reg.emplace<ItemComponent>(
            e,
            id,
            arch.name,
            arch.weight,
            arch.effects // unified effects vector
        );

        // Weapon stats
        if (arch.kind == ItemKind::Weapon) {
            WeaponStatsComponent wsc;
            wsc.type       = arch.weaponType;
            wsc.handling   = arch.handling;
            wsc.dmgType    = arch.dmgType;
            wsc.baseDamage = arch.baseDamage;
            wsc.rarity_mod = arch.rarityMod.value_or(1.0f); // optional<float>
            wsc.scaling    = arch.scaling;
            wsc.grantedAbilities  = arch.weaponAbilities;
            reg.emplace<WeaponStatsComponent>(e, std::move(wsc));
        }
        // Armor stats
        else if (arch.kind == ItemKind::Armor) {
            ArmorStatsComponent asc;
            asc.armorClass  = arch.armorClass;
            asc.armorType   = arch.armorType;
            asc.baseDefense = arch.baseDefense;
            asc.rarity_mod  = arch.rarityMod.value_or(1.0f);
            asc.grantedAbilities   = arch.armorAbilities;
            reg.emplace<ArmorStatsComponent>(e, std::move(asc));
        }

        return e;
    }

    
    static void Populate(entt::registry &reg, entt::entity e, ItemID id) {
        auto it = itemArchetypes.find(id);
        if (it == itemArchetypes.end()) {
            throw std::runtime_error("Unknown ItemID");
        }
        const ItemArchetype &arch = it->second;
        
    
        // Base item component: always present
        reg.emplace<ItemComponent>(
            e,
            id,
            arch.name,
            arch.weight,
            arch.effects // unified effects vector
        );
    
        // Weapon stats
        if (arch.kind == ItemKind::Weapon) {
            WeaponStatsComponent wsc;
            wsc.type       = arch.weaponType;
            wsc.handling   = arch.handling;
            wsc.dmgType    = arch.dmgType;
            wsc.baseDamage = arch.baseDamage;
            wsc.rarity_mod = arch.rarityMod.value_or(1.0f); // optional<float>
            wsc.scaling    = arch.scaling;
            wsc.grantedAbilities  = arch.weaponAbilities;
            reg.emplace<WeaponStatsComponent>(e, std::move(wsc));
        }
        // Armor stats
        else if (arch.kind == ItemKind::Armor) {
            ArmorStatsComponent asc;
            asc.armorClass  = arch.armorClass;
            asc.armorType   = arch.armorType;
            asc.baseDefense = arch.baseDefense;
            asc.rarity_mod  = arch.rarityMod.value_or(1.0f);
            asc.grantedAbilities   = arch.armorAbilities;
            reg.emplace<ArmorStatsComponent>(e, std::move(asc));
        }
    }

private:

    static ItemKind parseKind(const std::string& s) {
        if (s == "Weapon")     return ItemKind::Weapon;
        if (s == "Armor")      return ItemKind::Armor;
        if (s == "Consumable") return ItemKind::Consumable;
        if (s == "Key Item")   return ItemKind::KeyItem;
        throw std::runtime_error("Bad Item Kind: " + s);
    }

    static WeaponType parseWeaponType(const std::string& s) {
        if (s == "Dagger")       return WeaponType::Dagger;
        if (s == "Short Sword")  return WeaponType::ShortSword;
        if (s == "Medium Sword") return WeaponType::MediumSword;
        if (s == "Long Sword")   return WeaponType::LongSword;
        if (s == "Battle Axe")   return WeaponType::BattleAxe;
        if (s == "War Hammer")   return WeaponType::WarHammer;
        if (s == "Short Bow")    return WeaponType::ShortBow;
        if (s == "Long Bow")     return WeaponType::LongBow;
        if (s == "Cross Bow")    return WeaponType::CrossBow;
        throw std::runtime_error("Bad Weapon Type: " + s);
    }

    static Handling parseHandling(const std::string& s) {
        if (s == "One Handed") return Handling::OneHanded;
        if (s == "Two Handed") return Handling::TwoHanded;
        throw std::runtime_error("Bad Handling: " + s);
    }

    static DmgType parseDamageType(const std::string& s) {
        if (s == "Slashing") return DmgType::Slashing;
        if (s == "Piercing") return DmgType::Piercing;
        if (s == "Blunt")    return DmgType::Blunt;
        if (s == "Ranged")   return DmgType::Ranged;
        if (s == "Magic")    return DmgType::Magic;
        throw std::runtime_error("Bad DamageType: " + s);
    }

    static ArmorClass parseArmorClass(const std::string& s) {
        if (s == "Light Armor")  return ArmorClass::LightArmor;
        if (s == "Medium Armor") return ArmorClass::MediumArmor;
        if (s == "Heavy Armor")  return ArmorClass::HeavyArmor;
        throw std::runtime_error("Bad ArmorClass: " + s);
    }

    static ArmorType parseArmorType(const std::string& s) {
        if (s == "Head")  return ArmorType::Head;
        if (s == "Chest") return ArmorType::Chest;
        if (s == "Waist") return ArmorType::Waist;
        if (s == "Legs")  return ArmorType::Legs;
        if (s == "Arms")  return ArmorType::Arms;
        if (s == "Feet")  return ArmorType::Feet;
        throw std::runtime_error("Bad ArmorType: " + s);
    }

    // static AbilityID parseAbility(const std::string& s) {
    //     if (s == "None")             return AbilityID::None;
    //
    //     // --- Damage-over-time / Debuffs ---
    //     if (s == "Searing Wound")    return AbilityID::SearingWound;
    //     if (s == "Crippling Venom")  return AbilityID::CripplingVenom;
    //     if (s == "Ashen Burn")       return AbilityID::AshenBurn;
    //     if (s == "Festering Rot")    return AbilityID::FesteringRot;
    //     if (s == "Soul Bleed")       return AbilityID::SoulBleed;
    //
    //     // --- Buffs / Blessings ---
    //     if (s == "Quick Step")       return AbilityID::QuickStep;
    //     if (s == "Iron Skin")        return AbilityID::IronSkin;
    //     if (s == "Battle Trance")    return AbilityID::BattleTrance;
    //     if (s == "Ward of Light")    return AbilityID::WardOfLight;
    //     if (s == "Stoneform")        return AbilityID::Stoneform;
    //     if (s == "Arcane Focus")     return AbilityID::ArcaneFocus;
    //
    //     // --- Healing / Restoration ---
    //     if (s == "Renewing Grace")   return AbilityID::RenewingGrace;
    //     if (s == "Vital Surge")      return AbilityID::VitalSurge;
    //     if (s == "Blessed Mending")  return AbilityID::BlessedMending;
    //     if (s == "Spirit Bloom")     return AbilityID::SpiritBloom;
    //     if (s == "Second Wind")      return AbilityID::SecondWind;
    //
    //     // --- Utility / Control ---
    //     if (s == "Chains of Dread")  return AbilityID::ChainsOfDread;
    //     if (s == "Mind Shatter")     return AbilityID::MindShatter;
    //     if (s == "Frost Shackles")   return AbilityID::FrostShackles;
    //     if (s == "Echoing Fear")     return AbilityID::EchoingFear;
    //     if (s == "Staggering Blow")  return AbilityID::StaggeringBlow;
    //
    //     // --- Exotic / Flavorful ---
    //     if (s == "Dark Gift")        return AbilityID::DarkGift;
    //     if (s == "Phoenix Ember")    return AbilityID::PhoenixEmber;
    //     if (s == "Mirror Veil")      return AbilityID::MirrorVeil;
    //     if (s == "Blood Pact")       return AbilityID::BloodPact;
    //     if (s == "Ethereal Step")    return AbilityID::EtherealStep;
    //
    //     throw std::runtime_error("Unknown ability: " + s);
    // }

    static EffectID parseEffectID(const std::string& s) {
        if (s == "None")            return EffectID::None;

        // --- Damage / DoT ---
        if (s == "Damage")          return EffectID::Damage;
        if (s == "Poison")          return EffectID::Poison;
        if (s == "Bleed")           return EffectID::Bleed;
        if (s == "Burn")            return EffectID::Burn;
        if (s == "Scald")           return EffectID::Scald;

        // --- Crowd Control ---
        if (s == "Stun")            return EffectID::Stun;
        if (s == "Fear")            return EffectID::Fear;
        if (s == "Root")            return EffectID::Root;
        if (s == "Silence")         return EffectID::Silence;
        if (s == "Slow")            return EffectID::Slow;

        // --- Healing / Restoration ---
        if (s == "Heal")            return EffectID::Heal;
        if (s == "ManaRestore")     return EffectID::ManaRestore;
        if (s == "StaminaRestore")  return EffectID::StaminaRestore;

        // --- Stat Modifiers ---
        if (s == "DamageBonus")     return EffectID::DamageBonus;
        if (s == "ArmorBonus")      return EffectID::ArmorBonus;
        if (s == "StrengthBonus")   return EffectID::StrengthBonus;
        if (s == "SpeedBonus")      return EffectID::SpeedBonus;
        if (s == "IntellectBonus")  return EffectID::IntellectBonus;
        if (s == "ResistanceBonus") return EffectID::ResistanceBonus;
        if (s == "StaminaBonus")    return EffectID::StaminaBonus;
        if (s == "FocusBonus")      return EffectID::FocusBonus;

        // --- Utility / Meta ---
        if (s == "Cleanse")         return EffectID::Cleanse;
        if (s == "Shield")          return EffectID::Shield;
        if (s == "Reflect")         return EffectID::Reflect;
        if (s == "Summon")          return EffectID::Summon;
        if (s == "Trigger")         return EffectID::Trigger;

        throw std::runtime_error("Unknown effect: " + s);
    }
};

template<typename T>
void printGrantedAbilities(entt::entity e, entt::registry& reg) {
    auto& id = reg.get<ItemComponent>(e);
    std::cout << id.name << "'s granted abilities:" << std::endl;
    if constexpr (std::is_same_v<T, ArmorStatsComponent>) {
        // T is ArmorStatsComponent, so get that component
        auto& comp = reg.get<ArmorStatsComponent>(e);
        for (const auto& ability : comp.grantedAbilities) {
            std::cout << abilityId2String(ability) << std::endl;
        }
    } else if constexpr (std::is_same_v<T, WeaponStatsComponent>) {
        // T is WeaponStatsComponent, so get that component
        auto& comp = reg.get<WeaponStatsComponent>(e);
        for (const auto& ability : comp.grantedAbilities) {
            std::cout << abilityId2String(ability) << std::endl;
        }
    }
    std::cout << "\n";
    return;
}
