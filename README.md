# CRF minisumo++2027 (CRFminisumoplusplus2027)

A follow-up to the [CRF SumoBot](https://github.com/ChalmersRobotics/CRF-SumoBot)[^1] designed primarily by Kalle Strålman and David Strålman.

After RobotSM 2026 we sold out of kits that were arduino based and ran out of batteries that were cheap. While doing these changes we also chose to update the PCB and make some pretty big changes to the model, so why not make upgrades!?

## Concept for minisumo++2027
A minisumo .. plus some other things .. plus even some more!
- Minisumo for robotSM primarily, but as possible a module that can be a spring board into other things
- Minisumo that one steers like an RC car via bluetooth!
- Lego version! .. encapsulate motors and such into a robot combat like (or autonomous robot?) that can be lego'd together!
- [Death racers](https://www.youtube.com/watch?v=i10rxmsKHts)
- Dobot combat base module
- More? Why not?? Probably possible
  - Line following!?
  - Esphome controlled robot w/ or w/o home assistant!?

## Goals and features
1. Good for beginners to meet the primary goal of minisumo for robotSM
2. Cheap as chips
3. Possibility to make really really smallish, for example to encapsulate into lego!
4. More voltage to motors!
5. Battery charging possible since using the c6!
6. Possibility to expand and reuse gpio's or other purpose robots!

## TODO
- [x] Choose wires or PCB for connection (PCB right now)
- [x] Add sensors
- [x] Add Sumo-code
- [x] Add bluetooth code
- [x] Control motors via bluetooth
- [ ] Design the chassis
- [ ] Write build instructions
- [ ] PCBs - need to build to confirm eg ALL footprints (all done by hand) && perform functional tests with everything mounted as designed with software running && confirm within eventual 3d packaging.


## Instructions
- Obtain Components and Chassis (See *Bill of Materials below*) or via a kit @ CRF while supplies last!
- Download the `minisumo-bot.ino` file from [releases on the right side](https://github.com/ChalmersRobotics/CRF-SumoBot/releases)
- Build the robot according to the [instructions](TODO)
- Upload the code to the robot as in the [instructions](TODO) or as documented below.


### Instructions for pcb assembly / soldering incl tips and tricks
tbd

### Instructions for final assembly
tbd

### Instructions for uploading code to the ESP32
- Install Arduino IDE v2 from their [website](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/)[^2] or your favourite package manager. Current version is 2.3.10.
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



### Bill of Materials
See [the google sheets bom](https://docs.google.com/spreadsheets/d/1KNLTKy2cLUtDrH-E30Gfz_4ahhQaqS2SGsFHG1Fw9_M/edit?usp=sharing))
- PCB
- 3D printed chassis
- [ESP32 C6 Super Mini](https://mischianti.org/esp32-c6-supermini-high-resolution-pinout-datasheet-schema-and-specs/)
- Battery 3.7v cr123 with recharge usb c contact built in!
- Battery contacts!
- Buck boost to push motor driver to 9v!
- Switch on / off .. a smaller one is needed
- Motor driver: L298N
- Ultrasonic sensor: HC-SR04
- IR sensor: v183
- Start module
- Cables

## Changelog

| Version       | Changes      |
| ------------- | ------------- |
| v1.0          | First draft |


## References
[^1]: CRF SumoBot, Kalle Strålman, [https://github.com/ChalmersRobotics/CRF-SumoBot](https://github.com/ChalmersRobotics/CRF-SumoBot)
[^2]: Downloading and installing the Arduino IDE 2, Arduino, [https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/)

