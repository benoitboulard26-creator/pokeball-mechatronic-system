# Firmware – ATtiny85 Control Code

## Overview
This folder contains the firmware used to control the PCB functionality.
The code is written for an **ATtiny85** microcontroller and is responsible for handling user input and servo motor control.

## Hardware Mapping
The following pin configuration is used on the ATtiny85:

| Function        | ATtiny85 Pin | Arduino Pin |
|-----------------|--------------|-------------|
| Servo signal    | PB0          | Pin 0 (Pin 5) |
| Push button     | PB3          | Pin 3 (Pin 2) |

- The push button uses the **internal pull-up resistor**
- The servo motor is driven using a **manually generated PWM signal**

## Functional Description
- The system waits for a **push button press**
- Each button press toggles the servo position:
  - One position corresponds to the Pokéball **open state**
  - The other corresponds to the **closed state**
- A counter is used to alternate between positions
- Basic software debouncing is implemented

## Servo Control Strategy
- The servo signal is generated **manually**, without using a dedicated servo library
- PWM characteristics:
  - Period: ~20 ms
  - Pulse width:
    - ~1500 µs → neutral / mid position
    - ~450 µs → extreme position
- This approach ensures:
  - Low memory usage
  - Full compatibility with the ATtiny85

## Button Handling
- The button is read using `INPUT_PULLUP`
- A state change from **HIGH → LOW** triggers an action
- A short delay is used to limit switch bouncing

## Notes & Limitations
- Servo angle values may need adjustment depending on:
  - Servo model
  - Mechanical constraints
- Timing is handled using `delay()` and `delayMicroseconds()`, which is sufficient for this application but not intended for multitasking systems

## Compilation & Upload
- Compatible with Arduino IDE using an ATtiny85 core
- Ensure correct clock configuration before uploading
- Recommended to test servo motion without mechanical load first
