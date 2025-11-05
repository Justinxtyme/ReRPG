// Auto-generated from items.json
#pragma once

#include <optional>
#include <string>

#include "UObject/Object.h"
#include "Containers/Map.h"

enum class ItemID {
    LeatherHelm,
    LeatherCuirass,
    LeatherBoots,
    LeatherLeggings,
    LeatherVambraces,
    LeatherBelt,
    ReinforcedLeatherHelm,
    ReinforcedLeatherCuirass,
    ReinforcedLeatherBoots,
    ReinforcedLeatherLeggings,
    ReinforcedLeatherVambraces,
    ReinforcedLeatherBelt,
    HardenedLeatherHelm,
    HardenedLeatherCuirass,
    HardenedLeatherBoots,
    HardenedLeatherLeggings,
    HardenedLeatherVambraces,
    HardenedLeatherBelt,
    IronVisor,
    IronChestplate,
    IronBoots,
    IronGreaves,
    IronArmplates,
    IronGirdle,
    SteelVisor,
    SteelChestplate,
    SteelBoots,
    SteelGreaves,
    SteelArmplates,
    SteelGirdle,
    ClothHood,
    ClothRobe,
    ClothSandals,
    ClothTrousers,
    ClothGloves,
    ClothSash,
    BlessedClothHood,
    BlessedClothRobe,
    BlessedClothSandals,
    BlessedClothTrousers,
    BlessedClothGloves,
    BlessedClothSash,
    SilkHood,
    SilkRobe,
    SilkSandals,
    SilkTrousers,
    SilkGloves,
    SilkSash,
    ArcaneSilkHood,
    ArcaneSilkRobe,
    ArcaneSilkSandals,
    ArcaneSilkTrousers,
    ArcaneSilkGloves,
    ArcaneSilkSash,
    MysticHood,
    MysticRobe,
    MysticSandals,
    MysticTrousers,
    MysticGloves,
    MysticSash,
    EldritchMysticHood,
    EldritchMysticRobe,
    EldritchMysticSandals,
    EldritchMysticTrousers,
    EldritchMysticGloves,
    EldritchMysticSash,
    RustedDagger,
    RustedStraightSword,
    RustedGreatSword,
    OldBroadAxe,
    RustedFellingAxe,
    IronDagger,
    IronStraightSword,
    IronGreatsword,
    SteelDagger,
    SteelStraightSword,
    SteelGreatsword,
    SteelBroadAxe,
    SteelFellingAxe,
    WeakPotion,
    Potion,
    StrongPotion,
    ElixirOfSpeed,
};

UENUM(BlueprintType)
enum class EItemID : uint8
{
    LeatherHelm,
    LeatherCuirass,
    LeatherBoots,
    LeatherLeggings,
    LeatherVambraces,
    LeatherBelt,
    ReinforcedLeatherHelm,
    ReinforcedLeatherCuirass,
    ReinforcedLeatherBoots,
    ReinforcedLeatherLeggings,
    ReinforcedLeatherVambraces,
    ReinforcedLeatherBelt,
    HardenedLeatherHelm,
    HardenedLeatherCuirass,
    HardenedLeatherBoots,
    HardenedLeatherLeggings,
    HardenedLeatherVambraces,
    HardenedLeatherBelt,
    IronVisor,
    IronChestplate,
    IronBoots,
    IronGreaves,
    IronArmplates,
    IronGirdle,
    SteelVisor,
    SteelChestplate,
    SteelBoots,
    SteelGreaves,
    SteelArmplates,
    SteelGirdle,
    ClothHood,
    ClothRobe,
    ClothSandals,
    ClothTrousers,
    ClothGloves,
    ClothSash,
    BlessedClothHood,
    BlessedClothRobe,
    BlessedClothSandals,
    BlessedClothTrousers,
    BlessedClothGloves,
    BlessedClothSash,
    SilkHood,
    SilkRobe,
    SilkSandals,
    SilkTrousers,
    SilkGloves,
    SilkSash,
    ArcaneSilkHood,
    ArcaneSilkRobe,
    ArcaneSilkSandals,
    ArcaneSilkTrousers,
    ArcaneSilkGloves,
    ArcaneSilkSash,
    MysticHood,
    MysticRobe,
    MysticSandals,
    MysticTrousers,
    MysticGloves,
    MysticSash,
    EldritchMysticHood,
    EldritchMysticRobe,
    EldritchMysticSandals,
    EldritchMysticTrousers,
    EldritchMysticGloves,
    EldritchMysticSash,
    RustedDagger,
    RustedStraightSword,
    RustedGreatSword,
    OldBroadAxe,
    RustedFellingAxe,
    IronDagger,
    IronStraightSword,
    IronGreatsword,
    SteelDagger,
    SteelStraightSword,
    SteelGreatsword,
    SteelBroadAxe,
    SteelFellingAxe,
    WeakPotion,
    Potion,
    StrongPotion,
    ElixirOfSpeed,
};

enum class EquipSlot {
Head,
Chest,
Legs,
Waist,
Feet,
RightHand,
LeftHand
};

enum class ItemCategory {
Consumable,
Weapon,
Armor,
KeyItem
};

inline const char* item2string(ItemID id) {
    switch(id) {
        case ItemID::LeatherHelm: return "LeatherHelm";
        case ItemID::LeatherCuirass: return "LeatherCuirass";
        case ItemID::LeatherBoots: return "LeatherBoots";
        case ItemID::LeatherLeggings: return "LeatherLeggings";
        case ItemID::LeatherVambraces: return "LeatherVambraces";
        case ItemID::LeatherBelt: return "LeatherBelt";
        case ItemID::ReinforcedLeatherHelm: return "ReinforcedLeatherHelm";
        case ItemID::ReinforcedLeatherCuirass: return "ReinforcedLeatherCuirass";
        case ItemID::ReinforcedLeatherBoots: return "ReinforcedLeatherBoots";
        case ItemID::ReinforcedLeatherLeggings: return "ReinforcedLeatherLeggings";
        case ItemID::ReinforcedLeatherVambraces: return "ReinforcedLeatherVambraces";
        case ItemID::ReinforcedLeatherBelt: return "ReinforcedLeatherBelt";
        case ItemID::HardenedLeatherHelm: return "HardenedLeatherHelm";
        case ItemID::HardenedLeatherCuirass: return "HardenedLeatherCuirass";
        case ItemID::HardenedLeatherBoots: return "HardenedLeatherBoots";
        case ItemID::HardenedLeatherLeggings: return "HardenedLeatherLeggings";
        case ItemID::HardenedLeatherVambraces: return "HardenedLeatherVambraces";
        case ItemID::HardenedLeatherBelt: return "HardenedLeatherBelt";
        case ItemID::IronVisor: return "IronVisor";
        case ItemID::IronChestplate: return "IronChestplate";
        case ItemID::IronBoots: return "IronBoots";
        case ItemID::IronGreaves: return "IronGreaves";
        case ItemID::IronArmplates: return "IronArmplates";
        case ItemID::IronGirdle: return "IronGirdle";
        case ItemID::SteelVisor: return "SteelVisor";
        case ItemID::SteelChestplate: return "SteelChestplate";
        case ItemID::SteelBoots: return "SteelBoots";
        case ItemID::SteelGreaves: return "SteelGreaves";
        case ItemID::SteelArmplates: return "SteelArmplates";
        case ItemID::SteelGirdle: return "SteelGirdle";
        case ItemID::ClothHood: return "ClothHood";
        case ItemID::ClothRobe: return "ClothRobe";
        case ItemID::ClothSandals: return "ClothSandals";
        case ItemID::ClothTrousers: return "ClothTrousers";
        case ItemID::ClothGloves: return "ClothGloves";
        case ItemID::ClothSash: return "ClothSash";
        case ItemID::BlessedClothHood: return "BlessedClothHood";
        case ItemID::BlessedClothRobe: return "BlessedClothRobe";
        case ItemID::BlessedClothSandals: return "BlessedClothSandals";
        case ItemID::BlessedClothTrousers: return "BlessedClothTrousers";
        case ItemID::BlessedClothGloves: return "BlessedClothGloves";
        case ItemID::BlessedClothSash: return "BlessedClothSash";
        case ItemID::SilkHood: return "SilkHood";
        case ItemID::SilkRobe: return "SilkRobe";
        case ItemID::SilkSandals: return "SilkSandals";
        case ItemID::SilkTrousers: return "SilkTrousers";
        case ItemID::SilkGloves: return "SilkGloves";
        case ItemID::SilkSash: return "SilkSash";
        case ItemID::ArcaneSilkHood: return "ArcaneSilkHood";
        case ItemID::ArcaneSilkRobe: return "ArcaneSilkRobe";
        case ItemID::ArcaneSilkSandals: return "ArcaneSilkSandals";
        case ItemID::ArcaneSilkTrousers: return "ArcaneSilkTrousers";
        case ItemID::ArcaneSilkGloves: return "ArcaneSilkGloves";
        case ItemID::ArcaneSilkSash: return "ArcaneSilkSash";
        case ItemID::MysticHood: return "MysticHood";
        case ItemID::MysticRobe: return "MysticRobe";
        case ItemID::MysticSandals: return "MysticSandals";
        case ItemID::MysticTrousers: return "MysticTrousers";
        case ItemID::MysticGloves: return "MysticGloves";
        case ItemID::MysticSash: return "MysticSash";
        case ItemID::EldritchMysticHood: return "EldritchMysticHood";
        case ItemID::EldritchMysticRobe: return "EldritchMysticRobe";
        case ItemID::EldritchMysticSandals: return "EldritchMysticSandals";
        case ItemID::EldritchMysticTrousers: return "EldritchMysticTrousers";
        case ItemID::EldritchMysticGloves: return "EldritchMysticGloves";
        case ItemID::EldritchMysticSash: return "EldritchMysticSash";
        case ItemID::RustedDagger: return "RustedDagger";
        case ItemID::RustedStraightSword: return "RustedStraightSword";
        case ItemID::RustedGreatSword: return "RustedGreatSword";
        case ItemID::OldBroadAxe: return "OldBroadAxe";
        case ItemID::RustedFellingAxe: return "RustedFellingAxe";
        case ItemID::IronDagger: return "IronDagger";
        case ItemID::IronStraightSword: return "IronStraightSword";
        case ItemID::IronGreatsword: return "IronGreatsword";
        case ItemID::SteelDagger: return "SteelDagger";
        case ItemID::SteelStraightSword: return "SteelStraightSword";
        case ItemID::SteelGreatsword: return "SteelGreatsword";
        case ItemID::SteelBroadAxe: return "SteelBroadAxe";
        case ItemID::SteelFellingAxe: return "SteelFellingAxe";
        case ItemID::WeakPotion: return "WeakPotion";
        case ItemID::Potion: return "Potion";
        case ItemID::StrongPotion: return "StrongPotion";
        case ItemID::ElixirOfSpeed: return "ElixirOfSpeed";
    }
    return "Unknown";
}

inline std::optional<ItemID> itemFromString(const std::string& s) {
    if (s == "LeatherHelm") return ItemID::LeatherHelm;
    if (s == "LeatherCuirass") return ItemID::LeatherCuirass;
    if (s == "LeatherBoots") return ItemID::LeatherBoots;
    if (s == "LeatherLeggings") return ItemID::LeatherLeggings;
    if (s == "LeatherVambraces") return ItemID::LeatherVambraces;
    if (s == "LeatherBelt") return ItemID::LeatherBelt;
    if (s == "ReinforcedLeatherHelm") return ItemID::ReinforcedLeatherHelm;
    if (s == "ReinforcedLeatherCuirass") return ItemID::ReinforcedLeatherCuirass;
    if (s == "ReinforcedLeatherBoots") return ItemID::ReinforcedLeatherBoots;
    if (s == "ReinforcedLeatherLeggings") return ItemID::ReinforcedLeatherLeggings;
    if (s == "ReinforcedLeatherVambraces") return ItemID::ReinforcedLeatherVambraces;
    if (s == "ReinforcedLeatherBelt") return ItemID::ReinforcedLeatherBelt;
    if (s == "HardenedLeatherHelm") return ItemID::HardenedLeatherHelm;
    if (s == "HardenedLeatherCuirass") return ItemID::HardenedLeatherCuirass;
    if (s == "HardenedLeatherBoots") return ItemID::HardenedLeatherBoots;
    if (s == "HardenedLeatherLeggings") return ItemID::HardenedLeatherLeggings;
    if (s == "HardenedLeatherVambraces") return ItemID::HardenedLeatherVambraces;
    if (s == "HardenedLeatherBelt") return ItemID::HardenedLeatherBelt;
    if (s == "IronVisor") return ItemID::IronVisor;
    if (s == "IronChestplate") return ItemID::IronChestplate;
    if (s == "IronBoots") return ItemID::IronBoots;
    if (s == "IronGreaves") return ItemID::IronGreaves;
    if (s == "IronArmplates") return ItemID::IronArmplates;
    if (s == "IronGirdle") return ItemID::IronGirdle;
    if (s == "SteelVisor") return ItemID::SteelVisor;
    if (s == "SteelChestplate") return ItemID::SteelChestplate;
    if (s == "SteelBoots") return ItemID::SteelBoots;
    if (s == "SteelGreaves") return ItemID::SteelGreaves;
    if (s == "SteelArmplates") return ItemID::SteelArmplates;
    if (s == "SteelGirdle") return ItemID::SteelGirdle;
    if (s == "ClothHood") return ItemID::ClothHood;
    if (s == "ClothRobe") return ItemID::ClothRobe;
    if (s == "ClothSandals") return ItemID::ClothSandals;
    if (s == "ClothTrousers") return ItemID::ClothTrousers;
    if (s == "ClothGloves") return ItemID::ClothGloves;
    if (s == "ClothSash") return ItemID::ClothSash;
    if (s == "BlessedClothHood") return ItemID::BlessedClothHood;
    if (s == "BlessedClothRobe") return ItemID::BlessedClothRobe;
    if (s == "BlessedClothSandals") return ItemID::BlessedClothSandals;
    if (s == "BlessedClothTrousers") return ItemID::BlessedClothTrousers;
    if (s == "BlessedClothGloves") return ItemID::BlessedClothGloves;
    if (s == "BlessedClothSash") return ItemID::BlessedClothSash;
    if (s == "SilkHood") return ItemID::SilkHood;
    if (s == "SilkRobe") return ItemID::SilkRobe;
    if (s == "SilkSandals") return ItemID::SilkSandals;
    if (s == "SilkTrousers") return ItemID::SilkTrousers;
    if (s == "SilkGloves") return ItemID::SilkGloves;
    if (s == "SilkSash") return ItemID::SilkSash;
    if (s == "ArcaneSilkHood") return ItemID::ArcaneSilkHood;
    if (s == "ArcaneSilkRobe") return ItemID::ArcaneSilkRobe;
    if (s == "ArcaneSilkSandals") return ItemID::ArcaneSilkSandals;
    if (s == "ArcaneSilkTrousers") return ItemID::ArcaneSilkTrousers;
    if (s == "ArcaneSilkGloves") return ItemID::ArcaneSilkGloves;
    if (s == "ArcaneSilkSash") return ItemID::ArcaneSilkSash;
    if (s == "MysticHood") return ItemID::MysticHood;
    if (s == "MysticRobe") return ItemID::MysticRobe;
    if (s == "MysticSandals") return ItemID::MysticSandals;
    if (s == "MysticTrousers") return ItemID::MysticTrousers;
    if (s == "MysticGloves") return ItemID::MysticGloves;
    if (s == "MysticSash") return ItemID::MysticSash;
    if (s == "EldritchMysticHood") return ItemID::EldritchMysticHood;
    if (s == "EldritchMysticRobe") return ItemID::EldritchMysticRobe;
    if (s == "EldritchMysticSandals") return ItemID::EldritchMysticSandals;
    if (s == "EldritchMysticTrousers") return ItemID::EldritchMysticTrousers;
    if (s == "EldritchMysticGloves") return ItemID::EldritchMysticGloves;
    if (s == "EldritchMysticSash") return ItemID::EldritchMysticSash;
    if (s == "RustedDagger") return ItemID::RustedDagger;
    if (s == "RustedStraightSword") return ItemID::RustedStraightSword;
    if (s == "RustedGreatSword") return ItemID::RustedGreatSword;
    if (s == "OldBroadAxe") return ItemID::OldBroadAxe;
    if (s == "RustedFellingAxe") return ItemID::RustedFellingAxe;
    if (s == "IronDagger") return ItemID::IronDagger;
    if (s == "IronStraightSword") return ItemID::IronStraightSword;
    if (s == "IronGreatsword") return ItemID::IronGreatsword;
    if (s == "SteelDagger") return ItemID::SteelDagger;
    if (s == "SteelStraightSword") return ItemID::SteelStraightSword;
    if (s == "SteelGreatsword") return ItemID::SteelGreatsword;
    if (s == "SteelBroadAxe") return ItemID::SteelBroadAxe;
    if (s == "SteelFellingAxe") return ItemID::SteelFellingAxe;
    if (s == "WeakPotion") return ItemID::WeakPotion;
    if (s == "Potion") return ItemID::Potion;
    if (s == "StrongPotion") return ItemID::StrongPotion;
    if (s == "ElixirOfSpeed") return ItemID::ElixirOfSpeed;
    return std::nullopt;
}

inline ItemID ResolveItemID(const EItemID id) {
    static const TMap<EItemID, ItemID> Lookup = {
         {EItemID::LeatherHelm, ItemID::LeatherHelm },
         {EItemID::LeatherCuirass, ItemID::LeatherCuirass },
         {EItemID::LeatherBoots, ItemID::LeatherBoots },
         {EItemID::LeatherLeggings, ItemID::LeatherLeggings },
         {EItemID::LeatherVambraces, ItemID::LeatherVambraces },
         {EItemID::LeatherBelt, ItemID::LeatherBelt },
         {EItemID::ReinforcedLeatherHelm, ItemID::ReinforcedLeatherHelm },
         {EItemID::ReinforcedLeatherCuirass, ItemID::ReinforcedLeatherCuirass },
         {EItemID::ReinforcedLeatherBoots, ItemID::ReinforcedLeatherBoots },
         {EItemID::ReinforcedLeatherLeggings, ItemID::ReinforcedLeatherLeggings },
         {EItemID::ReinforcedLeatherVambraces, ItemID::ReinforcedLeatherVambraces },
         {EItemID::ReinforcedLeatherBelt, ItemID::ReinforcedLeatherBelt },
         {EItemID::HardenedLeatherHelm, ItemID::HardenedLeatherHelm },
         {EItemID::HardenedLeatherCuirass, ItemID::HardenedLeatherCuirass },
         {EItemID::HardenedLeatherBoots, ItemID::HardenedLeatherBoots },
         {EItemID::HardenedLeatherLeggings, ItemID::HardenedLeatherLeggings },
         {EItemID::HardenedLeatherVambraces, ItemID::HardenedLeatherVambraces },
         {EItemID::HardenedLeatherBelt, ItemID::HardenedLeatherBelt },
         {EItemID::IronVisor, ItemID::IronVisor },
         {EItemID::IronChestplate, ItemID::IronChestplate },
         {EItemID::IronBoots, ItemID::IronBoots },
         {EItemID::IronGreaves, ItemID::IronGreaves },
         {EItemID::IronArmplates, ItemID::IronArmplates },
         {EItemID::IronGirdle, ItemID::IronGirdle },
         {EItemID::SteelVisor, ItemID::SteelVisor },
         {EItemID::SteelChestplate, ItemID::SteelChestplate },
         {EItemID::SteelBoots, ItemID::SteelBoots },
         {EItemID::SteelGreaves, ItemID::SteelGreaves },
         {EItemID::SteelArmplates, ItemID::SteelArmplates },
         {EItemID::SteelGirdle, ItemID::SteelGirdle },
         {EItemID::ClothHood, ItemID::ClothHood },
         {EItemID::ClothRobe, ItemID::ClothRobe },
         {EItemID::ClothSandals, ItemID::ClothSandals },
         {EItemID::ClothTrousers, ItemID::ClothTrousers },
         {EItemID::ClothGloves, ItemID::ClothGloves },
         {EItemID::ClothSash, ItemID::ClothSash },
         {EItemID::BlessedClothHood, ItemID::BlessedClothHood },
         {EItemID::BlessedClothRobe, ItemID::BlessedClothRobe },
         {EItemID::BlessedClothSandals, ItemID::BlessedClothSandals },
         {EItemID::BlessedClothTrousers, ItemID::BlessedClothTrousers },
         {EItemID::BlessedClothGloves, ItemID::BlessedClothGloves },
         {EItemID::BlessedClothSash, ItemID::BlessedClothSash },
         {EItemID::SilkHood, ItemID::SilkHood },
         {EItemID::SilkRobe, ItemID::SilkRobe },
         {EItemID::SilkSandals, ItemID::SilkSandals },
         {EItemID::SilkTrousers, ItemID::SilkTrousers },
         {EItemID::SilkGloves, ItemID::SilkGloves },
         {EItemID::SilkSash, ItemID::SilkSash },
         {EItemID::ArcaneSilkHood, ItemID::ArcaneSilkHood },
         {EItemID::ArcaneSilkRobe, ItemID::ArcaneSilkRobe },
         {EItemID::ArcaneSilkSandals, ItemID::ArcaneSilkSandals },
         {EItemID::ArcaneSilkTrousers, ItemID::ArcaneSilkTrousers },
         {EItemID::ArcaneSilkGloves, ItemID::ArcaneSilkGloves },
         {EItemID::ArcaneSilkSash, ItemID::ArcaneSilkSash },
         {EItemID::MysticHood, ItemID::MysticHood },
         {EItemID::MysticRobe, ItemID::MysticRobe },
         {EItemID::MysticSandals, ItemID::MysticSandals },
         {EItemID::MysticTrousers, ItemID::MysticTrousers },
         {EItemID::MysticGloves, ItemID::MysticGloves },
         {EItemID::MysticSash, ItemID::MysticSash },
         {EItemID::EldritchMysticHood, ItemID::EldritchMysticHood },
         {EItemID::EldritchMysticRobe, ItemID::EldritchMysticRobe },
         {EItemID::EldritchMysticSandals, ItemID::EldritchMysticSandals },
         {EItemID::EldritchMysticTrousers, ItemID::EldritchMysticTrousers },
         {EItemID::EldritchMysticGloves, ItemID::EldritchMysticGloves },
         {EItemID::EldritchMysticSash, ItemID::EldritchMysticSash },
         {EItemID::RustedDagger, ItemID::RustedDagger },
         {EItemID::RustedStraightSword, ItemID::RustedStraightSword },
         {EItemID::RustedGreatSword, ItemID::RustedGreatSword },
         {EItemID::OldBroadAxe, ItemID::OldBroadAxe },
         {EItemID::RustedFellingAxe, ItemID::RustedFellingAxe },
         {EItemID::IronDagger, ItemID::IronDagger },
         {EItemID::IronStraightSword, ItemID::IronStraightSword },
         {EItemID::IronGreatsword, ItemID::IronGreatsword },
         {EItemID::SteelDagger, ItemID::SteelDagger },
         {EItemID::SteelStraightSword, ItemID::SteelStraightSword },
         {EItemID::SteelGreatsword, ItemID::SteelGreatsword },
         {EItemID::SteelBroadAxe, ItemID::SteelBroadAxe },
         {EItemID::SteelFellingAxe, ItemID::SteelFellingAxe },
         {EItemID::WeakPotion, ItemID::WeakPotion },
         {EItemID::Potion, ItemID::Potion },
         {EItemID::StrongPotion, ItemID::StrongPotion },
         {EItemID::ElixirOfSpeed, ItemID::ElixirOfSpeed },
    };
    if (const ItemID* Found = Lookup.Find(id))
    return *Found;

    throw std::runtime_error("EItemID");
}

