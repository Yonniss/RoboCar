# 🤖 Voice-Controlled Robot (ESP32)

This repository contains the source code, app project files, and documentation for a **Voice-Controlled Mobile Robot**. The system is built using an **ESP32**, **DC Motors**, and a custom **Android App** created with MIT App Inventor.

This project was initially a high school research project but I decided to upload it to GitHub to share my code with everyone.

![Project Status](https://img.shields.io/badge/Status-Completed-success)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![App](https://img.shields.io/badge/App-MIT%20App%20Inventor-orange)

**QUICK ADVERTISMENT** This code and build was made with the help of a spanish website that lets you code an Arduino/ESP32 with blocks named STEAMakers blocks. Since it imports some strange libraries, you should change the code as you need to make it work in the Arduino IDE. The components used can also be variated as you will, since I used a shield that made me able to not require some L289N drivers.


**QUICK ADVERTISMENT 2** The App was made to work only in spanish, so I would suggest you change the language of the app.


## 📋 Project Overview

The main objective of this project is to build a robotic system capable of moving and responding to voice commands. The robot interprets verbal instructions to move, turn, or stop, and includes manual control features via a mobile interface.

### Key Features
* **Voice Control:** Recognizes commands like "Forward", "Back", "Left", and numerical values for duration.
* **Manual Control:** Directional arrows (D-Pad style) on the app for direct maneuvering.
* **OLED Messaging:** Displays text sent from the smartphone on the robot's screen.
* **Horn/Buzzer:** Remote activation of a buzzer.

---

## 🛠️ Hardware Requirements

The robot is built using a modular approach, avoiding complex soldering by using a specific expansion shield.

| Component | Description |
|-----------|-------------|
| **Microcontroller** | ESP32 Plus STEAMakers (or standard ESP32)|
| **Expansion Board** | Shield IMAGINA 3DBot (Controls motors without external drivers)|
| **Actuators** | 2x DC Motors (3V-12V) connected to rear wheels |
| **Chassis** | Basic chassis with 1 caster wheel for stability made in fusion and then printed in 3d|
| **Display** | OLED Screen (I2C) |
| **Power** | Battery pack / Power Bank via USB |

---

## 💻 Software & Tools

* **Firmware:** Written in C++ (Arduino IDE) or STEAMakersBlocks.
* **App Development:** MIT App Inventor.
* **Libraries Used:**
    * `BluetoothSerial.h` (Wireless communication)
    * `Adafruit_SSD1306.h` (OLED Display)
    * `analogWrite.h` (PWM control for ESP32)

---

## ⚙️ Installation & Setup

### 1. Wiring
Based on the **IMAGINA 3DBot Shield**, the connections are plug-and-play:
* **Left Motor:** Connect to Motor 1 header.
* **Right Motor:** Connect to Motor 2 header.
* **OLED Display:** Connect to the I2C header.
* **Buzzer:** Integrated into the shield (controlled via pin `A0` / `GPIO 2`).

### 2. ESP32 Firmware
1. Open the `.ino` file located in the `/src` folder.
2. Install the required libraries in Arduino IDE.
3. Upload the code to the ESP32.
4. **Note:** The Bluetooth device name is set to `"prova control"`.

### 3. Android App
1. Import the `.aia` project into MIT App Inventor or install the `.apk` on your phone.
2. Enable Bluetooth on your phone and pair it with the ESP32.

---

## 📡 Communication Protocol

The app sends text strings via Bluetooth Serial to control the robot. The ESP32 parses these strings to execute commands.

### Movement Commands
| Command | Action | Description |
|:-------:|:------:|-------------|
| `CMD:w` | **Forward** | Moves motors forward |
| `CMD:s` | **Backward** | Moves motors backward |
| `CMD:a` | **Left** | Pivots left |
| `CMD:d` | **Right** | Pivots right |
| `CMD:r` | **Stop** | Stops all motors |

### Features
* **OLED Text:** `TXT:[message]` (e.g., `TXT:Hello World` displays "Hello World" on the screen).
* **Horn:** `BRD:` (Activates the buzzer for 100ms at 1000Hz).

### Voice-to-Action Logic
The app uses a dictionary algorithm to convert spoken number words (e.g., "one hundred fifty") into integer values. It sends the command in the format `CMD:[direction]:[value]` to set specific speeds or durations.

---

## 🚀 How to Use

1. **Power on** the robot.
2. Open the **App** and tap the **Bluetooth Icon** to connect.
3. **Manual Mode:** Use the on-screen arrows to drive.
4. **Voice Mode:** Tap the microphone icon and say:
    * *"Avanza"* (Forward)
    * *"Derecha"* (Right)
    * *"Stop"*
5. **Messaging:** Click the "OLED" button, type a message, and send it to the robot.

---

## 📄 Credits

**Author:** Yannis Florin Ionica
**Course:** 2025/2026

---
*Created for the High School Research Project (Treball de Recerca).*
