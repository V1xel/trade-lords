"""
CLI tool to import FBX files into Unreal Engine via remote execution
"""

import os
import sys
import argparse

# Add current directory to path
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def main():
    parser = argparse.ArgumentParser(
        description='Import FBX files into Unreal Engine',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python import_fbx.py path/to/model.fbx /Game/Assets/Models
  python import_fbx.py model.fbx /Game/Assets --skeletal --animations
  python import_fbx.py model.fbx /Game/Assets --no-textures --no-collision

Note: Check Unreal Engine Output Log for import results (Window -> Developer Tools -> Output Log)
        """
    )

    parser.add_argument(
        'fbx_path',
        help='Path to FBX file (absolute or relative to project root)'
    )

    parser.add_argument(
        'destination',
        help='Unreal Engine content path (e.g., /Game/Assets/Models)'
    )

    parser.add_argument(
        '--skeletal',
        action='store_true',
        help='Import as skeletal mesh (default: static mesh)'
    )

    parser.add_argument(
        '--animations',
        action='store_true',
        help='Import animations (only for skeletal meshes)'
    )

    parser.add_argument(
        '--no-textures',
        action='store_true',
        help='Skip texture import'
    )

    parser.add_argument(
        '--no-materials',
        action='store_true',
        help='Skip material import'
    )

    parser.add_argument(
        '--combine-meshes',
        action='store_true',
        help='Combine all meshes into single asset'
    )

    parser.add_argument(
        '--no-collision',
        action='store_true',
        help='Skip auto-generating collision'
    )

    parser.add_argument(
        '--morph-targets',
        action='store_true',
        help='Import morph targets (skeletal meshes only)'
    )

    parser.add_argument(
        '--multicast-group',
        default='239.0.0.1',
        help='Multicast group address (default: 239.0.0.1)'
    )

    parser.add_argument(
        '--multicast-port',
        type=int,
        default=6766,
        help='Multicast port (default: 6766)'
    )

    args = parser.parse_args()

    # Resolve FBX path
    fbx_path = args.fbx_path
    if not os.path.isabs(fbx_path):
        # Try relative to project root
        project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
        fbx_path = os.path.join(project_root, fbx_path)

    # Validate FBX exists
    if not os.path.exists(fbx_path):
        print(f"ERROR: FBX file not found: {fbx_path}")
        return 1

    # Fix Git Bash path conversion for Unreal content paths
    # Git Bash converts /Game/... to C:/Program Files/Git/Game/...
    destination = args.destination
    if 'Program Files/Git/Game' in destination or 'Program_Files/Git/Game' in destination:
        # Extract the /Game/... part
        destination = '/Game' + destination.split('/Game', 1)[1]

    print(f"FBX file: {fbx_path}")
    print(f"Destination: {destination}")

    # Build import options
    options = {
        'import_mesh': True,
        'import_textures': not args.no_textures,
        'import_materials': not args.no_materials,
        'import_animations': args.animations,
        'skeletal_mesh': args.skeletal,
        'combine_meshes': args.combine_meshes,
        'auto_generate_collision': not args.no_collision,
        'import_morph_targets': args.morph_targets
    }

    print(f"Import options: {options}")

    # Connect to Unreal Engine
    executor = UnrealRemoteExecutor(
        multicast_group=args.multicast_group,
        multicast_port=args.multicast_port
    )

    print(f"\nConnecting to Unreal Engine multicast {args.multicast_group}:{args.multicast_port}...")
    if not executor.connect():
        print("\nERROR: Could not create multicast socket.")
        print("Make sure:")
        print("1. Unreal Engine is running")
        print("2. Python Remote Execution plugin is enabled")
        print("3. Remote execution is configured in Config/DefaultEngine.ini:")
        print("   [/Script/PythonScriptPlugin.PythonScriptPluginSettings]")
        print("   bRemoteExecution=True")
        print(f"   RemoteExecutionMulticastGroupEndpoint={args.multicast_group}:{args.multicast_port}")
        return 1

    # Import FBX
    print("\nImporting FBX...")
    result = executor.import_fbx_remote(fbx_path, destination, options)

    if result.get('success'):
        print(f"\n[SUCCESS] Import command sent!")
        print(f"Result: {result.get('result')}")
        print(f"\nCheck Unreal Engine Output Log (Window -> Developer Tools -> Output Log) for import results.")
        executor.disconnect()
        return 0
    else:
        print(f"\n[FAILED] Import failed!")
        print(f"Error: {result.get('result')}")
        executor.disconnect()
        return 1


if __name__ == "__main__":
    sys.exit(main())
