#include "EntityManagerSubsystem.h"
//#include <entt/entt.hpp>
#include "ReRPG/TransformComponent.h"


void UEntityManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	RegisterComponentName<ItemComponent>();
	RegisterComponentName<ResourceComponent>();
	RegisterComponentName<InventoryComponent>();
	RegisterComponentName<AttributesComponent>();
	RegisterComponentName<IdentityComponent>();
	RegisterComponentName<CombatStatsComponent>();
	RegisterComponentName<ProgressionComponent>();
	
	// // Connect EnTT Registry to Live Entities
	// Registry.on_construct<entt::entity>().connect<&UEntityManagerSubsystem::OnEntityCreated>(*this);
	// Registry.on_destroy<entt::entity>().connect<&UEntityManagerSubsystem::OnEntityDestroyed>(*this);

}

void UEntityManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	
	// Registry.on_construct<entt::entity>().disconnect<&UEntityManagerSubsystem::OnEntityCreated>(*this);
	// Registry.on_destroy<entt::entity>().disconnect<&UEntityManagerSubsystem::OnEntityDestroyed>(*this);

	LiveEntities.Empty();
	
	Registry.clear();
}

void UEntityManagerSubsystem::OnEntityCreated(entt::registry& reg, entt::entity e)
{
	LiveEntities.Add(e);
}

void UEntityManagerSubsystem::OnEntityDestroyed(entt::registry& reg, entt::entity e)
{
	LiveEntities.Remove(e);
}


TArray<int32> UEntityManagerSubsystem::GetLiveEntityIDs() const
{
	TArray<int32> Result;
	Result.Reserve(LiveEntities.Num());

	for (entt::entity e : LiveEntities)
	{
		Result.Add(static_cast<int32>(entt::to_integral(e)));
	}

	return Result;
}

TArray<FEntityDebugInfo> UEntityManagerSubsystem::GetLiveEntityDebugInfo() const
{
	TArray<FEntityDebugInfo> Result;
	Result.Reserve(LiveEntities.Num());

	for (entt::entity e : LiveEntities)
	{
		FEntityDebugInfo Info;
		Info.EntityID = static_cast<int32>(entt::to_integral(e));

		TArray<FString> Present;

		if (Registry.all_of<TransformComponent>(e)) { Present.Add(TEXT("Transform")); }
		if (Registry.all_of<InventoryComponent>(e)) { Present.Add(TEXT("Inventory")); }
		if (Registry.all_of<ResourceComponent>(e))    { Present.Add(TEXT("Health")); }
		if (Registry.all_of<IdentityComponent>(e))    { Present.Add(TEXT("Identity")); }
		// …add checks for whatever components you want to debug

		Info.Components = FString::Join(Present, TEXT(", "));
		Result.Add(Info);
	}

	return Result;
}

void UEntityManagerSubsystem::Tick(float DeltaTime)
{
	static int TickCount = 0;
	TickCount++;
}

entt::entity UEntityManagerSubsystem::CreateEntity()
{
	entt::entity e = Registry.create();
	LiveEntities.Add(e);
	return e;
}

void UEntityManagerSubsystem::DestroyEntity(entt::entity e)
{
	// allow callers to run pre-destroy logic if needed
	LiveEntities.Remove(e);
	Registry.destroy(e);
}


TArray<FString> UEntityManagerSubsystem::GetComponentsFor(entt::entity e) {
	TArray<FString> Out;

	for (auto &&[type_id, storage] : Registry.storage()) {
		if (storage.contains(e)) {
			auto it = ComponentNames.find(type_id);
			if (it != ComponentNames.end()) {
				Out.Add(FString(it->second.c_str()));
			} else {
				UE_LOG(LogTemp, Warning, TEXT("Component type %u not registered in ComponentNames"), 
																								  type_id);
				Out.Add(FString::Printf(TEXT("Component<%llu>"),
						  static_cast<unsigned long long>(type_id)));
			}
		}
	}

	return Out;
}

TArray<FString> UEntityManagerSubsystem::GetComponentsForEntity(FEntityHandle Handle) {
	entt::entity e = static_cast<entt::entity>(Handle.Id);
	if (!Registry.valid(e)) {
		return {}; // entity no longer alive
	}
	return GetComponentsFor(e);
}
