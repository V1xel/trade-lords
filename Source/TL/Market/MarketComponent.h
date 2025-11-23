#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Resources/ResourceTypes.h"
#include "MarketTypes.h"
#include "MarketComponent.generated.h"

class ATLPlayerState;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnResourceBought, EResourceType, Resource, int32, Amount, int32, Price, ATLPlayerState*, Buyer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnResourceSold, EResourceType, Resource, int32, Amount, int32, Price, ATLPlayerState*, Seller);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPriceChanged, EResourceType, Resource, int32, NewPrice);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TL_API UMarketComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMarketComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	TMap<EResourceType, int32> ResourcePrices;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Market")
	TArray<FMarketPriceSnapshot> PriceHistory;

	UPROPERTY(BlueprintAssignable, Category = "Market")
	FOnResourceBought OnResourceBought;

	UPROPERTY(BlueprintAssignable, Category = "Market")
	FOnResourceSold OnResourceSold;

	UPROPERTY(BlueprintAssignable, Category = "Market")
	FOnPriceChanged OnPriceChanged;

	UFUNCTION(BlueprintCallable, Category = "Market")
	bool BuyResource(EResourceType Resource, int32 Amount, ATLPlayerState* Buyer);

	UFUNCTION(BlueprintCallable, Category = "Market")
	bool SellResource(EResourceType Resource, int32 Amount, ATLPlayerState* Seller);

	UFUNCTION(BlueprintCallable, Category = "Market")
	void AdjustPrice(EResourceType Resource, int32 Delta);

	UFUNCTION(BlueprintCallable, Category = "Market")
	int32 GetPrice(EResourceType Resource) const;

	UFUNCTION(BlueprintCallable, Category = "Market")
	void SavePriceSnapshot(int32 Round);
};
