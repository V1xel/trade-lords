# Lords Module - C++ Classes

## Overview

C++ data asset for lord definitions. Each lord configured as separate data asset with unique abilities and starting resources.

## Classes

### ULordDefinition

**Purpose:**
Data asset defining lord properties, abilities, and starting resources. Each of the 9 lords is a separate asset.

**State:**
- LordName (FText)
- LordTitle (FText)
- HouseColorPrimary (FLinearColor)
- HouseColorSecondary (FLinearColor)
- StartingGold (int32)
- StartingUnits (TArray<TSubclassOf<AUnit>>)
- StartingMerchants (int32)
- StartingShipping (int32)
- AbilityType (EAbilityType) - Passive, Triggered, Active
- AbilityDescription (FText)
- LordPortrait (UTexture2D*)

**Events:**
- OnAbilityTriggered
- OnLordSelected (ATLPlayerState* Player)

## Lord Data Assets

Documented in `Content/Lords/`:
- DA_Lord_Aldric
- DA_Lord_Godwyn
- DA_Lord_Isolde
- DA_Lord_Bertram
- DA_Lord_Elspeth
- DA_Lord_Roderick
- DA_Lord_Caspian
- DA_Lord_Marina
- DA_Lord_Oswald

Each data asset configures unique lord properties and abilities.

## Related Modules

- **GameFlow** - PlayerState references active lord
- **Units** - Starting units granted to player
- **Market** - Starting merchants affect trading
- **Shipping** - Starting shipping level
