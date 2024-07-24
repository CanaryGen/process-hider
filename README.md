# Process Hider by Executable Path

This is a simple example of how to hide a process by its executable path using Windows API functions. This code is for educational purposes only and should not be used for any malicious activities.

## How It Works

1. **CreateToolhelp32Snapshot**: Takes a snapshot of the current processes and modules.
2. **Process32First/Process32Next**: Iterates through the list of processes.
3. **OpenProcess**: Opens a handle to the process.
4. **Module32First/Module32Next**: Iterates through the modules of the process.
5. **strcmp**: Compares the executable path of the module with the path to hide.
6. **Modify PID**: If the path matches, the PID of the process is modified to hide it.

## Usage

1. Replace `pathToHide` with the actual path to the executable of the process you want to hide.
2. Compile the code using a C compiler that supports Windows API.
3. Run the compiled executable.

## Important Notes

- This example is simplified and does not achieve complete process hiding.
- Use this code responsibly and only in environments where you have permission to test.
- Unauthorized use of this code for hiding processes on other systems is illegal and unethical.

## Note

This project is for educational purposes only. Use at your own risk.
