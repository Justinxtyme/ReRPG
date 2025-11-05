#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include <ostream>
#include "item.h"
//#include "char.h"
#include "power.h"
#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class ArmorClass : uint8 {
    LightArmor,
    MediumArmor,
    HeavyArmor
};

UENUM(BlueprintType)
enum class ArmorType : uint8 {
    Head,
    Chest,
    Arms,
    Waist,
    Legs,
    Feet
};

inline const char* slot2string(const ArmorType &type) {
    switch (type) {
        case ArmorType::Head:  return "Head";
        case ArmorType::Chest: return "Chest";
        case ArmorType::Arms:  return "Arms";
        case ArmorType::Waist: return "Waist";
        case ArmorType::Legs:  return "Legs";
        case ArmorType::Feet:  return "Feet";
    }
    throw std::runtime_error("Unknown Armor Slot");
}

inline std::ostream& operator<<(std::ostream &os, ArmorType slot) {
    return os << slot2string(slot);
}


