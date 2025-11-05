#!/usr/bin/env python3
import json
import sys

def generate_item_hdr(json_file, header_file):
    with open(json_file, "r") as f:
        data = json.load(f)

    keys = list(data.keys())

    with open(header_file, "w") as out:
        out.write("// Auto-generated from {}\n".format(json_file))
        out.write("#pragma once\n\n")
        out.write("#include <optional>\n")
        out.write("#include <string>\n\n")
        out.write("#include \"UObject/Object.h\"\n")
        out.write("#include \"Containers/Map.h\"\n\n")
        out.write("enum class ItemID {\n")
        
        for k in keys:
            out.write(f"    {k},\n")
        out.write("};\n\n")

        ### EItemID
        out.write("UENUM(BlueprintType)\n")
        out.write("enum class EItemID : uint8\n")
        out.write("{\n")
        for k in keys:
            out.write(f"    {k},\n")
        out.write("};\n\n")
        
        #Equip Slot
        out.write("enum class EquipSlot {\n")
        out.write("Head,\n")
        out.write("Chest,\n")
        out.write("Legs,\n")
        out.write("Waist,\n")
        out.write("Feet,\n")
        out.write("RightHand,\n")
        out.write("LeftHand\n")
        out.write("};\n\n")
    
        # Item Category
        out.write("enum class ItemCategory {\n")
        out.write("Consumable,\n")
        out.write("Weapon,\n")
        out.write("Armor,\n")
        out.write("KeyItem\n")
        out.write("};\n\n")

        # item2string
        out.write("inline const char* item2string(ItemID id) {\n")
        out.write("    switch(id) {\n")
        for k in keys:
            out.write(f"        case ItemID::{k}: return \"{k}\";\n")
        out.write("    }\n")
        out.write("    return \"Unknown\";\n")
        out.write("}\n\n")

        # itemFromString
        out.write("inline std::optional<ItemID> itemFromString(const std::string& s) {\n")
        for k in keys:
            out.write(f"    if (s == \"{k}\") return ItemID::{k};\n")
        out.write("    return std::nullopt;\n")
        out.write("}\n\n")
        
        # ResolveItemID
        out.write("inline ItemID ResolveItemID(const EItemID id) {\n")
        out.write("    static const TMap<EItemID, ItemID> Lookup = {\n")
        for k in keys:    
            out.write(f"         {{EItemID::{k}, ItemID::{k} }},\n")
        
        out.write("    };\n")
        out.write("    if (const ItemID* Found = Lookup.Find(id))\n")
        out.write("    return *Found;\n\n")
        out.write("    throw std::runtime_error(\"EItemID\");\n")
        out.write("}\n\n")
        
        

        # ### item to EItemID
        # out.write("ItemID EItemIdToItemId(EItemID id) {\n")
        # out.write("    ")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: codegen.py items.json ItemID.generated.h")
        sys.exit(1)
    generate_item_hdr(sys.argv[1], sys.argv[2])