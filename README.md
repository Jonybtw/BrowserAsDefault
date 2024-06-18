# Set Browser as Default

This C++ application automates setting any browser as the default on Windows systems using UI manipulation without altering policies or registry settings directly. It is designed for use on restricted PCs where modifying system policies or registry entries is not allowed.

## Features

- **Automation**: Opens Windows Settings, navigates to the default apps section, selects the specified browser, and launches it.
- **Console UI**: Displays messages in different colors (green for success, red for errors) using `SetConsoleTextColor`.
- **Console Management**: Sets console title using `SetConsoleTitleWrapper` and keeps the console window always on top with `SetConsoleAlwaysOnTop`.
- **Multithreading**: Uses `std::thread` to perform tasks concurrently.
- **Delay and Close**: Automatically closes the console window after completing the task.

![image](https://github.com/Jonybtw/FirefoxAsDefault/assets/84144569/9627fb50-bf2e-4110-bbce-c5ddb6ab582a)

## Why Use This Program?

- **Suitable for Restricted PCs**: It operates within the confines of restricted policies by avoiding direct modifications to system settings.
- **Ease of Use**: Simplifies the process for users who frequently need to set a browser as default due to policy restrictions that may reset defaults.
- **Flexibility**: Supports setting any browser as default, not limited to Firefox or a specific browser.
- **Reliability**: Provides a consistent method to set a browser as default without requiring repeated manual intervention.

## "The default browser always resets on boot. How can I ensure it's set as default every time my PC boots?"

To ensure the application runs on startup:

1. **Create a Shortcut**: 
   - Right-click on the compiled executable (`YourApplication.exe`) and select "Create Shortcut".
   - Move the shortcut to the desired location (e.g., Desktop).

2. **Add to Startup Folder**: 
   - Press `Win + R` to open the Run dialog.
   - Type `shell:startup` and press Enter.
   - Copy the shortcut into this folder.

3. **Verify on Startup**: 
   - Restart your computer to verify that the application launches automatically after login.

By following these steps, the application will start automatically whenever the user logs into Windows, ensuring the browser is set as default without manual intervention.

**Note**: Ensure that the application's behavior on startup aligns with your system policies and user preferences.

## Important: 
  - Before building the application, ensure you update the path to the browser executable in the code (`openAndLog` function).
    
![image](https://github.com/Jonybtw/FirefoxAsDefault/assets/84144569/3cc9f55b-f700-4add-aaeb-7260c44d2fb6)

  - You may also need to adjust the number of times the down key (`VK_DOWN`) is pressed based on the position of your preferred browser in the list.
    
![image](https://github.com/Jonybtw/FirefoxAsDefault/assets/84144569/55412b91-a7a3-41fb-bbd1-e79c76aba695)
    
  - The `FindWindowW` function used to locate the Settings window may require adjustment depending on the language of your operating system.

![image](https://github.com/Jonybtw/BrowserAsDefault/assets/84144569/c28a3f60-3357-4907-ae99-d2f6d145ba16)



