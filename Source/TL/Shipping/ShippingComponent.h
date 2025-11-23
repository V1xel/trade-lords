#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShippingComponent.generated.h"

class AHexTile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShippingUpgraded, int32, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShippingUsed, AHexTile*, SourceHex, AHexTile*, TargetHex);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TL_API UShippingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UShippingComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shipping")
	int32 ShippingLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shipping")
	TArray<int32> UpgradeCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shipping")
	int32 MaxShippingLevel;

	UPROPERTY(BlueprintAssignable, Category = "Shipping")
	FOnShippingUpgraded OnShippingUpgraded;

	UPROPERTY(BlueprintAssignable, Category = "Shipping")
	FOnShippingUsed OnShippingUsed;

	UFUNCTION(BlueprintCallable, Category = "Shipping")
	bool UpgradeShipping();

	UFUNCTION(BlueprintCallable, Category = "Shipping")
	int32 GetUpgradeCost() const;

	UFUNCTION(BlueprintCallable, Category = "Shipping")
	bool CanUpgrade() const;
};
