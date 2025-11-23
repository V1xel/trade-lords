# Coding Standards

Clean, minimalistic C++ code standards for the TL project.

## Core Philosophy

**No Comments**
- Code should be self-documenting
- Documentation lives in `.claude/context/`, not in code
- Gameplay functionality documented in `Gameplay/` folder
- Integration patterns documented in `Scenarios/` folder

**Simple Architecture**
- Actors for game entities
- Components for reusable behavior
- Data Assets for configuration
- Base UE classes: GameMode, GameState, PlayerState, PlayerController
- No unnecessary abstractions or layers

**Modular Organization**
- Code organized by gameplay systems
- Matches gameplay documentation structure
- Clear separation by domain

## Module Structure

```
Lords/     → Lord actors and data
Units/     → Unit actors (Sheep, Cow, Field, etc.)
Hexes/     → HexTile actor
Resources/ → Resource data assets
Market/    → Market system
Contracts/ → Contract system and data
Shipping/  → Shipping mechanics
GameFlow/  → GameMode, GameState, turn management
```

## Class Types

**Actors** - Things that exist in the world
- HexTile (base class, Blueprint variants: Grassland, Forest, Mountain, etc.)
- Unit (base class, Blueprint variants: Sheep, Cow, Field, etc.)
- Lord (player representation)

**Components** - Reusable behavior
- Only when behavior is shared across multiple actors

**Data Assets** - Configuration data
- ResourceDefinition
- ContractDefinition
- LordDefinition

**Core UE Classes**
- GameMode - Game setup, rules
- GameState - Game-wide state (market, contracts, round)
- PlayerState - Per-player state (gold, resources, lord, units)
- PlayerController - Player input and actions

## Blueprint Integration

**C++ Base Classes**
- Marked `UCLASS(Blueprintable)`
- Expose properties with `UPROPERTY(EditAnywhere, BlueprintReadWrite)`
- Expose functions with `UFUNCTION(BlueprintCallable)`
- Minimal logic in C++, configuration in Blueprint

**Blueprint Variants**
- Derive from C++ base
- Configure different data (e.g., HexTile_Grassland, HexTile_Forest)
- Documented in `Content/` folder, not `Development/`

## Naming Conventions

**Prefixes:**
- `A` - Actors (AHexTile, AUnit, ALord)
- `U` - Components, Objects (UResourceDefinition)
- `F` - Structs (FResourceStock, FContractReward)
- `E` - Enums (ETerrainType, EResourceType)
- `b` - Booleans (bIsPassable, bCanStop)

**Categories:**
Match gameplay systems:
- `Lords`, `Units`, `Hexes`, `Resources`, `Market`, `Contracts`, `Shipping`, `GameFlow`

## Code Style

**Clean and minimal:**
```cpp
AHexTile::AHexTile()
{
    PrimaryActorTick.bCanEverTick = false;

    TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
    RootComponent = TileMesh;

    TerrainCost = 1;
    bIsOccupied = false;
}
```

**Simple logic:**
- One purpose per function
- Early returns for checks
- Minimal nesting
- Self-explanatory names

## Documentation Strategy

Documentation is separate from code:

1. **Gameplay docs** (`.claude/context/Gameplay/`) - What the system does
2. **Development docs** (`.claude/context/Development/Classes/`) - C++ class purpose, state, events
3. **Content docs** (`.claude/context/Content/`) - Blueprint implementations
4. **Scenario docs** (`.claude/context/Scenarios/`) - How systems work together

**Class documentation includes:**
- Purpose (what it is)
- State (properties it holds)
- Events (what it emits/receives)

**No implementation details in docs** - Keep it high-level

## Error Handling

Minimal logging:
```cpp
if (!Blueprint)
{
    UE_LOG(LogTemp, Error, TEXT("Blueprint is null"));
    return false;
}
```

Log only critical errors, not flow control.

## Summary

- Write clean, self-documenting code
- No comments in code
- Simple architecture: Actors, Components, Assets, Core UE classes
- Organize by gameplay modules
- Documentation separate from implementation
- Focus on state, purpose, events in docs
