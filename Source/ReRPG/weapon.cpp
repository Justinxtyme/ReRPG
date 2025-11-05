// weapon.cpp
#include "weapon.h"
#include "effects.h"
#include "component.h"
#include <iostream>
#include <type_traits> // For std::is_same_v


std::string weaponType2String(WeaponType type) {
    switch (type) {
        case WeaponType::Dagger:      return "Dagger";
        case WeaponType::ShortSword:  return "ShortSword";
        case WeaponType::MediumSword: return "MediumSword";
        case WeaponType::LongSword:   return "LongSword";
        case WeaponType::BattleAxe:   return "BattleAxe";
        case WeaponType::WarHammer:   return "WarHammer";
        case WeaponType::ShortBow:    return "ShortBow";
        case WeaponType::LongBow:     return "LongBow";
        case WeaponType::CrossBow:    return "CrossBow";
    }
    throw std::runtime_error("Unknown Weapon Type");
}

std::string weaponHandling2String(Handling handle) {
    switch (handle) {
        case Handling::OneHanded: return "One Handed";
        case Handling::TwoHanded: return "Two Handed";
    }
    throw std::runtime_error("Unknown Handling Type");
}

std::string damageType2String(DmgType dmg) {
    switch (dmg) {
        case DmgType::Slashing: return "Slashing";
        case DmgType::Piercing: return "Piercing";
        case DmgType::Blunt: return "Blunt";
        case DmgType::Ranged: return "Ranged";
        case DmgType::Magic: return "Magic";
    }
    throw std::runtime_error("Unknown Handling Type");
}

void printWeapInfo(entt::entity weap, entt::registry &reg) {
    auto&id = reg.get<ItemComponent>(weap);
    auto&stats = reg.get<WeaponStatsComponent>(weap);
    std::cout << item2string(id.id) << "'s stats: \n"
    << "Weapon Type: " << weaponType2String(stats.type) << "\n"
    << "Handling: " << weaponHandling2String(stats.handling) << "\n"
    << "Damage Type: " << damageType2String(stats.dmgType) << "\n"
    << "Base Damage: " << stats.baseDamage << "\n\n";
}

void printWeapEffects(entt::entity e, entt::registry& reg) {
    auto& id = reg.get<ItemComponent>(e);
    if (id.effects.empty()) {
        std::cout << id.name << "has no effects\n";
        return;
    }
    std::cout << id.name << "'s effects: \n";
    for (const auto& effect : id.effects) {
        std::cout << effect2string(effect) << "\n";
    }
    std::cout << "\n";
}



std::string abilityId2String(AbilityID id) {
    switch (id) {
        case AbilityID::None:            return "None";

        // --- Damage-over-time / Debuffs ---
        case AbilityID::SearingWound:    return "Searing Wound";
        case AbilityID::CripplingVenom:  return "Crippling Venom";
        case AbilityID::AshenBurn:       return "Ashen Burn";
        case AbilityID::FesteringRot:    return "Festering Rot";
        case AbilityID::SoulBleed:       return "Soul Bleed";

        // --- Buffs / Blessings ---
        case AbilityID::QuickStep:       return "Quick Step";
        case AbilityID::IronSkin:        return "Iron Skin";
        case AbilityID::BattleTrance:    return "Battle Trance";
        case AbilityID::WardOfLight:     return "Ward of Light";
        case AbilityID::Stoneform:       return "Stoneform";
        case AbilityID::ArcaneFocus:     return "Arcane Focus";

        // --- Healing / Restoration ---
        case AbilityID::RenewingGrace:   return "Renewing Grace";
        case AbilityID::VitalSurge:      return "Vital Surge";
        case AbilityID::BlessedMending:  return "Blessed Mending";
        case AbilityID::SpiritBloom:     return "Spirit Bloom";
        case AbilityID::SecondWind:      return "Second Wind";

        // --- Utility / Control ---
        case AbilityID::ChainsOfDread:   return "Chains of Dread";
        case AbilityID::MindShatter:     return "Mind Shatter";
        case AbilityID::FrostShackles:   return "Frost Shackles";
        case AbilityID::EchoingFear:     return "Echoing Fear";
        case AbilityID::StaggeringBlow:  return "Staggering Blow";

        // --- Exotic / Flavorful ---
        case AbilityID::DarkGift:        return "Dark Gift";
        case AbilityID::PhoenixEmber:    return "Phoenix Ember";
        case AbilityID::MirrorVeil:      return "Mirror Veil";
        case AbilityID::BloodPact:       return "Blood Pact";
        case AbilityID::EtherealStep:    return "Ethereal Step";
    }
    throw std::runtime_error("Unknown Ability");
}