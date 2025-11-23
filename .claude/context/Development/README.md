# Development Documentation

Technical documentation for C++ development in the TL board game project.

## Overview

This folder contains C++ class definitions, module configuration, build system documentation, and coding standards for the TL project.

## Structure

- **CodingStandards.md** - Code style, naming conventions, and best practices
- **ModuleSetup.md** - Unreal Engine module configuration and dependencies
- **BuildSystem.md** - Build configuration and compilation settings
- **Classes/** - Individual class documentation
  - **GameTile.md** - Configurable game tile actor
  - **BlueprintGraphHelper.md** - Blueprint graph manipulation utilities

## Core Classes

### Game Logic
- **AGameTile** - Base actor class for hex tiles, handles tile properties and visualization

### Tools & Utilities
- **UBlueprintGraphHelper** - Blueprint function library for programmatic Blueprint editing via Python

## Module Dependencies

**Public Modules:**
- Core
- CoreUObject
- Engine
- InputCore
- EnhancedInput

**Editor-Only Modules:**
- UnrealEd
- BlueprintGraph
- Kismet
- KismetCompiler

## Key Technologies

- **Unreal Engine 5.6** - Game engine
- **C++** - Primary language (C++17 standard)
- **Blueprint** - Visual scripting (extended from C++)
- **Python** - Editor automation (via BlueprintGraphHelper)

## Development Workflow

1. C++ classes marked `UCLASS(Blueprintable)` serve as base classes
2. Blueprint classes extend C++ classes with data-driven configuration
3. Python scripts use BlueprintGraphHelper for automated Blueprint generation
4. All gameplay logic exposed to Blueprints via `UPROPERTY` and `UFUNCTION` macros

## Quick Reference

**File Locations:**
- C++ Source: `/Source/TL/`
- Header Files: `/Source/TL/*.h`
- Implementation: `/Source/TL/*.cpp`
- Build Configuration: `/Source/TL/TL.Build.cs`
- Target Configuration: `/Source/TL.Target.cs`, `/Source/TLEditor.Target.cs`

## Related Documentation

- **Content/** - Blueprint implementations of C++ classes
- **Tools/** - Python scripts that interact with C++ code
- **Gameplay/** - Game mechanics that use these classes
