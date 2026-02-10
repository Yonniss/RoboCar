# 🤖 Voice-Controlled Robot (ESP32)

This repository contains the source code, app project files, and documentation for a **Voice-Controlled Mobile Robot**. The system is built using an **ESP32**, **DC Motors**, and a custom **Android App** created with MIT App Inventor.

![Project Status](https://img.shields.io/badge/Status-Completed-success)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![App](https://img.shields.io/badge/App-MIT%20App%20Inventor-orange)

## 📋 Project Overview

[cite_start]The main objective of this project is to build a robotic system capable of moving and responding to voice commands[cite: 16]. The robot interprets verbal instructions to move, turn, or stop, and includes manual control features via a mobile interface.

### Key Features
* [cite_start]**Voice Control:** Recognizes commands like "Forward", "Back", "Left", and numerical values for speed/duration[cite: 56, 1034].
* [cite_start]**Manual Control:** Directional arrows (D-Pad style) on the app for direct maneuvering[cite: 1280].
* [cite_start]**OLED Messaging:** Displays text sent from the smartphone on the robot's screen[cite: 1280].
* [cite_start]**Horn/Buzzer:** Remote activation of a buzzer[cite: 1286].

---

## 🛠️ Hardware Requirements

The robot is built using a modular approach, avoiding complex soldering by using a specific expansion shield.

| Component | Description |
|-----------|-------------|
| **Microcontroller** | [cite_start]ESP32 Plus STEAMakers (or standard ESP32) [cite: 534] |
| **Expansion Board** | [cite_start]Shield IMAGINA 3DBot (Controls motors without external drivers) [cite: 539] |
| **Actuators** | [cite_start]2x DC Motors (3V-12V) connected to rear wheels [cite: 546] |
| **Chassis** | [cite_start]Basic chassis with 1 caster wheel for stability [cite: 548] |
| **Display** | [cite_start]OLED Screen (I2C) [cite: 1559] |
| **Power** | Battery pack / Power Bank via USB |

---

## 💻 Software & Tools

* [cite_start]**Firmware:** Written in C++ (Arduino IDE) or STEAMakersBlocks[cite: 588].
* [cite_start]**App Development:** MIT App Inventor[cite: 19].
* **Libraries Used:**
    * [cite_start]`BluetoothSerial.h` (Wireless communication) [cite: 855]
    * [cite_start]`Adafruit_SSD1306.h` (OLED Display) [cite: 1408]
    * [cite_start]`analogWrite.h` (PWM control for ESP32) [cite: 852]

---

## ⚙️ Installation & Setup

### 1. Wiring
[cite_start]Based on the **IMAGINA 3DBot Shield**, the connections are plug-and-play[cite: 1559]:
* **Left Motor:** Connect to Motor 1 header.
* **Right Motor:** Connect to Motor 2 header.
* **OLED Display:** Connect to the I2C header.
* [cite_start]**Buzzer:** Integrated into the shield (controlled via pin `A0` / `GPIO 2`)[cite: 1294].

### 2. ESP32 Firmware
1.  Open the `.ino` file located in the `/src` folder.
2.  Install the required libraries in Arduino IDE.
3.  Upload the code to the ESP32.
4.  [cite_start]**Note:** The Bluetooth device name is set to `"prova control"`[cite: 776].

### 3. Android App
1.  Import the `.aia` project into MIT App Inventor or install the `.apk` on your phone.
2.  Enable Bluetooth on your phone and pair it with the ESP32.

---

## 📡 Communication Protocol

The app sends text strings via Bluetooth Serial to control the robot. [cite_start]The ESP32 parses these strings to execute commands[cite: 1194].

### Movement Commands
| Command | Action | Description |
|:-------:|:------:|-------------|
| `CMD:w` | **Forward** | [cite_start]Moves motors forward [cite: 1498] |
| `CMD:s` | **Backward** | [cite_start]Moves motors backward [cite: 1523] |
| `CMD:a` | **Left** | [cite_start]Pivots left [cite: 1510] |
| `CMD:d` | **Right** | [cite_start]Pivots right [cite: 1535] |
| `CMD:r` | **Stop** | [cite_start]Stops all motors [cite: 1540] |

### Features
* [cite_start]**OLED Text:** `TXT:[message]` (e.g., `TXT:Hello World` displays "Hello World" on the screen)[cite: 1545].
* [cite_start]**Horn:** `BRD:` (Activates the buzzer for 100ms at 1000Hz)[cite: 1548].

### Voice-to-Action Logic
The app uses a dictionary algorithm to convert spoken number words (e.g., "one hundred fifty") into integer values. [cite_start]It sends the command in the format `CMD:[direction]:[value]` to set specific speeds or durations[cite: 1194, 1272].

---

## 🚀 How to Use

1.  **Power on** the robot.
2.  Open the **App** and tap the **Bluetooth Icon** to connect.
3.  **Manual Mode:** Use the on-screen arrows to drive.
4.  **Voice Mode:** Tap the microphone icon and say:
    * *"Avanza"* (Forward)
    * *"Derecha"* (Right)
    * *"Stop"*
5.  **Messaging:** Click the "OLED" button, type a message, and send it to the robot.

---

## 📄 Credits

[cite_start]**Author:** Yannis Florin Ionica [cite: 3]
[cite_start]**Tutor:** Joaquim Crisol Forcadell [cite: 5]
[cite_start]**Institution:** Institut de Camarles [cite: 7]
[cite_start]**Course:** 2025/2026 [cite: 6]

---
*Created for the High School Research Project (Treball de Recerca).*
