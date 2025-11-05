#include "InventoryData.h"
#include "itemfactory.h"
#include "component.h"
#include "item.h"
#include "EntityManager/Public/EntityManagerSubsystem.h"
#include "GameFramework/Actor.h"
#include "Engine/GameInstance.h"
#include "Subsystems/WorldSubsystem.h"

WeaponStatsComponent MakeWeaponStats(const UWeaponData* Data)
{
	WeaponStatsComponent Comp;
	Comp.type = Data->Type_;
	Comp.damage = Data->Damage;
	Comp.handling = Data->Handling_;
	Comp.dmgType = Data->DamageType_;
	Comp.baseDamage = Data->BaseDamage;
	Comp.rarity_mod = Data->RarityMod;

	for (const auto& Pair : Data->Scaling)
		Comp.scaling[std::string(TCHAR_TO_UTF8(*Pair.Key))] = Pair.Value;

	for (const FName& Ability : Data->GrantedAbilities)
		Comp.grantedAbilities.push_back(FparseAbility(Ability));

	return Comp;
}

ArmorStatsComponent MakeArmorStats(const UArmorData* Data)
{
	ArmorStatsComponent Comp;
	Comp.armorType = Data->ArmorType_;
	Comp.armorClass = Data->ArmorClass_;
	Comp.baseDefense = Data->BaseDefense;
	Comp.rarity_mod = Data->RarityMod;

	for (const FName& Ability : Data->GrantedAbilities)
		Comp.grantedAbilities.push_back(FparseAbility(Ability));

	return Comp;
}

void BuildInventoryFromDefaults(entt::registry& Registry, const entt::entity Entity, const FInventoryDefaults& Defaults, ItemFactory IFactory)
{
	
	auto& Inv = Registry.emplace<InventoryComponent>(Entity);

	for (const auto& Item : Defaults.DefaultStackables)
		Inv.stackables[ResolveItemID(Item.ItemID)] = Item.Count;

	for (const auto& ArmorEntry : Defaults.DefaultArmor)
		Inv.armor[ArmorEntry.Slot] = IFactory.create(Registry, ResolveItemID(ArmorEntry.ItemID));

	for (const auto& WeaponEntry : Defaults.DefaultWeapons)
		Inv.weapons[WeaponEntry.Slot] = IFactory.create(Registry, ResolveItemID(WeaponEntry.ItemID));
	
}
