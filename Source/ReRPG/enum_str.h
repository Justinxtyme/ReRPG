#pragma once
#include "item.h"      // defines ItemID
#include "weapon.h"    // defines WeaponType, WeaponSlot (or put those in a common header)
#include "armor.h"     // defines ArmorType
#include <string>

// Keep these inline in a header to avoid multiple-definition linker errors.

// ItemID -> human readable name
inline std::string to_string(ItemID id) {
    switch (id) {
        // Potions & Elixirs
        case ItemID::WeakPotion:                   return "Weak Health Potion";
        case ItemID::Potion:                       return "Health Potion";
        case ItemID::PotentPotion:                 return "Mana Potion";
        case ItemID::ElixirOfStrength:             return "Elixir of Strength";
        case ItemID::SuperElixir:                  return "Super Elixir";
        case ItemID::ElixirOfDefense:              return "Elixir of Defense";
        case ItemID::PoisonFlask:                  return "Poison Flask";

        // Herbs
        case ItemID::HealingHerb:                  return "Healing Herb";
        case ItemID::StrongHealingHerb:            return "Strong Healing Herb";
        case ItemID::ManaHerb:                     return "Mana Herb";
        case ItemID::StrongManaHerb:               return "Strong Mana Herb";
        case ItemID::StaminaHerb:                  return "Stamina Herb";

        // Elemental Potions & Antidotes
        case ItemID::FirePotion:                   return "Fire Potion";
        case ItemID::FrostPotion:                  return "Frost Potion";
        case ItemID::ShockPotion:                  return "Shock Potion";
        case ItemID::Antidote:                     return "Antidote";
        case ItemID::GreaterAntidote:              return "Greater Antidote";

        // Leather Armor Set
        case ItemID::LeatherHelm:                  return "Leather Helm";
        case ItemID::LeatherCuirass:               return "Leather Cuirass";
        case ItemID::LeatherBoots:                 return "Leather Boots";
        case ItemID::LeatherLeggings:              return "Leather Leggings";
        case ItemID::LeatherVambraces:             return "Leather Vambraces";
        case ItemID::LeatherBelt:                  return "Leather Belt";

        // Reinforced Leather Armor Set
        case ItemID::ReinforcedLeatherHelm:        return "Reinforced Leather Helm";
        case ItemID::ReinforcedLeatherCuirass:     return "Reinforced Leather Cuirass";
        case ItemID::ReinforcedLeatherBoots:       return "Reinforced Leather Boots";
        case ItemID::ReinforcedLeatherLeggings:    return "Reinforced Leather Leggings";
        case ItemID::ReinforcedLeatherVambraces:   return "Reinforced Leather Vambraces";
        case ItemID::ReinforcedLeatherBelt:        return "Reinforced Leather Belt";

        // Hardened Leather Armor Set
        case ItemID::HardenedLeatherHelm:          return "Hardened Leather Helm";
        case ItemID::HardenedLeatherCuirass:       return "Hardened Leather Cuirass";
        case ItemID::HardenedLeatherBoots:         return "Hardened Leather Boots";
        case ItemID::HardenedLeatherLeggings:      return "Hardened Leather Leggings";
        case ItemID::HardenedLeatherVambraces:     return "Hardened Leather Vambraces";
        case ItemID::HardenedLeatherBelt:          return "Hardened Leather Belt";

                // Iron Armor Set
        case ItemID::IronVisor:                    return "Iron Visor";
        case ItemID::IronChestplate:               return "Iron Chestplate";
        case ItemID::IronBoots:                    return "Iron Boots";
        case ItemID::IronGreaves:                  return "Iron Greaves";
        case ItemID::IronArmplates:                return "Iron Armplates";
        case ItemID::IronGirdle:                   return "Iron Girdle";

        // Cloth Armor Set
        case ItemID::ClothHood:                    return "Cloth Hood";
        case ItemID::ClothRobe:                    return "Cloth Robe";
        case ItemID::ClothSandals:                 return "Cloth Sandals";
        case ItemID::ClothTrousers:                return "Cloth Trousers";
        case ItemID::ClothGloves:                  return "Cloth Gloves";
        case ItemID::ClothSash:                    return "Cloth Sash";

        // Blessed Cloth Armor Set
        case ItemID::BlessedClothHood:             return "Blessed Cloth Hood";
        case ItemID::BlessedClothRobe:             return "Blessed Cloth Robe";
        case ItemID::BlessedClothSandals:          return "Blessed Cloth Sandals";
        case ItemID::BlessedClothTrousers:         return "Blessed Cloth Trousers";
        case ItemID::BlessedClothGloves:           return "Blessed Cloth Gloves";
        case ItemID::BlessedClothSash:             return "Blessed Cloth Sash";

        // Silk Armor Set
        case ItemID::SilkHood:                     return "Silk Hood";
        case ItemID::SilkRobe:                     return "Silk Robe";
        case ItemID::SilkSandals:                  return "Silk Sandals";
        case ItemID::SilkTrousers:                 return "Silk Trousers";
        case ItemID::SilkGloves:                   return "Silk Gloves";
        case ItemID::SilkSash:                     return "Silk Sash";

        // Arcane Silk Armor Set
        case ItemID::ArcaneSilkHood:               return "Arcane Silk Hood";
        case ItemID::ArcaneSilkRobe:               return "Arcane Silk Robe";
        case ItemID::ArcaneSilkSandals:            return "Arcane Silk Sandals";
        case ItemID::ArcaneSilkTrousers:           return "Arcane Silk Trousers";
        case ItemID::ArcaneSilkGloves:             return "Arcane Silk Gloves";
        case ItemID::ArcaneSilkSash:               return "Arcane Silk Sash";

        // Mystic Armor Set
        case ItemID::MysticHood:                   return "Mystic Hood";
        case ItemID::MysticRobe:                   return "Mystic Robe";
        case ItemID::MysticSandals:                return "Mystic Sandals";
        case ItemID::MysticTrousers:               return "Mystic Trousers";
        case ItemID::MysticGloves:                 return "Mystic Gloves";
        case ItemID::MysticSash:                   return "Mystic Sash";

                // Eldritch Mystic Armor Set
        case ItemID::EldritchMysticHood:           return "Eldritch Mystic Hood";
        case ItemID::EldritchMysticRobe:           return "Eldritch Mystic Robe";
        case ItemID::EldritchMysticSandals:        return "Eldritch Mystic Sandals";
        case ItemID::EldritchMysticTrousers:       return "Eldritch Mystic Trousers";
        case ItemID::EldritchMysticGloves:         return "Eldritch Mystic Gloves";
        case ItemID::EldritchMysticSash:           return "Eldritch Mystic Sash";

        // Rusted Weapons
        case ItemID::RustedDagger:                 return "Rusted Dagger";
        case ItemID::RustedStraightSword:          return "Rusted Straight Sword";
        case ItemID::RustedGreatSword:             return "Rusted Greatsword";
        case ItemID::OldBroadAxe:                  return "Old Broad Axe";
        case ItemID::RustedFellingAxe:             return "Rusted Felling Axe";

        // Iron Weapons
        case ItemID::IronDagger:                   return "Iron Dagger";
        case ItemID::IronStraightSword:            return "Iron Straight Sword";
        case ItemID::IronGreatsword:               return "Iron Greatsword";

        // Miscellaneous
        case ItemID::BloodStone:                   return "Blood Stone";

        // Steel Armor Set
        case ItemID::SteelVisor:                   return "Steel Visor";
        case ItemID::SteelChestplate:              return "Steel Chestplate";
        case ItemID::SteelBoots:                   return "Steel Boots";
        case ItemID::SteelGreaves:                 return "Steel Greaves";
        case ItemID::SteelArmplates:               return "Steel Armplates";
        case ItemID::SteelGirdle:                  return "Steel Girdle";
 
        // Steel Weapons
        case ItemID::SteelDagger:                  return "Steel Dagger";
        case ItemID::SteelStraightSword:           return "Steel Straight Sword";
        case ItemID::SteelGreatsword:              return "Steel Greatsword";
        case ItemID::SteelBroadAxe:                return "Steel Broad Axe";
        case ItemID::SteelFellingAxe:              return "Steel Felling Axe";

        // Mithril Armor Set
        case ItemID::MithrilVisor:                 return "Mithril Visor";
        case ItemID::MithrilChestplate:            return "Mithril Chestplate";
        case ItemID::MithrilBoots:                 return "Mithril Boots";
        case ItemID::MithrilGreaves:               return "Mithril Greaves";
        case ItemID::MithrilArmplates:             return "Mithril Armplates";
        case ItemID::MithrilGirdle:                return "Mithril Girdle";

        // Mithril Weapons
        case ItemID::MithrilDagger:                return "Mithril Dagger";
        case ItemID::MithrilStraightSword:         return "Mithril Straight Sword";
        case ItemID::MithrilGreatsword:            return "Mithril Greatsword";
        case ItemID::MithrilBroadAxe:              return "Mithril Broad Axe";
        case ItemID::MithrilFellingAxe:            return "Mithril Felling Axe";

        // Bone Armor Set
        case ::BoneHelm:                     return "Bone Helm";
        case ::BoneCuirass:                  return "Bone Cuirass";
        case ItemID::BoneBoots:                    return "Bone Boots";
        case ItemID::BoneLeggings:                 return "Bone Leggings";
        case ItemID::BoneVambraces:                return "Bone Vambraces";
        case ItemID::BoneBelt:                     return "Bone Belt";

        // Magical Artifacts
        case ItemID::AncientRelic:                 return "Ancient Relic";
        case ItemID::CursedAmulet:                 return "Cursed Amulet";
        case ItemID::BlessedCharm:                 return "Blessed Charm";
        case ItemID::BloodAmulet:                  return "Blood Amulet";
        case ItemID::StoneOfFortune:               return "Stone of Fortune";
        case ItemID::StoneOfCurses:                return "Stone of Curses";


        default: return "Unknown Item";
    }
}
// ArmorType -> slot name
inline std::string to_string(ArmorType type) {
    switch (type) {
        case ArmorType::Head:  return "Head";
        case ArmorType::Chest: return "Chest";
        case ArmorType::Arms:  return "Arms";
        case ArmorType::Waist: return "Waist";
        case ArmorType::Legs:  return "Legs";
        case ArmorType::Feet:  return "Feet";
        default: return "Unknown Armor Slot";
    }
}

// WeaponSlot -> slot name
inline std::string to_string(WeaponSlot slot) {
    switch (slot) {
        case WeaponSlot::MainHand:  return "Main Hand";
        case WeaponSlot::OffHand:   return "Off Hand";
        case WeaponSlot::TwoHand:   return "Two-Handed";
        default: return "Unknown Weapon Slot";
    }
}

// WeaponType -> readable weapon type
inline std::string to_string(WeaponType weapontype) {
    switch (weapontype) {
        case WeaponType::Dagger:      return "Dagger";
        case WeaponType::ShortSword:  return "Short Sword";
        case WeaponType::LongSword:   return "Long Sword";
        case WeaponType::BattleAxe:   return "Battle Axe";
        case WeaponType::ShortBow:    return "Short Bow";
        case WeaponType::LongBow:     return "Long Bow";
        // add the rest...
        default: return "Unknown Weapon";
    }
}
