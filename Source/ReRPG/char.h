// ReSharper restore All

#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <functional>
#include <entt/entt.hpp>
#include <nlohmann/json.hpp>
#include "TransformComponent.h"
#include "component.h"
#include "item.h"
#include "effects.h"
#include "armor.h"


enum class EAttribute {
    Strength,
    Dexterity,
    Endurance,
    BaseSpeed,
    Luck,
    Intelligence,
    Light,
    Dark,
    Focus,
    Presence
};


enum class ECharClass {
    Warrior,
    Mage,
    Rogue,
    Brute,
    Archer
};



struct CharArchetype {
    int strength;
    int dexterity;
    int endurance;
    int baseSpeed;
    int luck;
    int intelligence;
    int light;
    int dark;
    int focus;
    int presence;
};


class CharFactory {

public:
    inline static std::unordered_map<ECharClass, CharArchetype> CharArchetypes;

    inline static nlohmann::json ItemData;

    static void Load(const std::string& Filename) {
        std::ifstream File(Filename);
        if (!File.is_open()) {
            throw std::runtime_error("Failed to open " + Filename);
        }

        nlohmann::json Data;
        File >> Data;

        
        for (auto& [key, value] :  Data.items()) {
            ECharClass Id;
            try {
                Id = CharClassFromString(key).value();
            } catch (const std::bad_optional_access&) {
                throw std::runtime_error("Failed to parse CharClass '" + key + "' from JSON.");
            }
            CharArchetype Arch;
            Arch.strength = value["strength"];
            Arch.dexterity = value["dexterity"];
            Arch.endurance = value["endurance"];
            Arch.baseSpeed = value["base_speed"];
            Arch.luck = value["luck"];
            Arch.intelligence = value["intelligence"];
            Arch.light = value["dark"];
            Arch.dark = value["dark"];
            Arch.focus = value["focus"];
            Arch.presence = value["presence"];


            CharArchetypes[Id] = std::move(Arch);
        }
    }

    static entt::entity Create(entt::registry &Reg, std::string Name, ECharClass CharClass, int X, int Y) {
  
        entt::entity E = Reg.create();
        Reg.emplace<IdentityComponent>(E, Name, CharClass);
        Reg.emplace<ResourceComponent>(E, 100,100,100,100,100,100);
        Reg.emplace<InventoryComponent>(E);
        inventory_init(E, Reg);
        Reg.emplace<ActiveEffects>(E);
        Reg.emplace<ProgressionComponent>(E);

        Reg.emplace<TransformComponent>(E);
        // auto&Pos = Reg.get<TransformComponent>(E);
        // Pos.vec.x = X;
        // Pos.vec.y = Y;

        Reg.emplace<StatusComponent>(E);
        Reg.emplace<MagicComponent>(E);
        Reg.emplace<CombatStatsComponent>(E);

        // Character Class archetypes set initial attr level 
        Reg.emplace<AttributesComponent>(E);
        auto& Attr = Reg.get<AttributesComponent>(E);
        auto const It = CharArchetypes.find(CharClass);
        if (It == CharArchetypes.end()) {
            throw std::runtime_error("Unknown Character class");
        }
        const CharArchetype &Arch = It->second;

        Attr.strength = Arch.strength;
        Attr.dexterity = Arch.dexterity;
        Attr.endurance = Arch.endurance;
        Attr.base_speed = Arch.baseSpeed;
        Attr.luck = Arch.luck;
        Attr.intelligence = Arch.intelligence;
        Attr.light = Arch.light;
        Attr.dark = Arch.dark;
        Attr.focus = Arch.focus;
        Attr.presence = Arch.presence;

        recalculateResources(E, Reg);
        return E;
    }
private:
    static std::optional<ECharClass>  CharClassFromString(const std::string& s) {
    if (s == "Warrior") return ECharClass::Warrior;
    if (s == "Mage") return ECharClass::Mage;
    if (s == "Archer") return ECharClass::Archer;
    if (s == "Brute") return ECharClass::Brute;
    if (s == "Rogue") return ECharClass::Rogue;
    throw std::runtime_error("Bad Character Class: " + s);
    }
};


void PrintAttributes(const entt::entity e, entt::registry &reg);

void PrintEquipped(const entt::entity e, entt::registry &reg);

void PrintResources(const entt::entity e, entt::registry &reg);

void PrintConsumables(const entt::entity e, entt::registry &reg);

//void GetPosition(const entt::entity e, entt::registry &reg); 

void GiveItem(const entt::entity e, entt::registry &reg, ItemID id, int quantity = 1);

EAttribute String2Attribute(const std::string s);

std::string Attribute2String(const EAttribute attr);
