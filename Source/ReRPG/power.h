#pragma once

#include <string>
#include "UObject/Object.h"

enum class AbilityID {
    None = 0,

    // --- Damage-over-time / Debuffs ---
    SearingWound,
    CripplingVenom,
    AshenBurn,
    FesteringRot,
    SoulBleed,

    // --- Buffs / Blessings ---
    QuickStep,       // +Speed/dexterity 
    IronSkin,        // +Armor
    BattleTrance,    // +Strength/Endurance
    WardOfLight,     // Resist Fear/Stun
    Stoneform,       // Temporary Damage Reduction
    ArcaneFocus,     // +Focus/Intelligence/mp

    // --- Healing / Restoration ---
    RenewingGrace,   // Heal over Time
    VitalSurge,      // Instant Heal
    BlessedMending,  // Hybrid heal + cleanse
    SpiritBloom,     // Regenerate mana/energy
    SecondWind,      // Heal on low HP trigger

    // --- Utility / Control ---
    ChainsOfDread,   // Root/Immobilize
    MindShatter,     // Silence
    FrostShackles,   // Slow
    EchoingFear,     // AoE panic
    StaggeringBlow,  // Stun

    // --- Exotic / Flavorful ---
    DarkGift,        // HoT with drawback
    PhoenixEmber,    // Revive on death
    MirrorVeil,      // Reflect damage
    BloodPact,       // Trade HP for power
    EtherealStep     // Phase through attacks
};


enum class Spell {

};



std::string abilityId2String(AbilityID id);

AbilityID parseAbility(const std::string& s);
AbilityID FparseAbility(const FName& s);
