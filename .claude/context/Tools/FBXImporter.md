# FBX Importer Tool

## Purpose

Import FBX files into Unreal Engine using Python remote execution.

## Location

`Tools/Python/import_fbx.py`

## Implementation

Uses Unreal Engine's `AssetImportTask` and `AssetTools` API via remote execution to import FBX files with configurable options.

## Usage

### Command Line

```bash
python Tools/Python/import_fbx.py <fbx_path> <destination_path> [options]
```

### Parameters

- `fbx_path` - Path to FBX file (absolute or relative to project root)
- `destination_path` - Unreal content path (e.g., `/Game/Assets/Models`)

### Options

| Option | Description | Default |
|--------|-------------|---------|
| `--skeletal` | Import as skeletal mesh | False (static mesh) |
| `--animations` | Import animations | False |
| `--no-textures` | Skip texture import | False (imports textures) |
| `--no-materials` | Skip material import | False (imports materials) |
| `--combine-meshes` | Combine meshes into single asset | False |
| `--no-collision` | Skip auto-generating collision | False (generates collision) |
| `--morph-targets` | Import morph targets (skeletal only) | False |

## Examples

```bash
# Import static mesh with default settings
python import_fbx.py Assets/table.fbx /Game/Furniture

# Import skeletal mesh with animations
python import_fbx.py Characters/hero.fbx /Game/Characters --skeletal --animations

# Import without textures (faster for testing)
python import_fbx.py Models/building.fbx /Game/Buildings --no-textures
```

## Dependencies

- Unreal Engine with Python plugins enabled
- Remote execution configured in DefaultEngine.ini
- `unreal_remote.py` module

## Error Handling

- Validates FBX file exists before import
- Creates destination directory if missing
- Returns detailed error messages on failure
- Logs import progress to Unreal Engine Output Log

## Notes

- FBX path is resolved relative to project root if not absolute
- Destination path must use Unreal format: `/Game/...`
- Git Bash path conversion is automatically handled
- Check Unreal Output Log for detailed import results
