# 🌡️ ESP32 DHT11 Temperature Monitoring with Email Alerts

An IoT-based temperature and humidity monitoring system using an **ESP32** and **DHT11 sensor**. The system continuously monitors environmental conditions and sends an **email alert** when the measured temperature reaches a predefined threshold.

## 🔧 Components Used

* ESP32 Development Board
* DHT11 Temperature & Humidity Sensor
* Jumper Wires
* Breadboard
* USB Cable

## ⚙️ Features

* Real-time temperature monitoring
* Real-time humidity monitoring
* ESP32 Wi-Fi connectivity
* DHT11 sensor interfacing
* Automatic email notification
* Temperature threshold-based alert

## 🛠️ Technologies Used

* **Microcontroller:** ESP32
* **Sensor:** DHT11
* **Programming:** C/C++
* **IDE:** Arduino IDE
* **Communication:** Wi-Fi
* **Notification:** Email

## 🔄 Working Principle

1. The DHT11 sensor measures the surrounding temperature and humidity.
2. The ESP32 reads the sensor values.
3. The ESP32 connects to a Wi-Fi network.
4. The temperature is compared with a predefined threshold.
5. If the threshold condition is satisfied, an email alert is sent.
6. The system continues monitoring the environment.

## 📊 Example

```text
Temperature: 31.5 °C
Humidity: 64.0 %

Temperature threshold exceeded!
Email alert sent.
```

## 🚀 Future Enhancements

* Blynk IoT integration
* Mobile notifications
* Cloud data logging
* Web-based monitoring dashboard
* Temperature and humidity graphs
* Multiple threshold levels

## 📌 Project Status

✅ Completed

The project demonstrates real-time environmental monitoring and automated email notification using ESP32 and DHT11.
