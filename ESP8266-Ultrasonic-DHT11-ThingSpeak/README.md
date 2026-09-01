# 📡 ESP8266 Ultrasonic & DHT11 IoT Monitoring with ThingSpeak

An IoT-based monitoring system developed using an **ESP8266 NodeMCU**, **HC-SR04 ultrasonic sensor**, and **DHT11 temperature and humidity sensor**.

The system collects distance, temperature, and humidity data and sends the measurements to the **ThingSpeak** cloud platform through Wi-Fi for remote monitoring and data visualization.

## 🔧 Components Used

* ESP8266 NodeMCU
* HC-SR04 Ultrasonic Sensor
* DHT11 Temperature & Humidity Sensor
* Breadboard
* Jumper Wires
* USB Cable

## ⚙️ Features

* 📏 Distance measurement using HC-SR04
* 🌡️ Temperature measurement using DHT11
* 💧 Humidity measurement using DHT11
* 📶 ESP8266 Wi-Fi connectivity
* ☁️ ThingSpeak cloud integration
* 📊 Online data visualization
* 🔄 Continuous sensor data monitoring

## 🛠️ Technologies Used

* **Microcontroller:** ESP8266 NodeMCU
* **Sensors:** HC-SR04 + DHT11
* **Cloud Platform:** ThingSpeak
* **Programming:** C/C++
* **IDE:** Arduino IDE
* **Communication:** Wi-Fi

## 🔄 Working Principle

1. The ESP8266 connects to the available Wi-Fi network.
2. The HC-SR04 measures the distance to an object.
3. The DHT11 measures temperature and humidity.
4. The ESP8266 processes the sensor readings.
5. The measured values are sent to the ThingSpeak cloud platform.
6. ThingSpeak stores and displays the data through graphs.
7. The process continues at regular intervals for real-time monitoring.

## 📊 Data Monitoring

The system can send the following parameters to ThingSpeak:

| Parameter   | Sensor  |
| ----------- | ------- |
| Distance    | HC-SR04 |
| Temperature | DHT11   |
| Humidity    | DHT11   |

The uploaded data can be monitored remotely through the ThingSpeak channel and visualized using graphs.

## 🚀 Future Enhancements

* Real-time web dashboard
* Mobile monitoring
* Threshold-based alerts
* Email notifications
* Data analytics
* Multiple sensor integration
* Automated IoT control based on sensor values

## 📌 Project Status

✅ Completed

This project demonstrates the integration of **ESP8266, multiple sensors, Wi-Fi connectivity, and ThingSpeak cloud monitoring** for real-time IoT data collection and visualization.
