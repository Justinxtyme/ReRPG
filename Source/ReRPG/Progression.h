//Progression.h
#pragma once

#include "CoreMinimal.h"
#include "Progression.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RERPG_API UProgressionComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Progression")
	int32 Level = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Progression")
	int32 Exp = 0;

	UFUNCTION(BlueprintCallable)
	int32 GetLevel() const { return Level; }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Progression")
	UProgressionTable* ProgressionData;
	
	UFUNCTION(BlueprintCallable)
	FText GetLevelInText() const
	{
		const FString String  = FString::FromInt(GetLevelFromXP(Level));
		return FText::FromString(String);
	}

	UFUNCTION(BlueprintCallable)
	int32 GetExp() const { return Exp; }

	UFUNCTION(BlueprintCallable)
	int32 GetLevelFromXP(int32 XP) const;
	
	
};


USTRUCT(BlueprintType)
struct FLevelThreshold
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 XPMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 XPMax;
};

UCLASS(BlueprintType)
class UProgressionTable : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FLevelThreshold> LevelEntries;
};


/* Binary search version if i decide on high lvl cap (100's to 1000's)
int32 UProgressionComponent::GetLevelFromXP(int32 XP) const
{
  int32 Low = 0;
  int32 High = ProgressionData->LevelEntries.Num() - 1;

  while (Low <= High)
  {
	  int32 Mid = (Low + High) / 2;
	  const FLevelThreshold& Entry = ProgressionData->LevelEntries[Mid];

	  if (XP >= Entry.XPMin && XP <= Entry.XPMax)
	  {
		  return Entry.Level;
	  }
	  else if (XP < Entry.XPMin)
	  {
		  High = Mid - 1;
	  }
	  else // XP > Entry.XPMax
	  {
		  Low = Mid + 1;
	  }
  }

  return CurrentLevel; // fallback
}
*/

