# Contracts Module - C++ Classes

## Overview

C++ data asset for contract definitions and component for contract management.

## Classes

### UContractDefinition

**Purpose:**
Data asset defining export contract requirements, rewards, and types.

**State:**
- ContractName (FText)
- RequiredResources (TMap<EResourceType, int32>) - Resources needed
- GoldReward (int32)
- ImportGoodReward (EResourceType) - Cotton, Tobacco, etc.
- ImportGoodAmount (int32)
- VictoryPoints (int32)
- ContractIcon (UTexture2D*)

**Events:**
- None (pure data)

### UContractManagerComponent

**Purpose:**
Component attached to GameState. Manages available contracts and fulfillment.

**State:**
- AvailableContracts (TArray<UContractDefinition*>) - Current contract pool
- FulfilledContracts (TMap<ATLPlayerState*, TArray<UContractDefinition*>>)

**Events:**
- OnContractTaken (ATLPlayerState* Player, UContractDefinition* Contract)
- OnContractFulfilled (ATLPlayerState* Player, UContractDefinition* Contract)
- OnContractsRefreshed

## Contract Data Assets

Documented in `Content/Contracts/`:
- DA_Contract_WoolExport
- DA_Contract_CheeseExport
- DA_Contract_WhiskyExport
- etc.

Each data asset configures contract requirements and rewards.

## Related Modules

- **Resources** - Contracts require resources
- **GameFlow** - GameState holds contract manager
- **Lords** - Aldric gets contract bonuses
