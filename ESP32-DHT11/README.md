# 🌡️ ESP32 DHT11 Temperature & Humidity Monitoring

An IoT-based environmental monitoring project using an **ESP32** and **DHT11 sensor** to measure temperature and humidity in real time.

## 🔧 Components Used

* ESP32 Development Board
* DHT11 Temperature & Humidity Sensor
* Breadboard
* Jumper wires
* USB cable

## 🔌 Circuit Connections

| DHT11 | ESP32  |
| ----- | ------ |
| VCC   | 3.3V   |
| DATA  | GPIO 4 |
| GND   | GND    |

> If your actual wiring uses a different GPIO pin, update the connection above.

## 📚 Required Library

Install the following library through Arduino IDE:

* DHT sensor library

## ⚙️ Working

1. The DHT11 sensor detects the surrounding temperature and humidity.
2. The ESP32 reads the sensor values.
3. The measured values are processed by the ESP32.
4. Temperature and humidity readings are displayed through the Serial Monitor.

## 🖥️ Sample Output

```text
Temperature: 29.5 °C
Humidity: 68.0 %
Temperature: 29.6 °C
Humidity: 67.5 %
```

## 🚀 Future Improvements

* Blynk IoT integration
* ThingSpeak cloud monitoring
* Web dashboard
* Mobile monitoring
* Data visualization
* Threshold-based alerts

## 📌 Project Status

✅ Completed
