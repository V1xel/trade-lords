#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LordDefinition.generated.h"

class AUnit;
class ATLPlayerState;

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	Passive UMETA(DisplayName = "Passive"),
	Triggered UMETA(DisplayName = "Triggered"),
	Active UMETA(DisplayName = "Active")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityTriggered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLordSelected, ATLPlayerState*, Player);

UCLASS(BlueprintType)
class TL_API ULordDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	FText LordName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	FText LordTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	FLinearColor HouseColorPrimary;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	FLinearColor HouseColorSecondary;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	int32 StartingGold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	TArray<TSubclassOf<AUnit>> StartingUnits;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	int32 StartingMerchants;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	int32 StartingShipping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	EAbilityType AbilityType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	FText AbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lord")
	UTexture2D* LordPortrait;

	UPROPERTY(BlueprintAssignable, Category = "Lord")
	FOnAbilityTriggered OnAbilityTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Lord")
	FOnLordSelected OnLordSelected;
};
