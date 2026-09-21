---
weight: 200
title: "Programming an ESP32"
description: ""
icon: "upload"
date: "2026-09-01T21:49:12+02:00"
lastmod: "2026-09-01T21:49:12+02:00"
draft: false
toc: true
---

- Install Arduino IDE v2 from their [website](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/)[^3] or your favourite package manager. Current version is 2.3.8.
- Install the required boards from the Boards Manager in the left column, second icon from the top:
    - esp32 by Espressif Systems (current version 3.3.11)
- Install the required libraries from the Library Manager, icon under the Boards Manager (or via Tools > Manage Libraries):
    - "HCSR04" by Martin Sosic (current version 2.0.0)
    - If you are going to remote control it using bluetooth: "NimBLE_Arduino" by h2zero (current version 2.5.1)
- Choose the correct board from the Select Board dropdown > Select other board and port. Then Search for *MakerGO ESP32 C6 SuperMini*. It will look as if nothing happens but that is fine.
- Connect the ESP32 to your computer while holding the BOOT button on the board. It will show up in the right column as something like `/dev/usb/ttyASM0` if you are on linux. Click Ok.
    - The board may not show up, in which case you need to hold the Boot button while connecting the board, then tapping the RST button and finally releasing the BOOT button.
- Paste the contents of `minisumo-bot.ino` into the default sketch or download the file and open it from File > Open
- If you want to see the serial monitor when the ESP is connected to your computer you need to enable "*USB CDC On Boot*" under Tools in the top bar, after which you can open the Serial Monitor in the top right corner under the magnifying glass.
- Verify and/or Upload the sketch to the ESP32 using the checkbox and/or arrow in the top left corner.
- **Done!** Now it will run the code you uploaded to it every time it is powered on!

[^3]: Downloading and installing the Arduino IDE 2, Arduino, [https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/)
