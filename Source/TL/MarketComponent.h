#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TLTypes.h"
#include "MarketComponent.generated.h"

class ATLPlayerState;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TL_API UMarketComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMarketComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	TMap<EResourceType, int32> ResourcePrices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	TArray<FMarketPriceSnapshot> PriceHistory;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnResourceBought, EResourceType, Resource, int32, Amount, int32, Price, ATLPlayerState*, Buyer);
	UPROPERTY(BlueprintAssignable, Category = "Market")
	FOnResourceBought OnResourceBought;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnResourceSold, EResourceType, Resource, int32, Amount, int32, Price, ATLPlayerState*, Seller);
	UPROPERTY(BlueprintAssignable, Category = "Market")
	FOnResourceSold OnResourceSold;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPriceChanged, EResourceType, Resource, int32, NewPrice);
	UPROPERTY(BlueprintAssignable, Category = "Market")
	FOnPriceChanged OnPriceChanged;

	UFUNCTION(BlueprintCallable, Category = "Market")
	void InitializePrices();

	UFUNCTION(BlueprintCallable, Category = "Market")
	int32 GetPrice(EResourceType Resource) const;

	UFUNCTION(BlueprintCallable, Category = "Market")
	void SetPrice(EResourceType Resource, int32 NewPrice);

	UFUNCTION(BlueprintCallable, Category = "Market")
	bool BuyResource(ATLPlayerState* Buyer, EResourceType Resource, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Market")
	bool SellResource(ATLPlayerState* Seller, EResourceType Resource, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Market")
	void SavePriceSnapshot(int32 Round);
};
