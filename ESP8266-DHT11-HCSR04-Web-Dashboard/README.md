# 🌐 ESP8266 Local Web Dashboard for DHT11 & HC-SR04

A local IoT monitoring system developed using an **ESP8266 NodeMCU**, **DHT11 temperature and humidity sensor**, and **HC-SR04 ultrasonic sensor**.

The ESP8266 collects sensor data and hosts a local web dashboard that allows users to monitor **temperature, humidity, and distance** in real time through a web browser connected to the same Wi-Fi network.

## 🔧 Components Used

* ESP8266 NodeMCU
* DHT11 Temperature & Humidity Sensor
* HC-SR04 Ultrasonic Sensor
* Breadboard
* Jumper Wires
* USB Cable

## ⚙️ Features

* 🌡️ Real-time temperature monitoring
* 💧 Real-time humidity monitoring
* 📏 Distance measurement
* 🌐 Local web dashboard
* 📶 ESP8266 Wi-Fi connectivity
* 📊 Live sensor data display
* 💻 Browser-based monitoring without a separate application

## 🛠️ Technologies Used

* **Microcontroller:** ESP8266 NodeMCU
* **Sensors:** DHT11 + HC-SR04
* **Programming:** C/C++
* **IDE:** Arduino IDE
* **Communication:** Wi-Fi
* **Interface:** HTML, CSS, JavaScript
* **Web Server:** ESP8266 Web Server

## 🔌 Sensor Connections

| Component    | ESP8266           |
| ------------ | ----------------- |
| DHT11 VCC    | 3.3V              |
| DHT11 DATA   | GPIO used in code |
| DHT11 GND    | GND               |
| HC-SR04 VCC  | 5V                |
| HC-SR04 TRIG | GPIO used in code |
| HC-SR04 ECHO | GPIO used in code |
| HC-SR04 GND  | GND               |

> Update the GPIO numbers according to the actual connections used in the project.

> **Important:** The HC-SR04 Echo pin can output 5V. When connecting it to an ESP8266 GPIO, use an appropriate voltage divider or level-shifting circuit.

## 🔄 Working Principle

1. The ESP8266 connects to the local Wi-Fi network.
2. The DHT11 measures temperature and humidity.
3. The HC-SR04 measures the distance to an object.
4. The ESP8266 processes the sensor readings.
5. A local web server hosted by the ESP8266 provides the dashboard.
6. Users open the ESP8266's local IP address in a web browser.
7. The dashboard displays the sensor values in real time.

## 📊 Monitored Parameters

| Parameter   | Sensor  |
| ----------- | ------- |
| Temperature | DHT11   |
| Humidity    | DHT11   |
| Distance    | HC-SR04 |

## 🚀 Future Enhancements

* Animated dashboard interface
* Real-time graphs
* Sensor data history
* Mobile-responsive dashboard
* Cloud data logging
* Blynk integration
* ThingSpeak integration
* Threshold-based alerts

## 📌 Project Status

✅ Completed

This project demonstrates **ESP8266 sensor interfacing, Wi-Fi communication, local web server development, and real-time IoT monitoring** using a browser-based dashboard.
