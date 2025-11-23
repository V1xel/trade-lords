# Tests Documentation

Test scenarios for validating game mechanics.

## Overview

Each test file documents a specific mechanic test with:
- **Initial State** - Game and player state before test
- **Events** - Sequence of actions/events
- **State Changes** - Expected state after each event
- **Final State** - Verification of end state

## Test Categories

### Placement Tests
- Test_PlaceUnit_Basic.md
- Test_PlaceUnit_Adjacency.md
- Test_PlaceUnit_TerrainCost.md
- Test_PlaceUnit_InvalidTerrain.md

### Production Tests
- Test_Production_BasicGoods.md
- Test_Production_Processing.md
- Test_Production_WorkerIncome.md

### Market Tests
- Test_Market_BuyResource.md
- Test_Market_SellResource.md
- Test_Market_PriceChange.md

### Contract Tests
- Test_Contract_TakeContract.md
- Test_Contract_FulfillContract.md
- Test_Contract_ContractCost.md

### Lord Ability Tests
- Test_Lord_Aldric_DualContracts.md
- Test_Lord_Godwyn_WhiskyAging.md
- Test_Lord_Isolde_MarketTrading.md
- Test_Lord_Bertram_FactoryCost.md
- Test_Lord_Elspeth_MilkSelling.md
- Test_Lord_Roderick_Workers.md
- Test_Lord_Caspian_Fisherman.md
- Test_Lord_Marina_RiverDelta.md
- Test_Lord_Oswald_BeerProduction.md

### Shipping Tests
- Test_Shipping_UpgradeLevel.md
- Test_Shipping_WaterPlacement.md

### GameFlow Tests
- Test_GameFlow_RoundProgression.md
- Test_GameFlow_PhaseTransitions.md
- Test_GameFlow_VictoryPoints.md

## Test Format

```markdown
# Test_Name

**Purpose:** What mechanic this tests

## Initial State

**Game State:**
- Round: X
- Phase: Y
- Available contracts: [...]

**Player State:**
- Gold: £X
- Resources: {resource: amount}
- Units: [unit list]
- Owned Hexes: [hex list]

## Events

### Event 1: Action Name

**Action:** Description of action taken

**State Changes:**
- Property: old_value → new_value

**Expected State:**
- Updated property values

### Event 2: Next Action

...

## Final State Verification

**Player State:**
- All final property values

**Assertions:**
- Specific checks to verify correct behavior
```

## Related Documentation

- **Gameplay/** - Mechanics being tested
- **Scenarios/** - Complex gameplay flows
- **Development/** - C++ implementation to test
