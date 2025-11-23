#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TLTypes.h"
#include "LordDefinition.generated.h"

class AUnit;

UCLASS(BlueprintType)
class TL_API ULordDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	FText LordName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	FText LordTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	FLinearColor HouseColorPrimary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	FLinearColor HouseColorSecondary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	int32 StartingGold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	TArray<TSubclassOf<AUnit>> StartingUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	int32 StartingMerchants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	int32 StartingShipping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	EAbilityType AbilityType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	FText AbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lord")
	UTexture2D* LordPortrait;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityTriggered);
	UPROPERTY(BlueprintAssignable, Category = "Lord")
	FOnAbilityTriggered OnAbilityTriggered;

	ULordDefinition()
		: HouseColorPrimary(FLinearColor::White)
		, HouseColorSecondary(FLinearColor::Gray)
		, StartingGold(8)
		, StartingMerchants(2)
		, StartingShipping(0)
		, AbilityType(EAbilityType::Passive)
		, LordPortrait(nullptr)
	{}
};
