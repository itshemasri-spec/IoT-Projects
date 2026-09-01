# 🌐 ESP8266 Local Web Page for DHT11, HC-SR04 & PIR Monitoring

A local IoT monitoring project developed using an **ESP8266 NodeMCU**, **DHT11 temperature and humidity sensor**, **HC-SR04 ultrasonic sensor**, and **PIR motion sensor**.

The ESP8266 connects to a Wi-Fi network and hosts a local web page. Users can access the page through the ESP8266's IP address to monitor temperature, humidity, distance, and motion status in real time.

## 🔧 Components Used

* ESP8266 NodeMCU
* DHT11 Temperature & Humidity Sensor
* HC-SR04 Ultrasonic Sensor
* PIR Motion Sensor
* Breadboard
* Jumper Wires
* USB Cable

## ⚙️ Features

* 🌡️ Temperature monitoring
* 💧 Humidity monitoring
* 📏 Distance measurement
* 🚶 Motion detection
* 🌐 Local web page
* 📶 ESP8266 Wi-Fi connectivity
* 🔗 IP-based browser access
* 🔄 Real-time sensor status display

## 🛠️ Technologies Used

* **Microcontroller:** ESP8266 NodeMCU
* **Sensors:** DHT11, HC-SR04, PIR
* **Programming:** C/C++
* **IDE:** Arduino IDE
* **Communication:** Wi-Fi
* **Interface:** HTML / CSS
* **Web Server:** ESP8266

## 🔌 Sensor Connections

| Component    | ESP8266                    |
| ------------ | -------------------------- |
| DHT11 VCC    | 3.3V                       |
| DHT11 DATA   | GPIO used in code          |
| DHT11 GND    | GND                        |
| HC-SR04 VCC  | 5V                         |
| HC-SR04 TRIG | GPIO used in code          |
| HC-SR04 ECHO | GPIO used in code          |
| HC-SR04 GND  | GND                        |
| PIR VCC      | 3.3V / according to module |
| PIR OUT      | GPIO used in code          |
| PIR GND      | GND                        |

> Update the GPIO numbers according to the actual connections used in the project.

> **Important:** The HC-SR04 Echo output can be 5V. Use a suitable voltage divider or level shifter before connecting it to an ESP8266 GPIO.

## 🔄 Working Principle

1. The ESP8266 connects to the configured Wi-Fi network.
2. The DHT11 measures temperature and humidity.
3. The HC-SR04 measures the distance of an object.
4. The PIR sensor detects movement.
5. The ESP8266 processes the sensor readings.
6. A local web server displays the collected information.
7. The ESP8266 IP address is shown through the Serial Monitor.
8. The user enters the IP address in a web browser to access the monitoring page.

### Example

```text
ESP8266 connected to Wi-Fi
IP Address: 192.168.1.105
```

The user can open the displayed IP address in a browser to view the sensor information.

## 📊 Monitored Parameters

| Parameter   | Sensor  |
| ----------- | ------- |
| Temperature | DHT11   |
| Humidity    | DHT11   |
| Distance    | HC-SR04 |
| Motion      | PIR     |

## 🚀 Future Enhancements

* Animated web dashboard
* Real-time graphs
* Mobile-responsive interface
* Cloud data logging
* Blynk IoT integration
* ThingSpeak integration
* Motion-based alerts
* Email notifications
* Remote monitoring over the internet

## 📌 Project Status

✅ Completed

This project demonstrates **ESP8266 sensor interfacing, Wi-Fi connectivity, local web server development, IP-based access, and real-time monitoring of multiple sensors**.
