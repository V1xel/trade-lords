#include "TLTestBase.h"
#include "TLPlayerState.h"
#include "TLGameState.h"
#include "TLGameMode.h"
#include "HexTile.h"
#include "Unit.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLPlacementBasicTest, "TL.Placement.Basic",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLPlacementBasicTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_PlaceUnit_Basic"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	AHexTile* Hex = World->SpawnActor<AHexTile>();
	Hex->TerrainTypes.Add(ETerrainType::Grassland);
	Hex->TerrainCost = 1;
	Hex->bIsOccupied = false;
	TestHelper.LogHexState(TEXT("Created"), Hex);

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 10;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	TestHelper.LogSection(TEXT("EVENT 1: Place Sheep on Grassland"));

	int32 InitialGold = Player->Gold;
	int32 SheepCost = 4;
	int32 TerrainCost = Hex->TerrainCost;
	int32 TotalCost = SheepCost + TerrainCost;

	TestHelper.LogInfo(FString::Printf(TEXT("Unit Cost: £%d"), SheepCost));
	TestHelper.LogInfo(FString::Printf(TEXT("Terrain Cost: £%d"), TerrainCost));
	TestHelper.LogInfo(FString::Printf(TEXT("Total Cost: £%d"), TotalCost));

	AUnit* Sheep = World->SpawnActor<AUnit>();
	Sheep->UnitType = EUnitType::Sheep;
	Sheep->UnitCost = SheepCost;
	Sheep->RequiredTerrain.Add(ETerrainType::Grassland);
	Sheep->ProducesResource = EResourceType::Wool;

	if (Sheep->CanPlaceOnTerrain(Hex))
	{
		if (Player->SpendGold(TotalCost))
		{
			Hex->PlaceUnit(Sheep, Player);
			Player->AddUnit(Sheep);
			Player->AddHex(Hex);
			Sheep->PlacedOnHex = Hex;
			Sheep->OwningPlayer = Player;

			TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));
			TestHelper.LogStateChange(TEXT("Player Units"), TEXT("0"), FString::FromInt(Player->OwnedUnits.Num()));
			TestHelper.LogStateChange(TEXT("Player Owned Hexes"), TEXT("0"), FString::FromInt(Player->OwnedHexes.Num()));
			TestHelper.LogStateChange(TEXT("Hex Occupied"), TEXT("false"), TEXT("true"));
		}
		else
		{
			TestHelper.LogError(TEXT("Failed to spend gold"));
		}
	}
	else
	{
		TestHelper.LogError(TEXT("Cannot place unit on terrain"));
	}

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);
	TestHelper.LogHexState(TEXT("Final"), Hex);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, 5, TEXT("Player Gold = £5"));
	bSuccess &= TestHelper.AssertEqual(Player->OwnedUnits.Num(), 1, TEXT("Player has 1 unit"));
	bSuccess &= TestHelper.AssertEqual(Player->OwnedHexes.Num(), 1, TEXT("Player owns 1 hex"));
	bSuccess &= TestHelper.AssertEqual(Hex->bIsOccupied, true, TEXT("Hex is occupied"));
	bSuccess &= TestHelper.AssertNotNull(Hex->OccupyingUnit, TEXT("Hex has occupying unit"));
	bSuccess &= TestHelper.AssertNotNull(Hex->OwningPlayer, TEXT("Hex has owning player"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLPlacementInvalidTerrainTest, "TL.Placement.InvalidTerrain",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLPlacementInvalidTerrainTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_PlaceUnit_InvalidTerrain"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	AHexTile* MountainHex = World->SpawnActor<AHexTile>();
	MountainHex->TerrainTypes.Add(ETerrainType::Mountain);
	MountainHex->TerrainCost = 6;
	MountainHex->bIsOccupied = false;
	TestHelper.LogHexState(TEXT("Created Mountain"), MountainHex);

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 20;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	TestHelper.LogSection(TEXT("EVENT 1: Attempt to Place Sheep on Mountain (Invalid)"));

	int32 InitialGold = Player->Gold;

	AUnit* Sheep = World->SpawnActor<AUnit>();
	Sheep->UnitType = EUnitType::Sheep;
	Sheep->UnitCost = 4;
	Sheep->RequiredTerrain.Add(ETerrainType::Grassland);
	Sheep->ProducesResource = EResourceType::Wool;

	bool bCanPlace = Sheep->CanPlaceOnTerrain(MountainHex);
	TestHelper.LogInfo(FString::Printf(TEXT("Can place Sheep on Mountain: %s"), bCanPlace ? TEXT("Yes") : TEXT("No")));

	if (bCanPlace)
	{
		TestHelper.LogError(TEXT("Should not be able to place Sheep on Mountain!"));
	}
	else
	{
		TestHelper.LogInfo(TEXT("Correctly rejected placement"));
	}

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);
	TestHelper.LogHexState(TEXT("Final"), MountainHex);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, InitialGold, TEXT("Player Gold unchanged"));
	bSuccess &= TestHelper.AssertEqual(Player->OwnedUnits.Num(), 0, TEXT("Player has 0 units"));
	bSuccess &= TestHelper.AssertEqual(MountainHex->bIsOccupied, false, TEXT("Hex is not occupied"));
	bSuccess &= TestHelper.AssertEqual(bCanPlace, false, TEXT("Cannot place Sheep on Mountain"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLPlacementTerrainCostTest, "TL.Placement.TerrainCost",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLPlacementTerrainCostTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_PlaceUnit_TerrainCost"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	AHexTile* ForestHex = World->SpawnActor<AHexTile>();
	ForestHex->TerrainTypes.Add(ETerrainType::Forest);
	ForestHex->TerrainCost = 3;
	TestHelper.LogHexState(TEXT("Created Forest"), ForestHex);

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->Gold = 20;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	TestHelper.LogSection(TEXT("EVENT 1: Place Woodcutter on Forest"));

	int32 InitialGold = Player->Gold;
	int32 WoodcutterCost = 5;
	int32 TerrainCost = ForestHex->TerrainCost;
	int32 TotalCost = WoodcutterCost + TerrainCost;

	TestHelper.LogInfo(FString::Printf(TEXT("Unit Cost: £%d"), WoodcutterCost));
	TestHelper.LogInfo(FString::Printf(TEXT("Terrain Cost: £%d"), TerrainCost));
	TestHelper.LogInfo(FString::Printf(TEXT("Total Cost: £%d"), TotalCost));

	AUnit* Woodcutter = World->SpawnActor<AUnit>();
	Woodcutter->UnitType = EUnitType::Woodcutter;
	Woodcutter->UnitCost = WoodcutterCost;
	Woodcutter->RequiredTerrain.Add(ETerrainType::Forest);
	Woodcutter->GeneratesIncome = 4;

	if (Woodcutter->CanPlaceOnTerrain(ForestHex))
	{
		if (Player->SpendGold(TotalCost))
		{
			ForestHex->PlaceUnit(Woodcutter, Player);
			Player->AddUnit(Woodcutter);
			Player->AddHex(ForestHex);

			TestHelper.LogStateChange(TEXT("Player Gold"), FString::FromInt(InitialGold), FString::FromInt(Player->Gold));
		}
	}

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->Gold, 12, TEXT("Player Gold = £12 (£20 - £8)"));
	bSuccess &= TestHelper.AssertEqual(Player->OwnedUnits.Num(), 1, TEXT("Player has 1 unit"));
	bSuccess &= TestHelper.AssertEqual(ForestHex->bIsOccupied, true, TEXT("Forest is occupied"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}
