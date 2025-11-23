# Unreal Engine Python Automation Tools

Python utilities for automating Unreal Engine workflows via remote execution.

## Setup

### 1. Enable Python Plugins in Unreal Engine

Enable these plugins (Edit → Plugins):
- Python Editor Script Plugin
- Editor Scripting Utilities
- Python Remote Execution

### 2. Configure Remote Execution

Add to `Config/DefaultEngine.ini`:
```ini
[/Script/PythonScriptPlugin.PythonScriptPluginSettings]
bRemoteExecution=True
RemoteExecutionMulticastGroupEndpoint=239.0.0.1:6766
RemoteExecutionMulticastBindAddress=0.0.0.0
RemoteExecutionSendBufferSizeBytes=2097152
RemoteExecutionReceiveBufferSizeBytes=2097152
RemoteExecutionMulticastTtl=0
```

### 3. Restart Unreal Engine

## Core Modules

### unreal_remote.py
Core remote execution module using official Unreal Engine Python API.
- Discovers Unreal Engine nodes via UDP multicast
- Establishes TCP command connection
- Executes Python code in running Unreal Editor

## Tools

### import_fbx.py
Import FBX files into Unreal Engine with configurable options.

**Usage:**
```bash
python import_fbx.py <fbx_path> <destination_path> [options]
```

**Examples:**
```bash
# Import static mesh
python import_fbx.py Assets/model.fbx /Game/Assets/Models

# Import skeletal mesh with animations
python import_fbx.py character.fbx /Game/Characters --skeletal --animations

# Import without textures
python import_fbx.py model.fbx /Game/Models --no-textures
```

**Options:**
- `--skeletal` - Import as skeletal mesh (default: static mesh)
- `--animations` - Import animations
- `--no-textures` - Skip texture import
- `--no-materials` - Skip material import
- `--combine-meshes` - Combine all meshes into single asset
- `--no-collision` - Skip auto-generating collision
- `--morph-targets` - Import morph targets (skeletal only)

### create_blueprint.py
Create Blueprint child classes with configured properties.

**Usage:**
```python
from create_blueprint import create_blueprint_with_properties

result = create_blueprint_with_properties(
    parent_class_path='/Script/TL.GameTile',
    blueprint_path='/Game/Blueprints/Tiles',
    blueprint_name='BP_MyTile',
    properties={
        'TileName': 'My Tile',
        'TileColor': (1.0, 0.0, 0.0, 1.0),  # Red
        'MovementCost': 2,
        'bCanStop': True
    }
)
```

**Property Types:**
- `bool` - Pass Python bool (True/False)
- `int32/float` - Pass Python int/float
- `FString` - Pass Python string
- `FLinearColor` - Pass tuple (R, G, B, A) with values 0.0-1.0

## Blueprint Graph Editing

For advanced Blueprint graph manipulation (adding nodes, connecting pins), use the C++ helper:

```python
import unreal

# Load Blueprint
bp = unreal.load_asset('/Game/Blueprints/MyBlueprint')

# Add Print String to BeginPlay
unreal.BlueprintGraphHelper.add_print_string_to_begin_play(
    bp,
    'Hello World!'
)

# Compile Blueprint
unreal.BlueprintGraphHelper.compile_blueprint(bp)
```

See `Source/TL/BlueprintGraphHelper.h` for available C++ functions.

## Architecture

### Remote Execution Flow

1. **Discovery**: Client sends UDP multicast ping to 239.0.0.1:6766
2. **Response**: Unreal Engine responds with pong containing node info
3. **Connection**: Client opens TCP connection for command execution
4. **Execution**: Python code sent over TCP, executed in Unreal
5. **Results**: Execution results returned via TCP

### Protocol

Uses official Unreal Engine remote_execution protocol:
- UDP multicast for node discovery
- TCP for reliable command execution
- JSON message format with magic header 'ue_py'

## Error Handling

**Connection Failed:**
- Ensure Unreal Engine is running
- Verify remote execution is enabled in DefaultEngine.ini
- Check firewall allows UDP/TCP on configured ports

**Import Failed:**
- Check FBX file exists and is readable
- Verify destination path format: `/Game/...` not `C:/...`
- Review Unreal Engine Output Log for detailed errors

**Property Setting Failed:**
- Ensure property names match C++ class (PascalCase)
- Verify property types are correct
- Check property is marked BlueprintReadWrite/EditAnywhere

## Best Practices

1. **Always check connection** before executing commands
2. **Use absolute paths** for file operations
3. **Verify assets exist** before attempting to load
4. **Compile Blueprints** after graph modifications
5. **Check Output Log** in Unreal Engine for detailed results

## Extending

To add new automation capabilities:

1. **Python-only features**: Extend existing modules or create new ones
2. **Graph editing**: Add functions to `BlueprintGraphHelper.cpp`
3. **Complex operations**: Create new C++ Blueprint Function Library

All C++ functions marked `UFUNCTION(BlueprintCallable)` are automatically callable from Python.

## Content Generation

### Generate All Content Assets

Create all Blueprints and Data Assets for the TL project:

```bash
python generate_all_content.py
```

This creates 39 assets:
- 5 Hex Tile Blueprints → `/Game/Hexes/`
- 10 Unit Blueprints → `/Game/Units/`
- 11 Resource Data Assets → `/Game/Resources/`
- 9 Lord Data Assets → `/Game/Lords/`
- 4 Contract Data Assets → `/Game/Contracts/`

### Generate Individual Modules

```bash
python generate_hexes.py       # Hex tiles only
python generate_units.py        # Units only
python generate_resources.py   # Resources only
python generate_lords.py        # Lords only
python generate_contracts.py   # Contracts only
```

### Test Remote Connection

```bash
python test_remote.py
```

Expected output:
```
Testing remote execution connection to Unreal Engine...
Connection successful!
SUCCESS: Remote execution is working!
```
