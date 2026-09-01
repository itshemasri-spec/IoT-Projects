# 🌐 ESP8266 DHT11 Local Web Dashboard

A simple IoT-based monitoring system using an **ESP8266 NodeMCU** and **DHT11 temperature and humidity sensor**.

The ESP8266 connects to a Wi-Fi network and hosts a local web dashboard. The sensor readings can be viewed through a web browser by entering the **IP address assigned to the ESP8266**.

## 🔧 Components Used

* ESP8266 NodeMCU
* DHT11 Temperature & Humidity Sensor
* Breadboard
* Jumper Wires
* USB Cable

## ⚙️ Features

* 🌡️ Real-time temperature monitoring
* 💧 Real-time humidity monitoring
* 🌐 Local web dashboard
* 📶 Wi-Fi connectivity
* 🔗 Access through ESP8266 IP address
* 💻 Browser-based monitoring
* 🔄 Continuous sensor data updates

## 🛠️ Technologies Used

* **Microcontroller:** ESP8266 NodeMCU
* **Sensor:** DHT11
* **Programming:** C/C++
* **IDE:** Arduino IDE
* **Communication:** Wi-Fi
* **Interface:** HTML, CSS
* **Web Server:** ESP8266

## 🔌 Circuit Connections

| DHT11 Pin | ESP8266           |
| --------- | ----------------- |
| VCC       | 3.3V              |
| DATA      | GPIO used in code |
| GND       | GND               |

> Update the GPIO number according to the actual pin used in your project.

## 🔄 Working Principle

1. The DHT11 sensor measures temperature and humidity.
2. The ESP8266 reads the sensor values.
3. The ESP8266 connects to the configured Wi-Fi network.
4. The ESP8266 obtains a local IP address.
5. The IP address is displayed through the Serial Monitor.
6. The user enters this IP address in a web browser.
7. The ESP8266 serves a local dashboard displaying the current temperature and humidity values.

### Example

```text
ESP8266 connected to Wi-Fi
IP Address: 192.168.1.105
```

Open the displayed IP address in a browser:

```text
http://192.168.1.105
```

The dashboard then displays the DHT11 readings.

## 📊 Monitored Parameters

| Parameter   | Sensor |
| ----------- | ------ |
| Temperature | DHT11  |
| Humidity    | DHT11  |

## 🚀 Future Enhancements

* Animated dashboard
* Real-time graphs
* Mobile-responsive interface
* Historical data storage
* ThingSpeak integration
* Blynk IoT integration
* Cloud-based monitoring
* Temperature threshold alerts

## 📌 Project Status

✅ Completed

This project demonstrates **ESP8266 Wi-Fi connectivity, DHT11 sensor interfacing, local IP-based web access, and browser-based IoT monitoring**.
