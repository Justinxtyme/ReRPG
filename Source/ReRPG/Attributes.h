#pragma once

#include "CoreMinimal.h"
#include "Attributes.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RERPG_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Dexterity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Endurance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int BaseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Luck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Light;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Dark;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Focus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	int Presence;
};