# GameFlow Module - C++ Classes

## Overview

Core Unreal Engine classes for game management, state tracking, and player control.

## Classes

### ATLGameMode

**Purpose:**
Manages game setup, rules, and round progression.

**State:**
- NumPlayers (int32)
- CurrentRound (int32)
- MaxRounds (int32)
- GamePhase (EGamePhase) - Setup, Action, Production, End
- TurnOrder (TArray<ATLPlayerState*>)

**Events:**
- OnGameStart
- OnRoundStart (int32 Round)
- OnRoundEnd (int32 Round)
- OnPhaseChanged (EGamePhase NewPhase)
- OnGameEnd

### ATLGameState

**Purpose:**
Replicates game-wide state. Holds market, contracts, and shared game data.

**State:**
- CurrentRound (int32)
- CurrentPhase (EGamePhase)
- MarketComponent (UMarketComponent*)
- ContractManager (UContractManagerComponent*)
- AvailableLords (TArray<ULordDefinition*>) - For lord selection
- HexGrid (TArray<AHexTile*>) - All hex tiles on board

**Events:**
- OnMarketUpdated
- OnContractsRefreshed
- OnPhaseChanged (EGamePhase NewPhase)

### ATLPlayerState

**Purpose:**
Tracks per-player state including resources, gold, units, lord, and progress.

**State:**
- Gold (int32)
- ResourceStock (TMap<EResourceType, int32>)
- SelectedLord (ULordDefinition*)
- OwnedUnits (TArray<AUnit*>)
- OwnedHexes (TArray<AHexTile*>)
- ShippingComponent (UShippingComponent*)
- AvailableMerchants (int32)
- UsedMerchants (int32)
- ActiveContracts (TArray<UContractDefinition*>)
- VictoryPoints (int32)

**Events:**
- OnGoldChanged (int32 NewGold)
- OnResourceChanged (EResourceType Resource, int32 NewAmount)
- OnUnitAcquired (AUnit* Unit)
- OnContractTaken (UContractDefinition* Contract)
- OnContractFulfilled (UContractDefinition* Contract)
- OnVictoryPointsChanged (int32 NewVP)

### ATLPlayerController

**Purpose:**
Handles player input, UI interaction, and action requests.

**State:**
- SelectedHex (AHexTile*)
- SelectedUnit (AUnit*)
- CurrentAction (EPlayerAction) - PlaceUnit, Trade, TakeContract, etc.

**Events:**
- OnHexClicked (AHexTile* Hex)
- OnUnitSelected (AUnit* Unit)
- OnActionConfirmed (EPlayerAction Action)
- OnTurnEnd

## Enums

### EGamePhase

**Values:**
- Setup
- LordSelection
- Action
- Production
- EndRound
- GameEnd

### EPlayerAction

**Values:**
- PlaceUnit
- BuyResource
- SellResource
- TakeContract
- FulfillContract
- UpgradeShipping
- EndTurn

## Related Modules

All modules connect through GameFlow:
- **Lords** - PlayerState references lord
- **Units** - PlayerState owns units
- **Hexes** - GameState holds hex grid
- **Resources** - PlayerState tracks resources
- **Market** - GameState holds market
- **Contracts** - GameState holds contracts
- **Shipping** - PlayerState has shipping
