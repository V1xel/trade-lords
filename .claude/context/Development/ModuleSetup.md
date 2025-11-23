# Module Setup

Organization of C++ modules matching gameplay systems.

## Module Structure

```
Source/TL/
├── TL.Build.cs          # Module dependencies
├── TL.h, TL.cpp         # Module definition
├── Lords/               # Lord system
├── Units/               # Unit actors
├── Hexes/               # Hex tile actors
├── Resources/           # Resource data
├── Market/              # Market component
├── Contracts/           # Contract system
├── Shipping/            # Shipping component
└── GameFlow/            # Core UE classes
```

## Unreal Engine Modules

### Public Dependencies

```csharp
PublicDependencyModuleNames.AddRange(new string[] {
    "Core",
    "CoreUObject",
    "Engine",
    "InputCore",
    "EnhancedInput"
});
```

**Core** - Basic types, containers
**CoreUObject** - UObject, reflection system
**Engine** - Actors, Components, GameMode, etc.
**InputCore** - Input bindings
**EnhancedInput** - Modern input system

### Editor Dependencies

```csharp
if (Target.bBuildEditor)
{
    PrivateDependencyModuleNames.AddRange(new string[] {
        "UnrealEd",
        "BlueprintGraph",
        "Kismet",
        "KismetCompiler"
    });
}
```

**UnrealEd** - Editor functionality
**BlueprintGraph** - Blueprint graph editing
**Kismet** - Blueprint utilities
**KismetCompiler** - Blueprint compilation

Used by BlueprintGraphHelper for Python automation.

## Module Organization

### By Gameplay System

Each gameplay module maps to C++ code:

**Gameplay/Lords** → **Development/Lords**
- ULordDefinition data assets
- Lord abilities and properties

**Gameplay/Units** → **Development/Units**
- AUnit base actor
- Unit types, production, workers

**Gameplay/Hexes** → **Development/Hexes**
- AHexTile base actor
- Terrain types, placement

**Gameplay/Resources** → **Development/Resources**
- UResourceDefinition data assets
- FResourceStock struct

**Gameplay/Market** → **Development/Market**
- UMarketComponent
- Dynamic pricing

**Gameplay/Contracts** → **Development/Contracts**
- UContractDefinition data assets
- UContractManagerComponent

**Gameplay/Shipping** → **Development/Shipping**
- UShippingComponent
- Shipping levels

**Gameplay/GameFlow** → **Development/GameFlow**
- ATLGameMode
- ATLGameState
- ATLPlayerState
- ATLPlayerController

## Class Naming

### Prefixes

**A** - Actors
- AHexTile
- AUnit
- ATLGameMode
- ATLGameState
- ATLPlayerState
- ATLPlayerController

**U** - Components, Objects, Data Assets
- UMarketComponent
- UShippingComponent
- UContractManagerComponent
- ULordDefinition
- UResourceDefinition
- UContractDefinition

**F** - Structs
- FResourceStock
- FMarketPriceSnapshot

**E** - Enums
- EResourceType
- ETerrainType
- EUnitType
- EGamePhase
- EPlayerAction

## Dependencies Between Modules

```
GameFlow
├── Lords (PlayerState references lord)
├── Units (PlayerState owns units)
├── Hexes (GameState holds grid)
├── Resources (PlayerState tracks resources)
├── Market (GameState holds market)
├── Contracts (GameState holds contracts)
└── Shipping (PlayerState has shipping)
```

**GameFlow** is the central hub - other modules are self-contained.

## Blueprint Integration

### Base C++ Classes

Marked `UCLASS(Blueprintable)`:
- AHexTile
- AUnit

Extended in Blueprint with data configuration.

### Data Assets

Marked `UCLASS(Blueprintable)`:
- ULordDefinition
- UResourceDefinition
- UContractDefinition

Created as individual assets in Content Browser.

### Components

Added to core classes:
- UMarketComponent → ATLGameState
- UContractManagerComponent → ATLGameState
- UShippingComponent → ATLPlayerState

## Summary

- Code organized by gameplay systems
- Matches Gameplay documentation structure
- Simple dependencies through GameFlow
- Blueprint extension for configuration
- Data assets for content
