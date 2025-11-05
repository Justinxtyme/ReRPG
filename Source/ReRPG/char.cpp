//#include "char.h"
#include "char.h"
#include "itemfactory.h"
#include <iostream>

/* TODO: Implement Scaling logic from weapons and/or armor */

void PrintAttributes(const entt::entity e, entt::registry &reg) {
    auto& Id = reg.get<IdentityComponent>(e);
    auto& Attr = reg.get<AttributesComponent>(e);
    std::cout << Id.name << "'s attributes:\n"
    << "Strength: " << Attr.strength << "\n"
    << "Dexterity: " << Attr.dexterity << "\n"
    << "Endurance: " << Attr.endurance << "\n"
    << "Intelligence: " << Attr.intelligence << "\n"
    << "Speed: " << Attr.base_speed << "\n"
    << "Focus: " << Attr.focus << "\n"
    << "Presence: " << Attr.presence << "\n"
    << "Luck: " << Attr.luck << "\n\n";
    
}

void PrintEquipped(const entt::entity e, entt::registry &reg) {
    auto&Inv = reg.get<InventoryComponent>(e);
    IdentityComponent& Id = reg.get<IdentityComponent>(e);
    std::cout << Id.name << "'s Equipped items: \n";
    for (auto &[slot, armorEntity] : Inv.armor) {
        if (armorEntity != entt::null) {
            // The entity ID of the equipped armor piece
            std::cout << "Slot " << slot2string(slot)
                    << " has armor entity " << (int)armorEntity << "\n";

            // If you want to print details of the armor itself:
            if (reg.any_of<ArmorStatsComponent>(armorEntity)) {
                auto const &ArmorComp = reg.get<ArmorStatsComponent>(armorEntity);
                auto &Info = reg.get<ItemComponent>(armorEntity);
                std::cout << "  Armor name: " << Info.name
                        << " | Defense: " << ArmorComp.baseDefense << "\n";
            }
        } else {
            std::cout << "Slot " << slot2string(slot) << " is empty\n";
        }
    }
    std::cout << "\n";
}

void PrintResources(const entt::entity e, entt::registry &reg) {
    auto& Res = reg.get<ResourceComponent>(e);
    auto& Id = reg.get<IdentityComponent>(e);

    std::cout << Id.name << "'s Resources: \n" 
    << "Max hp: " << Res.max_hp << "\n"
    << "Max sp: " << Res.max_sp << "\n"
    << "Max mp: " << Res.max_mp << "\n\n";
}

void PrintConsumables(const entt::entity e, entt::registry &reg) {
    auto& Inv = reg.get<InventoryComponent>(e);
    auto& Id = reg.get<IdentityComponent>(e);
    if (Inv.stackables.empty()) {
        std::cout << Id.name << "has no consumables." << std::endl;
        return;
    }
    std::cout << Id.name << "'s consumables: " << std::endl;
    for (const auto& pair : Inv.stackables) {
        std::cout << "Item: " << item2string(pair.first) << ", Quantity: " << pair.second 
         << std::endl;
    }
    std::cout << "\n";
}


//void GetPosition(const entt::entity e, entt::registry &reg) {
//    auto& loc = reg.get<TransformComponent>(e);
//    auto& id = reg.get<IdentityComponent>(e);
//
//    std::cout << id.name << "'s Position is: "
//    << loc.vec.x << ", " << loc.vec.y << "\n";
//
//}

void GiveItem(const entt::entity e, entt::registry &reg, ItemID id, int quantity) {
    auto&inv = reg.get<InventoryComponent>(e);
    if (!inv.stackables[id]) {
        inv.stackables[id] = quantity;
    }
    else {
        inv.stackables[id] += quantity;
    } 
}


EAttribute String2Attribute(const std::string s) {
    if (s == "Strength")      return EAttribute::Strength;
    if (s == "Dexterity")     return EAttribute::Dexterity;
    if (s == "Endurance")     return EAttribute::Endurance;
    if (s == "BaseSpeed")     return EAttribute::BaseSpeed;
    if (s == "Luck")          return EAttribute::Luck;
    if (s == "Intelligence")  return EAttribute::Intelligence;
    if (s == "Light")         return EAttribute::Light;
    if (s == "Dark")          return EAttribute::Dark;
    if (s == "Focus")         return EAttribute::Focus;
    if (s == "Presence")      return EAttribute::Presence;

    throw std::runtime_error("Bad Attribute Type: " + s);
}

std::string Attribute2String(const EAttribute attr) {
    switch (attr) {
        case EAttribute::Strength:      return "Strength";
        case EAttribute::Dexterity:     return "Dexterity";
        case EAttribute::Endurance:     return "Endurance";
        case EAttribute::BaseSpeed:     return "BaseSpeed";
        case EAttribute::Luck:          return "Luck";
        case EAttribute::Intelligence:  return "Intelligence";
        case EAttribute::Light:         return "Light";
        case EAttribute::Dark:          return "Dark";
        case EAttribute::Focus:         return "Focus";
        case EAttribute::Presence:      return "Presence";
    }
    throw std::runtime_error("Bad Attribute Type");
}
