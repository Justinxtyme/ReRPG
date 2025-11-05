#pragma once

#include "power.h"
#include <vector>
#include <unordered_map>
#include <entt/entt.hpp>

enum class EffectID {
    None = 0,
    // --- Damage / DoT ---
    Damage,
    Poison,
    Bleed,
    Burn,
    Scald,
    // --- Crowd Control ---
    Stun,
    Fear,
    Root,
    Silence,
    Slow,
    // --- Healing / Restoration ---
    Heal,
    ManaRestore,
    StaminaRestore,
    // --- Stat Modifiers ---
    DamageBonus,
    ArmorBonus,
    StrengthBonus,
    SpeedBonus,
    IntellectBonus,
    ResistanceBonus,
    StaminaBonus,
    FocusBonus,
    // --- Utility / Meta ---
    Cleanse,
    Shield,
    Reflect,
    Summon,
    Trigger
};

std::string effect2string(EffectID effect);

enum class EffectKind {
    Instant,
    OverTime,
    Passive
};

struct EffectComponent {
    AbilityID  source;
    EffectID   id;
    EffectKind kind;
    int        magnitude;
    int        duration;
    bool       stunned = false;
};



struct ActiveEffects {
    std::vector<EffectComponent> effects;
};

struct AbilityComponent {
    std::string name;
    std::string desc;
    std::vector<EffectComponent> effects;
};



enum class Effects {
    None,
    Fire,
    Poison,
    Bleed,
    Magic
};


using EffectFn = std::function<void(entt::entity, entt::registry&, EffectComponent&)>;
std::unordered_map<EffectID, EffectFn> make_effect_table();

void tick_effects(entt::entity target,
                  std::vector<EffectComponent> &activeEffects,
                  entt::registry &reg,
                  const std::unordered_map<EffectID, EffectFn> &table);


void apply_instant_effects(entt::entity target,
                           const std::vector<EffectComponent> &effects,
                           entt::registry &reg,
                           const std::unordered_map<EffectID, EffectFn> &table);

