# WaterCleanUp Bot (WaterOS)
This code is the firmware for the TrashZapper water-cleaning bot. It controls the bot's movement.

Latest version: 1.8

Download it with this command (make sure you have the CLI GIT installed):
```
git clone --recurse-submodules https://github.com/matthewyang204/WaterOS.git
```

No hardware build available yet.

Requirements:
Water Cleanup Bot Build #1 or later,
Arduino IDE 2.0 or later,
Windows 10 64-bit or later OR macOS 10.14 (Mojave) or later

macOS
-----

# Installation

1. Download the .zip source code and extract it.

2. Open the .ino file in Arduino IDE or upload it to the web editor.

3. Upload it to the arduino board on the bot.

# Usage
Interact with the bot through the Serial Monitor and use the Photo Booth to display the video camera's output to view where it is going.

# Game Controller Support
To install game controller support:

1. Download Enjoyable:

Apple Silicon Macs: https://github.com/matthewyang204/enjoyable-apple-silicon/releases/download/1.3/Enjoyable.zip

Intel Macs: https://github.com/shirosaki/enjoyable/releases/download/v1.2.1/Enjoyable-1.2.1.zip

2. Install them from the .zip. I built the Apple Silicon version myself, and have not signed it (paying $99 yearly is a torture). So if you have an Apple Silicon Mac, run `sudo spctl --master-disable` to disable gatekeeper before installing the app.

3. From the menu, click "Mappings > Import..." or press Command + O.

4. Now it's ready.

To use it:

1. Set up the serial monitor and wireless link stuff. More on that in the instructable.

2. Press the direction on the D-Pad you want to go. Note that 'down' sends the stop command.

3. Press the X button on your controller to send it to the bot. Holding down the D-Pad doesn't work.

Windows
-------

# Installation to bot

1. Download the .zip source code and extract it

2. Open the .ino file in WaterOS\ in Arduino IDE and upload it to your Arduino

# Usage
Interact with the bot through the Serial Monitor and use the Windows Camera to display the video camera's output to view where it is going.

# Game Controller Support
To install game controller support:

1. Download AntiMicro from the Microsoft Store

2. Import the mapping in AntiMicro\map\WaterOS.joystick.amgp to the controller of your choice

To use it:

1. Set up the Serial Monitor and the Windows Camera as usual

2. Open up AntiMicro

3. Minimize AntiMicro to the system tray

4. Use the D-Pad as if you were doing WASD. Note that the 'down' button sends the stop command, as this bot cannot move backward.

5. Press X to send the keystroke to the bot.

Note: You can also use [AntiMicroX](https://github.com/AntiMicroX/antimicrox), which is backwards-compatible with the original AntiMicro. I originally designed this for AntiMicro, but because the new AntiMicroX is a continuation/fork of the original, it should also work.

In general
----------

# Direct CLI interaction

It's best to use the game controller. However, if you insist, here's a list of commands:

- 'forward' to go forward

- 'stop' to stop all motors and park bot

- 'left' to go left

- 'right' to go right

# Updating

1. Follow the installation instrutions above to flash the new version to your bot.

# Resources

Copyright @matthewyang204 2023-2024，@13-JA 2024