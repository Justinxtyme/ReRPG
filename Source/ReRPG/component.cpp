// component.cpp
#include "component.h"
#include <cassert>
#include <cstring>
#include <vector>

//#include "effects.h"


void inventory_init(entt::entity e, entt::registry &reg) {
    auto& res = reg.get<InventoryComponent>(e);
    res.armor.emplace(ArmorType::Head,  entt::null);
    res.armor.emplace(ArmorType::Chest, entt::null);
    res.armor.emplace(ArmorType::Arms,  entt::null);
    res.armor.emplace(ArmorType::Waist, entt::null);
    res.armor.emplace(ArmorType::Legs,  entt::null);
    res.armor.emplace(ArmorType::Feet,  entt::null);

    res.weapons.emplace(WeaponSlot::MainHand, entt::null);
    res.weapons.emplace(WeaponSlot::OffHand,  entt::null);
}


// //NOT FINISHED
// void resource_init(entt::entity e, entt::registry &reg) {
//     auto& id = reg.get<IdentityComponent>(e);
//     auto& res = reg.get<ResourceComponent>(e);



// }


void recalculateResources( entt::entity e, entt::registry &reg) {
    auto& res = reg.get<ResourceComponent>(e);
    auto& attrs = reg.get<AttributesComponent>(e);
    res.max_hp += (attrs.strength     * 0.20f);
    res.max_sp += (attrs.endurance    * 0.25f);
    res.max_mp += (attrs.intelligence * 0.20f);
    // clamp current values if needed
    res.hp = std::min(res.hp, res.max_hp);
    res.sp = std::min(res.sp, res.max_sp);
    res.mp = std::min(res.mp, res.max_mp);
}


void TakeDamage(entt::registry &reg, entt::entity e, int amount) {
    auto& res = reg.get<ResourceComponent>(e);
    res.hp = std::max(0, res.hp - amount);
}

void Heal(entt::registry &reg, entt::entity e, int amount) {
    auto& res = reg.get<ResourceComponent>(e);
    res.hp = std::min(res.max_hp, res.hp + amount);
}

// void StatusComponent::Inert() { 
//     stunned = true; 
// }

// void StatusComponent::Tick() {
//     if (stun_duration > 0) {
//         stun_duration--;
//         if (stun_duration == 0) stunned = false;
//     }
// }

// bool StatusComponent::IsStunned() const { 
//     return stunned; 
// }

// void TransformComponent::move(float dx, float dy) {
//     position.x += dx;
//     position.y += dy;
// }

// void TransformComponent::set(float x, float y) {
//     position.x = x;
//     position.y = y;
// }
