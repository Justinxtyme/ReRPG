#include "power.h"
#include <iostream>
#include <unordered_map>
#include "Containers/Map.h"


AbilityID parseAbility(const std::string& s) {
	static const std::unordered_map<std::string, AbilityID> table = {
		{ "None", AbilityID::None },

		// Damage-over-time / Debuffs
		{ "Searing Wound", AbilityID::SearingWound },
		{ "Crippling Venom", AbilityID::CripplingVenom },
		{ "Ashen Burn", AbilityID::AshenBurn },
		{ "Festering Rot", AbilityID::FesteringRot },
		{ "Soul Bleed", AbilityID::SoulBleed },

		// Buffs / Blessings
		{ "Quick Step", AbilityID::QuickStep },
		{ "Iron Skin", AbilityID::IronSkin },
		{ "Battle Trance", AbilityID::BattleTrance },
		{ "Ward of Light", AbilityID::WardOfLight },
		{ "Stoneform", AbilityID::Stoneform },
		{ "Arcane Focus", AbilityID::ArcaneFocus },

		// Healing / Restoration
		{ "Renewing Grace", AbilityID::RenewingGrace },
		{ "Vital Surge", AbilityID::VitalSurge },
		{ "Blessed Mending", AbilityID::BlessedMending },
		{ "Spirit Bloom", AbilityID::SpiritBloom },
		{ "Second Wind", AbilityID::SecondWind },

		// Utility / Control
		{ "Chains of Dread", AbilityID::ChainsOfDread },
		{ "Mind Shatter", AbilityID::MindShatter },
		{ "Frost Shackles", AbilityID::FrostShackles },
		{ "Echoing Fear", AbilityID::EchoingFear },
		{ "Staggering Blow", AbilityID::StaggeringBlow },

		// Exotic / Flavorful
		{ "Dark Gift", AbilityID::DarkGift },
		{ "Phoenix Ember", AbilityID::PhoenixEmber },
		{ "Mirror Veil", AbilityID::MirrorVeil },
		{ "Blood Pact", AbilityID::BloodPact },
		{ "Ethereal Step", AbilityID::EtherealStep },
	};

	auto it = table.find(s);
	if (it != table.end())
		return it->second;

	throw std::runtime_error("Unknown ability: " + s);
}

AbilityID FparseAbility(const FName& s) {
	static const TMap<FName, AbilityID> table = {
		{ "None", AbilityID::None },

		// Damage-over-time / Debuffs
		{ "Searing Wound", AbilityID::SearingWound },
		{ "Crippling Venom", AbilityID::CripplingVenom },
		{ "Ashen Burn", AbilityID::AshenBurn },
		{ "Festering Rot", AbilityID::FesteringRot },
		{ "Soul Bleed", AbilityID::SoulBleed },

		// Buffs / Blessings
		{ "Quick Step", AbilityID::QuickStep },
		{ "Iron Skin", AbilityID::IronSkin },
		{ "Battle Trance", AbilityID::BattleTrance },
		{ "Ward of Light", AbilityID::WardOfLight },
		{ "Stoneform", AbilityID::Stoneform },
		{ "Arcane Focus", AbilityID::ArcaneFocus },

		// Healing / Restoration
		{ "Renewing Grace", AbilityID::RenewingGrace },
		{ "Vital Surge", AbilityID::VitalSurge },
		{ "Blessed Mending", AbilityID::BlessedMending },
		{ "Spirit Bloom", AbilityID::SpiritBloom },
		{ "Second Wind", AbilityID::SecondWind },

		// Utility / Control
		{ "Chains of Dread", AbilityID::ChainsOfDread },
		{ "Mind Shatter", AbilityID::MindShatter },
		{ "Frost Shackles", AbilityID::FrostShackles },
		{ "Echoing Fear", AbilityID::EchoingFear },
		{ "Staggering Blow", AbilityID::StaggeringBlow },

		// Exotic / Flavorful
		{ "Dark Gift", AbilityID::DarkGift },
		{ "Phoenix Ember", AbilityID::PhoenixEmber },
		{ "Mirror Veil", AbilityID::MirrorVeil },
		{ "Blood Pact", AbilityID::BloodPact },
		{ "Ethereal Step", AbilityID::EtherealStep },
	};

	if (const AbilityID* Found = table.Find(s))
		return *Found;


	throw std::runtime_error("Unknown ability");
}