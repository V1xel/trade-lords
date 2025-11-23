# Tools

Definitions for AI interaction with Unreal Engine.

## Overview

This folder contains tool definitions and documentation for automating Unreal Engine workflows through Python remote execution.

## Available Tools

### [FBXImporter](FBXImporter.md)
Command-line tool for importing FBX files into Unreal Engine with configurable import options.

**Use Cases:**
- Batch import 3D models
- Automated asset pipeline
- Testing with placeholder meshes

### [BlueprintCreator](BlueprintCreator.md)
Programmatic Blueprint asset creation with property configuration.

**Use Cases:**
- Generate Blueprint variants from C++ classes
- Automated level design workflows
- Data-driven asset generation

### [BlueprintGraphHelper](BlueprintGraphHelper.md)
C++ helper library for Blueprint graph manipulation exposed to Python.

**Use Cases:**
- Add nodes to Blueprint event graphs
- Connect Blueprint logic programmatically
- Automate repetitive Blueprint tasks

## Implementation Location

Python scripts: `Tools/Python/`
- `unreal_remote.py` - Core remote execution module
- `import_fbx.py` - FBX import tool
- `create_blueprint.py` - Blueprint creation tool

C++ helpers: `Source/TL/`
- `BlueprintGraphHelper.h/cpp` - Graph manipulation library

## Architecture

All tools use Python remote execution to communicate with running Unreal Editor:

```
Python Script → Remote Execution → Unreal Engine Python API → C++ Functions
```

For operations not exposed by Python API, C++ helpers bridge the gap:

```
Python → unreal.BlueprintGraphHelper → C++ K2Node APIs
```

## Adding New Tools

### Pure Python Tools

1. Create Python script in `Tools/Python/`
2. Use `unreal_remote.py` for remote execution
3. Document in this folder as `.md` file

### C++ Helper Tools

1. Create C++ class inheriting `UBlueprintFunctionLibrary`
2. Mark functions with `UFUNCTION(BlueprintCallable)`
3. Add required modules to `TL.Build.cs`
4. Compile and use from Python via `unreal.ClassName.function_name()`
5. Document implementation and usage

## Dependencies

- Unreal Engine 5.6+
- Python 3.x
- Python plugins enabled in Unreal Engine
- Remote execution configured
- Official Unreal Engine Python API

## Best Practices

1. Keep tools focused on single responsibility
2. Provide clear error messages
3. Log operations for debugging
4. Document parameters and return values
5. Handle edge cases gracefully
6. Test with running Unreal Editor
