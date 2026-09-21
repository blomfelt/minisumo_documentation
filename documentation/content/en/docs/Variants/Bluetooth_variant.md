---
weight: 12
title: "Bluetooth"
description: ""
icon: "article"
date: "2026-09-21T14:24:28+02:00"
lastmod: "2026-09-21T14:24:28+02:00"
draft: false
toc: true
---

The bluetooth variant of the sumobot uses Bluetooth Low Energy (BLE) to communicate with for example an app on your phone. 

If you are using android you can use the app [BLE Joystick](https://play.google.com/store/apps/details?id=iyok.com.blejoystickpro) to control the robot.

For debugging the characteristics you can use the app [nRF Connect](https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp).

For this bot there are not complete build instructions, but the info found in the [quickstart guide for the minisumo bot](/docs/quickstart) and the [full build instructions for the minisumo bot]() applies, except that you don't need the IR sensors or Ultrasonic distance sensors, however you can add them to the bot and modify the code to include them if you want!

The code is located at [variants/Bluetooth_control/Bluetooth_control.ino](https://github.com/ChalmersRobotics/minisumoplusplus2027/blob/main/variants/Bluetooth_control/Bluetooth_control.ino) in the GitHub.

The 3D-printing files are located at [this link](link)
