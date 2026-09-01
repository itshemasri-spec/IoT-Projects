# 💡 ESP8266 External LED Control using Blynk IoT

An IoT-based LED control project using an **ESP8266 NodeMCU**, an external LED, and the **Blynk IoT mobile application**.

The project demonstrates wireless control of an external LED through the internet using the ESP8266 and Blynk IoT platform.

## 🔧 Components Used

* ESP8266 NodeMCU
* External LED
* Resistor
* Breadboard
* Jumper Wires
* USB Cable

## ⚙️ Features

* 💡 External LED control
* 📱 Blynk IoT mobile application
* 📶 ESP8266 Wi-Fi connectivity
* 🔄 Wireless ON/OFF control
* 🌐 Internet-based IoT communication

## 🛠️ Technologies Used

* **Microcontroller:** ESP8266 NodeMCU
* **IoT Platform:** Blynk IoT
* **Programming:** C/C++
* **IDE:** Arduino IDE
* **Communication:** Wi-Fi

## 🔌 Circuit Connections

| Component       | ESP8266                   |
| --------------- | ------------------------- |
| LED Anode (+)   | GPIO pin used in the code |
| LED Cathode (-) | GND through resistor      |

> Update the GPIO number in this table according to the actual pin used in the project.

## 🔄 Working Principle

1. The ESP8266 connects to a Wi-Fi network.
2. The ESP8266 establishes communication with the Blynk IoT platform.
3. A virtual control button in the Blynk mobile application is used to control the LED.
4. When the user presses the button, the command is sent to the ESP8266.
5. The ESP8266 switches the external LED ON or OFF according to the received command.

## 📱 Blynk IoT

The Blynk IoT application provides a mobile interface for controlling the external LED remotely.

## 🚀 Future Enhancements

* Control multiple LEDs
* Add relay-based appliance control
* Add sensor monitoring
* Add scheduling
* Add automation rules
* Expand into a complete smart home system

## 📌 Project Status

✅ Completed

This project demonstrates **ESP8266 Wi-Fi connectivity, Blynk IoT integration, and wireless control of an external LED**.
