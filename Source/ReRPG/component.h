//component.h
#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <entt/entt.hpp>
#include "armor.h"
#include "weapon.h"




enum class ECharClass;

enum class EffectID;

enum class Spell;


struct IdentityComponent {
    std::string name;
    ECharClass charClass; 
};


struct ProgressionComponent {
    int level = 1;
    int exp   = 0;
};


struct CombatStatsComponent {
    int attack;
    int defense;
    int accuracy;
    int evasion;
};


struct AttributesComponent {
    int strength;
    int dexterity;
    int endurance;
    int base_speed;
    int luck;
    int intelligence;
    int light;
    int dark;
    int focus;
    int presence;
    
};


struct ResourceComponent {
    int hp;
    int sp;
    int mp;
    int max_hp;
    int max_sp;
    int max_mp;
};


struct ItemComponent {
    ItemID       id;          // archetype key
    std::string  name;   // maybe cached from data
    float        weight;
    std::vector<EffectID> effects;
};


struct InventoryComponent {
    // Stackables: ItemID → count
    std::unordered_map<ItemID, int> stackables;

    // Equipped armor: slot → entity ID (or INVALID_ID if empty)
    std::unordered_map<ArmorType, entt::entity> armor;

    // Equipped weapons: slot → entity ID (or INVALID_ID if empty)
    std::unordered_map<WeaponSlot, entt::entity> weapons;  
};


// struct ItemComponent {
//     ItemID       id;          // archetype key
//     std::string  name;   // maybe cached from data
//     float        weight;
//     std::vector<EffectID> effects;
// };



struct ArmorStatsComponent {
    ArmorClass  armorClass;
    ArmorType   armorType;
    int         baseDefense; 
    float       rarity_mod;
    std::vector<AbilityID> grantedAbilities;
};

// struct UseEffectComponent {
//     std::vector<Effects> effects;
//     enum class UseKind {          // optional discriminator
//         Consumable,
//         KeyItem
//     } kind;
// };



struct StatusComponent {
    bool stunned = false;
    int stun_duration = 0;
};



// struct MovementComponent : public Component {
//     float speed;
// };

// // struct AIComponent : public Component {
// //     void updateAI(Entity& self);
// // };

struct MagicComponent {
    std::vector<Spell> spellbook;
};

void inventory_init(entt::entity e, entt::registry &reg);

void recalculateResources(entt::entity e, entt::registry &reg);

void TakeDamage(entt::registry &reg, entt::entity e, int amount);

void Heal(entt::registry &reg, entt::entity e, int amount);