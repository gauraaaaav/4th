/*
Start program and print main process ID.

Initialize STARTUPINFO and PROCESS_INFORMATION.

Call CreateProcess() to start a child process.

If success ? print child PID.

Else ? print error.

Create a new thread (std::thread) to run a function that prints the current PID.

Print message from the main thread.

Wait for the thread to finish (join).

Close process/thread handles.

Print ending message and exit.
*/


#include <iostream>
#include <windows.h>    // For CreateProcess, GetCurrentProcessId
#include <thread>       // For std::thread

using namespace std;

// Function that thread will run
void threadFunction() {
    cout << "Thread running in process PID: " << GetCurrentProcessId() << endl;
}

int main() {
    cout << "Program started. Main PID: " << GetCurrentProcessId() << endl;

    // ---- Process creation using CreateProcess (Windows API) ----
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcess(
            NULL,            // Application name
            (LPSTR)"notepad.exe", // Example child process (opens Notepad)
            NULL, NULL, FALSE,
            0, NULL, NULL,
            &si, &pi)) 
    {
        cout << "Child process created with PID: " << pi.dwProcessId << endl;
    } else {
        cerr << "CreateProcess failed! Error: " << GetLastError() << endl;
    }

    // ---- Thread creation using std::thread (C++11) ----
    thread t(threadFunction);

    cout << "Hello from the main thread! PID: " << GetCurrentProcessId() << endl;

    // Wait for thread to finish
    t.join();

    cout << "Main process ending. PID: " << GetCurrentProcessId() << endl;

    // Close handles to child process
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
