#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <locale>
#include <codecvt>

// Function to simulate a key press
void SendKey(WORD vkCode) {
    INPUT input = { INPUT_KEYBOARD, { 0 } };
    input.ki.wVk = vkCode;
    SendInput(1, &input, sizeof(INPUT));

    // Release the key
    ZeroMemory(&input, sizeof(INPUT));
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

// Function to simulate the Enter key press and release
void SendEnterKey() {
    INPUT inputs[2] = {};

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_RETURN;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_RETURN;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, inputs, sizeof(INPUT));
}

void SetConsoleTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void SetConsoleTitleWrapper(const wchar_t* title) {
    SetConsoleTitleW(title); // Use SetConsoleTitleW for wide strings
}

void SetConsoleAlwaysOnTop(HWND hwnd) {
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void openAndLog() {
    SetConsoleTextColor(10); // Green color code
    // Log message
    std::wcout << L"Opening settings..." << std::endl;
    SetConsoleTextColor(15); // Reset color to default

    // Open Windows Settings app
    ShellExecuteW(0, L"open", L"ms-settings:defaultapps", NULL, NULL, SW_SHOWNORMAL);
    Sleep(2000); // Wait for settings to load

    SetConsoleTextColor(10); // Green color code
    // Log message
    std::wcout << L"Navigating to browser section..." << std::endl;
    SetConsoleTextColor(15); // Reset color to default

    // Simulate navigation to the browser section
    for (int i = 0; i < 5; ++i) {
        SendKey(VK_TAB);
        Sleep(150); // Small delay for each tab key press
    }
    SendEnterKey();
    Sleep(150);

    SetConsoleTextColor(10); // Green color code
    // Log message
    std::wcout << L"Selecting the browser..." << std::endl;
    SetConsoleTextColor(15); // Reset color to default

    // Simulate selecting the browser (adjust as needed based on position)
    SendKey(VK_DOWN);  // Adjust if needed based on browser position
    Sleep(50);
    SendEnterKey();
    Sleep(150);

    SetConsoleTextColor(10); // Green color code
    // Log message
    std::wcout << L"Closing settings window..." << std::endl;
    SetConsoleTextColor(15); // Reset color to default

    // Close the Settings window
    HWND hwnd = FindWindowW(L"ApplicationFrameWindow", L"Settings");
    if (hwnd) {
        PostMessage(hwnd, WM_CLOSE, 0, 0);
    } else {
        SetConsoleTextColor(12); // Red color code
        std::wcerr << L"Error: Could not find the settings window." << std::endl;
        SetConsoleTextColor(15); // Reset color to default
    }

    SetConsoleTextColor(10); // Green color code
    // Log message
    std::wcout << L"Opening the browser..." << std::endl;
    SetConsoleTextColor(15); // Reset color to default

    // Launch the browser (using ShellExecuteW for wide characters)
    ShellExecuteW(0, L"open", L"C:\\Users\\YourUsername\\Path\\To\\browser.exe", NULL, NULL, SW_SHOWNORMAL); // Adjust path
}

// Function to close the console window after a specified delay
void CloseConsoleAfterDelay(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    FreeConsole(); // Close the console window
}

int main() {
    // Check if the program is already attached to a console
    if (GetConsoleWindow() == NULL) {
        // Create a new console window
        if (!AllocConsole()) {
            std::wcerr << L"Failed to create a new console." << std::endl;
            return 1; // Indicate failure
        }
        freopen("CONOUT$", "w", stdout); // Redirect stdout to the console
        freopen("CONOUT$", "w", stderr); // Redirect stderr to the console
    }

    // Set console title
    SetConsoleTitleWrapper(L"Set Browser as Default");

    // Set console window always on top
    HWND consoleHwnd = GetConsoleWindow();
    if (consoleHwnd) {
        SetConsoleAlwaysOnTop(consoleHwnd);
    }

    // Start a new thread for openAndLog
    std::thread logThread(openAndLog);

    // Wait for the thread to finish
    logThread.join();

    SetConsoleTextColor(12); // Red color code
    std::wcout << L"Browser set as default." << std::endl;
    SetConsoleTextColor(15); // Reset color to default

    // Close the console window after 5 seconds
    CloseConsoleAfterDelay(5);

    return 0;
}
