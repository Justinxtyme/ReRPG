#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "item.h"
//#include "char.h"

#include "effects.h"

// Base component interface
class IGrantsComponent {
public:
    virtual ~IGrantsComponent() = default;
};

// Component for items that grant a temporary effect on use
class GrantsEffectComponent : public IGrantsComponent {
public:
    GrantsEffectComponent(Effect* effect) : m_effect(effect) {}
    void OnUse(class Entity* target) {
        m_effect->Apply(target);
    }
private:
    Effect* m_effect;
};

// Component for items that grant a passive or active ability when equipped
class GrantsAbilityComponent : public IGrantsComponent {
public:
    GrantsAbilityComponent(Ability* ability) : m_ability(ability) {}
    void OnEquip(class Entity* character) {
        character->AddAbility(m_ability);
    }
private:
    std::unique_ptr<Ability> m_ability;
};