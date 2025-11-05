#pragma once

#include "CoreMinimal.h"   
#include "Subsystems/WorldSubsystem.h"
#include <entt/entt.hpp>
#include "ReRPG/itemfactory.h"
#include "EntityManagerSubsystem.generated.h"

class ItemFactory;

USTRUCT(BlueprintType)
struct FEntityHandle {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 Id;
};


// In-editor debug info for live entities
USTRUCT(BlueprintType)
struct FEntityDebugInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="ECS")
	int32 EntityID;

	// A simple string listing which components are present
	UPROPERTY(BlueprintReadOnly, Category="ECS")
	FString Components;
};


UCLASS()
class ENTITYMANAGER_API UEntityManagerSubsystem
	                  : public UWorldSubsystem,
						public FTickableGameObject

{
	GENERATED_BODY()

public:
	entt::registry Registry;

	TSet<entt::entity> LiveEntities;

	ItemFactory	IFactory;

	
	
	entt::entity CreateEntity(); 
	void DestroyEntity(entt::entity e);
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category="EntityManager")
	TArray<int32> GetLiveEntityIDs() const;

	UFUNCTION(BlueprintCallable, Category="ECS")
	TArray<FEntityDebugInfo> GetLiveEntityDebugInfo() const;

	virtual void Tick(float DeltaTime) override;
	
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UEntityManagerSubsystem, STATGROUP_Tickables); }

	virtual bool IsTickable() const override { return true; }
	
	TArray<FString> GetComponentsFor(entt::entity e);

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetComponentsForEntity(FEntityHandle Handle);



private:
	void OnEntityCreated(entt::registry& reg, entt::entity e);
	void OnEntityDestroyed(entt::registry& reg, entt::entity e);

};

// Lookup table for component names
inline std::unordered_map<entt::id_type, std::string> ComponentNames;


// Register each component that needs in editor inspection
// example call "RegisterComponentName<ItemComponent>()"
template<typename T>
void RegisterComponentName() {
	ComponentNames[entt::type_hash<T>::value()] = std::string(entt::type_name<T>().value());
}

