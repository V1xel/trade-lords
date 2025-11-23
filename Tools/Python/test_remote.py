import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def test_connection():
    print("Testing remote execution connection to Unreal Engine...")
    print("-" * 60)

    executor = UnrealRemoteExecutor()

    if executor.connect():
        print("\nConnection successful!")
        print("-" * 60)

        print("\nTesting simple command...")
        result = executor.execute("print('Hello from remote Python!')")

        print("\n" + "=" * 60)
        if result.get('success'):
            print("SUCCESS: Remote execution is working!")
        else:
            print("ERROR: Command failed")
            print(f"Result: {result}")

        executor.disconnect()
    else:
        print("\n" + "=" * 60)
        print("FAILED: Could not connect to Unreal Engine")
        print("\nTroubleshooting:")
        print("  1. Ensure Unreal Editor is running")
        print("  2. Check Python plugin is enabled")
        print("  3. Verify remote execution is enabled in Editor Preferences")


if __name__ == '__main__':
    test_connection()
