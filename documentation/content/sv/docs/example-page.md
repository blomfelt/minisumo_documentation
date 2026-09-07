---
weight: 2
title: "CRF Minisumo bot"
description: ""
icon: "article"
date: "2026-09-01T19:05:21+02:00"
lastmod: "2026-09-01T19:05:21+02:00"
draft: false
toc: true
---


A follow-up to the [CRF SumoBot](https://github.com/ChalmersRobotics/CRF-SumoBot)[^1] designed by Kalle Strålman.

Bluetooth remote control code from Shib Sankar Das's [ESP32-Bluetooth-RC-Car-Project](https://github.com/Shib-Sankar-Das/ESP32-Bluetooth-RC-Car-Project/)[^2]

Please find:
- [Instructions and workshop intro (v1.2, updated 251105) - here](TODO)
- [3D manufacturing files](TODO)
- [complete release package - here!](https://github.com/ChalmersRobotics/CRF-SumoBot/releases)

!["Rendered image of nano-hat v1.2"](https://github.com/user-attachments/assets/4b3bfe92-f011-4b23-bd6a-29615ce4e76a)

## TODO
- [x] Choose wires or PCB for connection (PCB right now)
- [x] Add sensors
- [x] Add Sumo-code
- [ ] Design the chassis
- [ ] Write build instructions

## Instructions
- Obtain Components and Chassis (See *Bill of Materials below*)
- Download the `minisumo-bot.ino` file from [releases on the right side](https://github.com/ChalmersRobotics/CRF-SumoBot/releases)
- Build the robot according to the [instructions](TODO)
- Upload the code to the robot as in the [instructions](TODO) or as documented below.

## Uploading code to the ESP32
- Install Arduino IDE v2 from their [website](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/)[^3] or your favourite package manager. Current version is 2.3.8.
- Install the required boards from the Boards Manager in the left column, second icon from the top:
    - esp32 by Espressif Systems (current version 3.3.11)
- Install the required libraries from the Library Manager, icon under the Boards Manager (or via Tools > Manage Libraries):
    - "NimBLE_Arduino" by h2zero (current version 2.5.1)
    - "HCSR04" by Martin Sosic (current version 2.0.0)
- Choose the correct board from the Select Board dropdown > Select other board and port. Then Search for *MakerGO ESP32 C6 SuperMini*. It will look as if nothing happens but that is fine.
- Connect the ESP32 to your computer while holding the BOOT button on the board. It will show up in the right column as something like `/dev/usb/ttyASM0` if you are on linux. Click Ok.
    - The board may not show up, in which case you need to hold the Boot button while connecting the board, then tapping the RST button and finally releasing the BOOT button.
- Paste the contents of `minisumo-bot.ino` into the default sketch or download the file and open it from File > Open
- Verify and/or Upload the sketch to the ESP32 using the checkbox and/or arrow in the top left corner.


## Bill of Materials
- PCB
- 3D printed chassis
- ESP32 C6 Supermini
- Motor driver: L298N
- Ultrasonic sensor: HC-SR04
- IR sensor: v183
- Cables

## Changelog

| Version       | Changes      |
| ------------- | ------------- |
| v2.0          | <ul><li>Updated PCB design</li><li>Changed to ESP from Arduino</li></ul> |
| v1.2          | <ul><li>Add EN_A and EN_B pins for controlling H-Bridge speed</li><li>Move start module placement slightly more towards the edge</li><li>Add header pins for unused ports on the Arduino to allow further extension / mods</li>Add an optional switch to pull-up and bypass start module</ul> |
| v1.1          | <ul><li>Move mounting holes slightly</li><li>Add header pins for start module</li></ul> |
| v1.0          | First draft |


## References
[^1]: CRF SumoBot, Kalle Strålman, [https://github.com/ChalmersRobotics/CRF-SumoBot](https://github.com/ChalmersRobotics/CRF-SumoBot)
[^2]: ESP32-Bluetooth-RC-Car-Project, Shib Sankar Das, [https://github.com/Shib-Sankar-Das/ESP32-Bluetooth-RC-Car-Project/](https://github.com/Shib-SankAar-Das/ESP32-Bluetooth-RC-Car-Project/)
[^3]: Downloading and installing the Arduino IDE 2, Arduino, [https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/)

