#include "TLTestBase.h"
#include "TLPlayerState.h"
#include "Unit.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLProductionBasicGoodsTest, "TL.Production.BasicGoods",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLProductionBasicGoodsTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_Production_BasicGoods"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 10;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	AUnit* Sheep = World->SpawnActor<AUnit>();
	Sheep->UnitType = EUnitType::Sheep;
	Sheep->ProducesResource = EResourceType::Wool;
	Sheep->OwningPlayer = Player;

	AUnit* Cow = World->SpawnActor<AUnit>();
	Cow->UnitType = EUnitType::Cow;
	Cow->ProducesResource = EResourceType::Milk;
	Cow->OwningPlayer = Player;

	AUnit* Field = World->SpawnActor<AUnit>();
	Field->UnitType = EUnitType::Field;
	Field->ProducesResource = EResourceType::Grain;
	Field->OwningPlayer = Player;

	Player->OwnedUnits.Add(Sheep);
	Player->OwnedUnits.Add(Cow);
	Player->OwnedUnits.Add(Field);

	TestHelper.LogInfo(FString::Printf(TEXT("Created %d production units"), Player->OwnedUnits.Num()));

	TestHelper.LogSection(TEXT("EVENT 1: Sheep Produces Wool"));

	Sheep->OnProduction.AddDynamic(Player, &ATLPlayerState::AddResource);
	Sheep->Produce();

	TestHelper.LogStateChange(TEXT("Wool"), TEXT("0"), FString::FromInt(Player->GetResourceAmount(EResourceType::Wool)));

	TestHelper.LogSection(TEXT("EVENT 2: Cow Produces Milk"));

	Cow->OnProduction.AddDynamic(Player, &ATLPlayerState::AddResource);
	Cow->Produce();

	TestHelper.LogStateChange(TEXT("Milk"), TEXT("0"), FString::FromInt(Player->GetResourceAmount(EResourceType::Milk)));

	TestHelper.LogSection(TEXT("EVENT 3: Field Produces Grain"));

	Field->OnProduction.AddDynamic(Player, &ATLPlayerState::AddResource);
	Field->Produce();

	TestHelper.LogStateChange(TEXT("Grain"), TEXT("0"), FString::FromInt(Player->GetResourceAmount(EResourceType::Grain)));

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, 10, TEXT("Gold unchanged during production"));
	bSuccess &= TestHelper.AssertEqual(Player->GetResourceAmount(EResourceType::Wool), 1, TEXT("Player has 1 Wool"));
	bSuccess &= TestHelper.AssertEqual(Player->GetResourceAmount(EResourceType::Milk), 1, TEXT("Player has 1 Milk"));
	bSuccess &= TestHelper.AssertEqual(Player->GetResourceAmount(EResourceType::Grain), 1, TEXT("Player has 1 Grain"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLProductionWorkerIncomeTest, "TL.Production.WorkerIncome",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLProductionWorkerIncomeTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_Production_WorkerIncome"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 10;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	AUnit* Woodcutter = World->SpawnActor<AUnit>();
	Woodcutter->UnitType = EUnitType::Woodcutter;
	Woodcutter->GeneratesIncome = 4;
	Woodcutter->UpgradedIncome = 6;
	Woodcutter->bIsUpgraded = false;
	Woodcutter->OwningPlayer = Player;

	AUnit* Miner = World->SpawnActor<AUnit>();
	Miner->UnitType = EUnitType::Miner;
	Miner->GeneratesIncome = 6;
	Miner->UpgradedIncome = 8;
	Miner->bIsUpgraded = false;
	Miner->OwningPlayer = Player;

	Player->OwnedUnits.Add(Woodcutter);
	Player->OwnedUnits.Add(Miner);

	TestHelper.LogUnitState(TEXT("Woodcutter"), Woodcutter);
	TestHelper.LogUnitState(TEXT("Miner"), Miner);

	TestHelper.LogSection(TEXT("EVENT 1: Woodcutter Generates Income"));

	int32 InitialGold = Player->Gold;
	Woodcutter->OnIncomeGenerated.AddDynamic(Player, &ATLPlayerState::AddGold);
	Woodcutter->GenerateGold();

	TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));

	TestHelper.LogSection(TEXT("EVENT 2: Miner Generates Income"));

	InitialGold = Player->Gold;
	Miner->OnIncomeGenerated.AddDynamic(Player, &ATLPlayerState::AddGold);
	Miner->GenerateGold();

	TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, 20, TEXT("Player Gold = £20 (£10 + £4 + £6)"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}
