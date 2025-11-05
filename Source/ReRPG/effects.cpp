#include "effects.h"
#include "component.h"


/* TODO: Implement attribute scaling into effect logic */

std::unordered_map<EffectID, EffectFn> make_effect_table() {
    std::unordered_map<EffectID, EffectFn> table;

    // --- Damage / DoT ---
    table[EffectID::Damage] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int dmg = eff.magnitude;
        res.hp = std::max(0, res.hp - dmg);
    };

    table[EffectID::Poison] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int dmg = eff.magnitude;
        res.hp = std::max(0, res.hp - dmg);
    };

    table[EffectID::Bleed] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int dmg = eff.magnitude;
        res.hp = std::max(0, res.hp - dmg);
    };

    table[EffectID::Burn] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int dmg = eff.magnitude;
        res.hp = std::max(0, res.hp - dmg);
    };

    table[EffectID::Scald] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int dmg = eff.magnitude;
        res.hp = std::max(0, res.hp - dmg);
    };

    // // --- Crowd Control ---
    // table[EffectID::Stun] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // apply stun status
    // };

    // table[EffectID::Fear] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // apply fear status
    // };

    // table[EffectID::Root] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // apply root/immobilize
    // };

    // table[EffectID::Silence] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // apply silence
    // };

    // table[EffectID::Slow] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // apply slow
    // };

    // --- Healing / Restoration ---
    table[EffectID::Heal] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int heal = eff.magnitude; 
        res.hp = std::min(res.max_hp, res.hp + heal);
    };

    table[EffectID::ManaRestore] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int restore = eff.magnitude; 
        res.mp = std::min(res.max_mp, res.mp + restore);
    };

    table[EffectID::StaminaRestore] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &res = reg.get<ResourceComponent>(e);
        const int restore = eff.magnitude; 
        res.sp = std::min(res.max_sp, res.sp + restore);
    };

    // --- Stat Modifiers ---
    table[EffectID::DamageBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto&res = reg.get<WeaponStatsComponent>(e);
        res.damage += eff.magnitude;

    };

    table[EffectID::ArmorBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto&res = reg.get<ArmorStatsComponent>(e);
        res.baseDefense += eff.magnitude;
    };

    table[EffectID::StrengthBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &attr = reg.get<AttributesComponent>(e);
        attr.strength += eff.magnitude;
    };

    table[EffectID::SpeedBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &attr = reg.get<AttributesComponent>(e);
        attr.base_speed += eff.magnitude;
    };

    table[EffectID::IntellectBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &attr = reg.get<AttributesComponent>(e);
        attr.intelligence += eff.magnitude;
    };

    table[EffectID::ResistanceBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &attr = reg.get<AttributesComponent>(e);
        attr.endurance += eff.magnitude;
    };

    table[EffectID::StaminaBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &attr = reg.get<ResourceComponent>(e);
        attr.sp += eff.magnitude;
    };

    table[EffectID::FocusBonus] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
        auto &attr = reg.get<AttributesComponent>(e);
        attr.focus += eff.magnitude;
    };

    // // --- Utility / Meta ---
    // table[EffectID::Cleanse] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // remove debuffs
    // };

    // table[EffectID::Shield] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // apply shield/temporary HP
    // };

    // table[EffectID::Reflect] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // reflect damage
    // };

    // table[EffectID::Summon] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // summon entity
    // };

    // table[EffectID::Trigger] = [](entt::entity e, entt::registry &reg, EffectComponent &eff) {
    //     // trigger another effect
    // };

    return table;
}


std::string effect2string(EffectID effect) {
    switch (effect) {
        case EffectID::None:            return "None";

        // --- Damage / DoT ---
        case EffectID::Damage:          return "Damage";
        case EffectID::Poison:          return "Poison";
        case EffectID::Bleed:           return "Bleed";
        case EffectID::Burn:            return "Burn";
        case EffectID::Scald:           return "Scald";

        // --- Crowd Control ---
        case EffectID::Stun:            return "Stun";
        case EffectID::Fear:            return "Fear";
        case EffectID::Root:            return "Root";
        case EffectID::Silence:         return "Silence";
        case EffectID::Slow:            return "Slow";

        // --- Healing / Restoration ---
        case EffectID::Heal:            return "Heal";
        case EffectID::ManaRestore:     return "Mana Restore";
        case EffectID::StaminaRestore:  return "Stamina Restore";

        // --- Stat Modifiers ---
        case EffectID::DamageBonus:     return "Damage Bonus";
        case EffectID::ArmorBonus:      return "Armor Bonus";
        case EffectID::StrengthBonus:   return "Strength Bonus";
        case EffectID::SpeedBonus:      return "Speed Bonus";
        case EffectID::IntellectBonus:  return "Intellect Bonus";
        case EffectID::StaminaBonus:    return "Focus Bonus";
        case EffectID::ResistanceBonus: return "Resistance Bonus";
        case EffectID::FocusBonus:      return "Focus Bonus";

        // --- Utility / Meta ---
        case EffectID::Cleanse:         return "Cleanse";
        case EffectID::Shield:          return "Shield";
        case EffectID::Reflect:         return "Reflect";
        case EffectID::Summon:          return "Summon";
        case EffectID::Trigger:         return "Trigger";
    }

    throw std::runtime_error("Bad EffectID");
}


void tick_effects(entt::entity target,
                  std::vector<EffectComponent> &activeEffects,
                  entt::registry &reg,
                  const std::unordered_map<EffectID, EffectFn> &table) {
    for (auto it = activeEffects.begin(); it != activeEffects.end(); ) {
        auto &eff = *it;

        // Only tick non‑instant effects
        if (eff.duration > 0 /* or eff.kind == OverTime */) {
            if (auto fn = table.find(eff.id); fn != table.end()) {
                fn->second(target, reg, eff);
            }

            if (--eff.duration <= 0) {
                it = activeEffects.erase(it);
                continue;
            }
        }

        ++it;
    }
}

void apply_instant_effects(entt::entity target,
                           const std::vector<EffectComponent> &effects,
                           entt::registry &reg,
                           const std::unordered_map<EffectID, EffectFn> &table) {
    for (auto &eff : effects) {
        if (eff.duration == 0 /* or eff.kind == Instant */) {
            if (auto it = table.find(eff.id); it != table.end()) {
                // Apply once; do not mutate eff or add to activeEffects
                it->second(target, reg, const_cast<EffectComponent &>(eff));
            }
        }
    }
}
