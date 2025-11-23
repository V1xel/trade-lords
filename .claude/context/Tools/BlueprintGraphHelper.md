# Blueprint Graph Helper

## Purpose

C++ Blueprint Function Library that exposes K2Node graph manipulation to Python, enabling programmatic Blueprint graph editing.

## Location

- Header: `Source/TL/BlueprintGraphHelper.h`
- Implementation: `Source/TL/BlueprintGraphHelper.cpp`

## Why C++?

The official Unreal Engine Python API has limited Blueprint graph editing capabilities. Direct node manipulation (adding nodes, connecting pins) requires C++ access to:
- `K2Node` classes (BeginPlay, CallFunction, etc.)
- `EdGraph` and `EdGraphPin` manipulation
- `FBlueprintEditorUtils` for graph modification

This helper library exposes these C++ capabilities to Python via `UFUNCTION(BlueprintCallable)`.

## Available Functions

### AddPrintStringToBeginPlay

Add a Print String node connected to BeginPlay event.

```python
import unreal

bp = unreal.load_asset('/Game/Blueprints/MyBlueprint')
result = unreal.BlueprintGraphHelper.add_print_string_to_begin_play(
    bp,
    'Hello World!'
)
```

**Parameters:**
- `Blueprint` - UBlueprint pointer to modify
- `PrintText` - String to print

**Returns:** `bool` - True if successful

### AddCustomEvent

Add a custom event node to Blueprint.

```python
result = unreal.BlueprintGraphHelper.add_custom_event(
    bp,
    'OnCustomEvent'
)
```

**Parameters:**
- `Blueprint` - UBlueprint pointer to modify
- `EventName` - Name of custom event

**Returns:** `bool` - True if successful

### CompileBlueprint

Compile Blueprint after modifications.

```python
result = unreal.BlueprintGraphHelper.compile_blueprint(bp)
```

**Parameters:**
- `Blueprint` - UBlueprint pointer to compile

**Returns:** `bool` - True if compilation successful

## Implementation Details

### Node Creation Process

1. Find or create EventGraph in Blueprint's `UbergraphPages`
2. Create K2Node (e.g., `UK2Node_Event`, `UK2Node_CallFunction`)
3. Configure node properties (function reference, event type, etc.)
4. Add node to graph
5. Allocate default pins
6. Position node
7. Connect pins using `MakeLinkTo()`
8. Mark Blueprint as structurally modified
9. Compile if needed

### Key Classes Used

- `UK2Node_Event` - Event nodes (BeginPlay, custom events)
- `UK2Node_CallFunction` - Function call nodes (Print String)
- `UEdGraph` - Graph container
- `UEdGraphPin` - Node connection pins
- `FBlueprintEditorUtils` - Blueprint modification utilities
- `FKismetEditorUtilities` - Compilation utilities

## Module Dependencies

Requires these modules in `TL.Build.cs`:
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

## Extending

To add new graph manipulation functions:

1. Declare function in `BlueprintGraphHelper.h` with `UFUNCTION(BlueprintCallable)`
2. Implement in `BlueprintGraphHelper.cpp` using K2Node APIs
3. Recompile C++ code
4. Function automatically available in Python as `unreal.BlueprintGraphHelper.function_name()`

## Best Practices

1. Always check Blueprint pointer is valid
2. Find EventGraph before modifying
3. Call `MarkBlueprintAsStructurallyModified()` after changes
4. Compile Blueprint after graph modifications
5. Log actions for debugging
6. Return success/failure boolean for error handling

## Limitations

- Only works in Editor builds (bBuildEditor = true)
- Requires Unreal Editor to be running
- Cannot undo graph changes (use version control)
- Complex graphs may require multiple function calls
