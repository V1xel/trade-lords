#include "TLTestBase.h"
#include "TLPlayerState.h"
#include "TLGameState.h"
#include "MarketComponent.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLMarketBuyResourceTest, "TL.Market.BuyResource",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLMarketBuyResourceTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_Market_BuyResource"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	ATLGameState* GameState = NewObject<ATLGameState>();
	UMarketComponent* Market = NewObject<UMarketComponent>();
	Market->InitializePrices();
	GameState->MarketComponent = Market;

	TestHelper.LogInfo(FString::Printf(TEXT("Wool Price: £%d"), Market->GetPrice(EResourceType::Wool)));
	TestHelper.LogInfo(FString::Printf(TEXT("Grain Price: £%d"), Market->GetPrice(EResourceType::Grain)));

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 20;
	Player->AvailableMerchants = 2;
	Player->UsedMerchants = 0;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	TestHelper.LogSection(TEXT("EVENT 1: Buy 2 Wool"));

	int32 InitialGold = Player->Gold;
	int32 WoolPrice = Market->GetPrice(EResourceType::Wool);
	int32 WoolQuantity = 2;
	int32 WoolTotalCost = WoolPrice * WoolQuantity;

	TestHelper.LogInfo(FString::Printf(TEXT("Buying %d Wool at £%d each = £%d total"), WoolQuantity, WoolPrice, WoolTotalCost));

	if (Player->UseMerchant())
	{
		if (Player->SpendGold(WoolTotalCost))
		{
			Player->AddResource(EResourceType::Wool, WoolQuantity);
			Market->BuyResource(Player, EResourceType::Wool, WoolQuantity);

			TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));
			TestHelper.LogStateChange(TEXT("Player Wool"), TEXT("0"), FString::FromInt(Player->GetResourceAmount(EResourceType::Wool)));
			TestHelper.LogStateChange(TEXT("Used Merchants"), TEXT("0"), TEXT("1"));
		}
	}

	TestHelper.LogSection(TEXT("EVENT 2: Buy 3 Grain"));

	InitialGold = Player->Gold;
	int32 GrainPrice = Market->GetPrice(EResourceType::Grain);
	int32 GrainQuantity = 3;
	int32 GrainTotalCost = GrainPrice * GrainQuantity;

	TestHelper.LogInfo(FString::Printf(TEXT("Buying %d Grain at £%d each = £%d total"), GrainQuantity, GrainPrice, GrainTotalCost));

	if (Player->UseMerchant())
	{
		if (Player->SpendGold(GrainTotalCost))
		{
			Player->AddResource(EResourceType::Grain, GrainQuantity);
			Market->BuyResource(Player, EResourceType::Grain, GrainQuantity);

			TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));
			TestHelper.LogStateChange(TEXT("Player Grain"), TEXT("0"), FString::FromInt(Player->GetResourceAmount(EResourceType::Grain)));
			TestHelper.LogStateChange(TEXT("Used Merchants"), TEXT("1"), TEXT("2"));
		}
	}

	TestHelper.LogSection(TEXT("EVENT 3: Attempt to Buy Without Merchant (Invalid)"));

	InitialGold = Player->Gold;
	bool bCanUseMerchant = Player->UseMerchant();

	TestHelper.LogInfo(FString::Printf(TEXT("Can use merchant: %s"), bCanUseMerchant ? TEXT("Yes") : TEXT("No")));

	if (!bCanUseMerchant)
	{
		TestHelper.LogInfo(TEXT("Correctly rejected - no merchants available"));
	}

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, 11, TEXT("Player Gold = £11 (£20 - £6 - £3)"));
	bSuccess &= TestHelper.AssertEqual(Player->GetResourceAmount(EResourceType::Wool), 2, TEXT("Player has 2 Wool"));
	bSuccess &= TestHelper.AssertEqual(Player->GetResourceAmount(EResourceType::Grain), 3, TEXT("Player has 3 Grain"));
	bSuccess &= TestHelper.AssertEqual(Player->UsedMerchants, 2, TEXT("Used 2 merchants"));
	bSuccess &= TestHelper.AssertEqual(bCanUseMerchant, false, TEXT("Cannot use more merchants"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLMarketSellResourceTest, "TL.Market.SellResource",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLMarketSellResourceTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_Market_SellResource"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	ATLGameState* GameState = NewObject<ATLGameState>();
	UMarketComponent* Market = NewObject<UMarketComponent>();
	Market->InitializePrices();
	GameState->MarketComponent = Market;

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 10;
	Player->AvailableMerchants = 2;
	Player->UsedMerchants = 0;
	Player->AddResource(EResourceType::Wool, 3);
	Player->AddResource(EResourceType::Cheese, 2);
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	TestHelper.LogSection(TEXT("EVENT 1: Sell 2 Wool"));

	int32 InitialGold = Player->Gold;
	int32 WoolPrice = Market->GetPrice(EResourceType::Wool);
	int32 WoolQuantity = 2;
	int32 WoolTotalValue = WoolPrice * WoolQuantity;

	TestHelper.LogInfo(FString::Printf(TEXT("Selling %d Wool at £%d each = £%d total"), WoolQuantity, WoolPrice, WoolTotalValue));

	if (Player->UseMerchant())
	{
		if (Player->SpendResource(EResourceType::Wool, WoolQuantity))
		{
			Player->AddGold(WoolTotalValue);
			Market->SellResource(Player, EResourceType::Wool, WoolQuantity);

			TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));
			TestHelper.LogStateChange(TEXT("Player Wool"), TEXT("3"), FString::FromInt(Player->GetResourceAmount(EResourceType::Wool)));
		}
	}

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, 16, TEXT("Player Gold = £16 (£10 + £6)"));
	bSuccess &= TestHelper.AssertEqual(Player->GetResourceAmount(EResourceType::Wool), 1, TEXT("Player has 1 Wool left"));
	bSuccess &= TestHelper.AssertEqual(Player->UsedMerchants, 1, TEXT("Used 1 merchant"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}
