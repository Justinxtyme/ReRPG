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
