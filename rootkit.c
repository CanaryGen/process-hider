#include <windows.h>
#include <tlhelp32.h>
#include <string.h>

// Function to hide a process by its executable path
void HideProcessByPath(const char* pathToHide) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe)) {
        do {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe.th32ProcessID);
            if (hProcess != NULL) {
                MODULEENTRY32 me;
                me.dwSize = sizeof(MODULEENTRY32);
                if (Module32First(hSnapshot, &me)) {
                    do {
                        if (strcmp(me.szExePath, pathToHide) == 0) {
                            // Modify the PID in the structure to hide the process
                            pe.th32ProcessID = 0;
                        }
                    } while (Module32Next(hSnapshot, &me));
                }
                CloseHandle(hProcess);
            }
        } while (Process32Next(hSnapshot, &pe));
    }

    CloseHandle(hSnapshot);
}

int main() {
    // Path to the executable of the process we want to hide
    const char* pathToHide = "C:\\Path\\To\\Executable.exe"; // Replace with the actual path

    // Hide the process
    HideProcessByPath(pathToHide);

    return 0;
}
