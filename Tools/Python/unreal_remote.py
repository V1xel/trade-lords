"""
Unreal Engine Remote Execution Utility
Enables Python script execution in Unreal Engine from external processes
Uses the official remote_execution module from Unreal Engine
"""

import sys
import os
import time

# Add Unreal Engine's Python plugin path
UNREAL_PYTHON_PATH = r'C:\Program Files\Epic Games\UE_5.6\Engine\Plugins\Experimental\PythonScriptPlugin\Content\Python'
if UNREAL_PYTHON_PATH not in sys.path:
    sys.path.insert(0, UNREAL_PYTHON_PATH)

import remote_execution as ue_remote


class UnrealRemoteExecutor:
    """Executes Python commands in Unreal Engine via remote execution"""

    def __init__(self, multicast_group='239.0.0.1', multicast_port=6766):
        """
        Initialize remote executor

        Args:
            multicast_group (str): Multicast group address (default: 239.0.0.1)
            multicast_port (int): Multicast port (default: 6766)
        """
        config = ue_remote.RemoteExecutionConfig()
        config.multicast_group_endpoint = (multicast_group, multicast_port)
        self.remote_exec = ue_remote.RemoteExecution(config)
        self.connected_node = None

    def connect(self):
        """Start remote execution and discover nodes"""
        try:
            self.remote_exec.start()
            print(f"Started remote execution, discovering nodes...")

            # Wait for nodes to be discovered
            timeout = 30  # Increased timeout to 30 seconds
            start_time = time.time()
            last_msg_time = start_time

            while time.time() - start_time < timeout:
                nodes = self.remote_exec.remote_nodes

                # Print progress every 3 seconds
                if time.time() - last_msg_time > 3:
                    elapsed = int(time.time() - start_time)
                    print(f"  Still searching... ({elapsed}/{timeout}s)")
                    last_msg_time = time.time()

                if nodes:
                    # Connect to first available node
                    node = nodes[0]
                    node_id = node['node_id']
                    print(f"Found Unreal Engine node: {node.get('machine_name', node_id)}")
                    self.remote_exec.open_command_connection(node_id)
                    self.connected_node = node_id
                    print(f"Connected to node {node_id}")
                    return True
                time.sleep(0.1)

            print("No Unreal Engine nodes found after 30 seconds")
            print("Check that:")
            print("  - Unreal Editor is running")
            print("  - Python plugin is enabled")
            print("  - Remote execution is enabled in Project Settings")
            print("  - Windows Firewall allows Python.exe")
            return False

        except Exception as e:
            print(f"Failed to connect: {e}")
            return False

    def disconnect(self):
        """Close remote execution"""
        if self.remote_exec:
            self.remote_exec.stop()
            print("Disconnected from Unreal Engine")

    def execute(self, python_code):
        """
        Execute Python code in Unreal Engine

        Args:
            python_code (str): Python code to execute

        Returns:
            dict: Execution result with 'success' and 'result' keys
        """
        if not self.remote_exec.has_command_connection():
            if not self.connect():
                return {"success": False, "result": "Not connected to Unreal Engine"}

        try:
            # Execute command via official remote execution
            result = self.remote_exec.run_command(
                python_code,
                unattended=True,
                exec_mode=ue_remote.MODE_EXEC_FILE
            )

            print(f"Command executed")
            print(f"Success: {result.get('success')}")
            if result.get('result'):
                print(f"Result: {result.get('result')}")
            if result.get('output'):
                print(f"Output:")
                for output_item in result.get('output', []):
                    print(f"  [{output_item.get('type')}] {output_item.get('output')}")

            return result

        except Exception as e:
            return {"success": False, "result": f"Execution error: {e}"}

    def execute_file(self, python_file):
        """
        Execute Python file in Unreal Engine

        Args:
            python_file (str): Path to Python file

        Returns:
            dict: Execution result
        """
        try:
            with open(python_file, 'r') as f:
                python_code = f.read()
            return self.execute(python_code)
        except Exception as e:
            return {"success": False, "result": f"Failed to read file: {e}"}

    def import_fbx_remote(self, fbx_path, destination_path, options=None):
        """
        Import FBX file via remote execution

        Args:
            fbx_path (str): Full file system path to FBX file
            destination_path (str): Unreal content path
            options (dict): Import options

        Returns:
            dict: Import result
        """
        import os

        tools_path = os.path.abspath(os.path.dirname(__file__))
        options_str = str(options) if options else "None"

        code = f"""
import sys
sys.path.append(r'{tools_path}')

from fbx_importer import import_fbx

result = import_fbx(
    r'{fbx_path}',
    '{destination_path}',
    {options_str}
)

print(f"FBX Import result: {{result}}")
"""

        return self.execute(code)


# Example usage
if __name__ == "__main__":
    executor = UnrealRemoteExecutor()

    if executor.connect():
        # Example: Simple print command
        result = executor.execute("print('Hello from remote Python!')")
        print(f"Result: {result}")

        executor.disconnect()
    else:
        print("Failed to connect to Unreal Engine")
