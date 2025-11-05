// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ReRPG : ModuleRules
{
	public ReRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "EntityManager"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ReRPG",
			"ReRPG/Variant_Platforming",
			"ReRPG/Variant_Platforming/Animation",
			"ReRPG/Variant_Combat",
			"ReRPG/Variant_Combat/AI",
			"ReRPG/Variant_Combat/Animation",
			"ReRPG/Variant_Combat/Gameplay",
			"ReRPG/Variant_Combat/Interfaces",
			"ReRPG/Variant_Combat/UI",
			"ReRPG/Variant_SideScrolling",
			"ReRPG/Variant_SideScrolling/AI",
			"ReRPG/Variant_SideScrolling/Gameplay",
			"ReRPG/Variant_SideScrolling/Interfaces",
			"ReRPG/Variant_SideScrolling/UI"
		});
		
		PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "C:/Users/the1i/CODERZ/ReRPG/ThirdParty/glm"));
		PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "C:/Users/the1i/CODERZ/ReRPG/ThirdParty/entt/src"));
		PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "C:/Users/the1i/CODERZ/ReRPG/ThirdParty/nlohmann"));

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
