using UnrealBuildTool;
using System.IO;
public class EntityManager : ModuleRules
{
    public EntityManager(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine"
        });
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../../ThirdParty/glm"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../../ThirdParty/entt/src"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../../ThirdParty/nlohmann"));

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            // Add modules only used internally here
        });
    }
}



