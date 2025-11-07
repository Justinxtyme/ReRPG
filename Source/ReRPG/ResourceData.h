#pragma once
#include "CoreMinimal.h"
#include "ResourceData.generated.h"



USTRUCT(BlueprintType)
struct FResourceComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	int32 HP = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	int32 SP = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	int32 MP = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	int32 MaxHP = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	int32 MaxSP = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	int32 MaxMP = 100;
};



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RERPG_API UResourcesComponent : public UActorComponent
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	float HP;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	float SP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	float MP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	float MaxSP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	float MaxMP;
    
    UFUNCTION(BlueprintCallable)
    float GetHPPercent() const
    {
        return MaxHP > 0 ? HP / MaxHP : 0.f;
    }
    
	UFUNCTION(BlueprintCallable)
    float GetSPPercent() const
    {
        return MaxSP > 0 ? SP / MaxSP : 0.f;
    } 
    
    UFUNCTION(BlueprintCallable)
    float GetMPPercent() const
	{
		return MaxMP > 0 ? MP / MaxMP : 0.f;
	}       

};
