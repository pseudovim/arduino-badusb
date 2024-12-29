Arduino Persistent Reverseshell BadUSB
  A project that uses an Arduino microcontroller to automate keyboard inputs for specific tasks, including creating and running a .bat script on a Windows system.

Description
  This project leverages the Keyboard.h library to emulate a USB keyboard. It automates a series of steps on a Windows computer, including:
  Opening the Run dialog.
  Creating and saving a .bat file.
  Running the script and configuring it to execute on startup.
  Features
  Simulates keypresses to interact with Windows.
  Types out a predefined script.
  Automates file saving and application control.

Prerequisites
  1. An Arduino board (e.g., Arduino Leonardo, Arduino Micro) with HID support.
  2. Arduino IDE installed on your computer.
  3. The Keyboard library (pre-installed with Arduino IDE).
   
Setup Instructions
  1. Clone or download this repository to your local machine.
  2. Open the .ino file in the Arduino IDE.
  3. Connect your Arduino board to your computer via USB.
  4. Upload the script to your Arduino.
   
Usage
  Once the script is uploaded, ensure the Arduino is connected to your computer.
  The script will start after a short delay (2 seconds).
  Watch as the Arduino automates the steps to create and run the .bat script.
  
How It Works
  Keyboard Simulation: The script uses the Keyboard.h library to emulate a USB keyboard and simulate keypresses.
  Automated Typing: It types out a predefined script character-by-character with precise delays.
  File Saving: The script saves the .bat file to a specified location on your computer.
  Startup Shortcut: It creates a shortcut in the Windows Startup folder to ensure the script runs automatically.
