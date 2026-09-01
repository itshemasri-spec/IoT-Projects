# IoT-Projects
A collection of IoT projects developed using ESP32, ESP8266, sensors, and cloud platforms for real-time monitoring and automation.
# 🔌 IoT Projects

A collection of practical **Internet of Things (IoT) projects** developed using **ESP32, ESP8266, sensors, cloud platforms, web technologies, and smart home automation**.

This repository contains hands-on projects created to explore **embedded systems, sensor interfacing, Wi-Fi communication, IoT platforms, cloud data logging, web-based monitoring, and automation**.

---

## 📚 Projects

| #  | Project                                                                           | Hardware                        | Platform / Technology | Status      |
| -- | --------------------------------------------------------------------------------- | ------------------------------- | --------------------- | ----------- |
| 1  | 🌡️ [ESP32 DHT11 Monitoring](./ESP32-DHT11)                                       | ESP32 + DHT11                   | Arduino IDE           | ✅ Completed |
| 2  | 📧 [ESP32 DHT11 Email Alert](./ESP32-DHT11-Email)                                 | ESP32 + DHT11                   | Email + Wi-Fi         | ✅ Completed |
| 3  | 📊 [ESP32 Google Sheets](./ESP32-Google-Sheets)                                   | ESP32                           | Google Sheets         | ✅ Completed |
| 4  | 💡 [ESP8266 Alexa Smart Lights](./ESP8266-Alexa-SinricPro-Lights)                 | ESP8266 + Relay                 | Sinric Pro + Alexa    | ✅ Completed |
| 5  | 📊 [ESP8266 Animated IoT Dashboard](./ESP8266-Animated-IoT-Dashboard)             | ESP8266                         | Web Dashboard         | ✅ Completed |
| 6  | 💡 [ESP8266 Blynk External LED](./ESP8266-Blynk-External-LED)                     | ESP8266 + LED                   | Blynk IoT             | ✅ Completed |
| 7  | 📡 [ESP8266 Ultrasonic & DHT11 ThingSpeak](./ESP8266-Ultrasonic-DHT11-ThingSpeak) | ESP8266 + HC-SR04 + DHT11       | ThingSpeak            | ✅ Completed |
| 8  | 🌐 [ESP8266 DHT11 Local Web Dashboard](./ESP8266-DHT11-Local-Web-Dashboard)       | ESP8266 + DHT11                 | Local Web Server      | ✅ Completed |
| 9  | 🌐 [ESP8266 DHT11, HC-SR04 & PIR Web Page](./ESP8266-DHT11-HCSR04-PIR-Web-Page)   | ESP8266 + DHT11 + HC-SR04 + PIR | Local Web Server      | ✅ Completed |
| 10 | 💡 [ESP32 Matrix LED IP Control](./ESP32-Matrix-LED-IP-Control)                   | ESP32 + LED Matrix              | Local Web Server      | ✅ Completed |

---

## 🛠️ Hardware & Technologies

### 🔲 Microcontrollers

* ESP32
* ESP8266 NodeMCU

### 📡 Sensors & Components

* DHT11 Temperature & Humidity Sensor
* HC-SR04 Ultrasonic Sensor
* PIR Motion Sensor
* LED
* LED Matrix
* Relay Module

### ☁️ IoT & Cloud Platforms

* Blynk IoT
* ThingSpeak
* Sinric Pro
* Google Sheets
* Amazon Alexa

### 💻 Development Tools

* Arduino IDE
* C/C++
* HTML
* CSS
* JavaScript
* Git
* GitHub

---

## ⚡ Key Areas Covered

These projects provide practical experience in:

* 🔌 Microcontroller programming
* 🌡️ Sensor interfacing
* 📶 Wi-Fi connectivity
* ☁️ Cloud integration
* 📊 IoT data logging
* 🌐 Local web servers
* 📱 Mobile-based IoT control
* 🎙️ Voice-controlled automation
* 🏠 Smart home automation
* 📈 Real-time monitoring
* 📧 Automated notifications
* 💡 Wireless device control

---

## 📁 Repository Structure

```text
IoT-Projects/
│
├── ESP32-DHT11/
│   ├── ESP32-DHT11.ino
│   └── README.md
│
├── ESP32-DHT11-Email/
│   ├── ESP32-DHT11-Email.ino
│   └── README.md
│
├── ESP32-Google-Sheets/
│   ├── ESP32-Google-Sheets.ino
│   └── README.md
│
├── ESP8266-Alexa-SinricPro-Lights/
│   ├── ESP8266-Alexa-SinricPro-Lights.ino
│   └── README.md
│
├── ESP8266-Animated-IoT-Dashboard/
│   ├── ESP8266-Animated-IoT-Dashboard.ino
│   └── README.md
│
├── ESP8266-Blynk-External-LED/
│   ├── ESP8266-Blynk-External-LED.ino
│   └── README.md
│
├── ESP8266-Ultrasonic-DHT11-ThingSpeak/
│   ├── ESP8266-Ultrasonic-DHT11-ThingSpeak.ino
│   └── README.md
│
├── ESP8266-DHT11-Local-Web-Dashboard/
│   ├── ESP8266-DHT11-Local-Web-Dashboard.ino
│   └── README.md
│
├── ESP8266-DHT11-HCSR04-PIR-Web-Page/
│   ├── ESP8266-DHT11-HCSR04-PIR-Web-Page.ino
│   └── README.md
│
├── ESP32-Matrix-LED-IP-Control/
│   ├── ESP32-Matrix-LED-IP-Control.ino
│   └── README.md
│
└── README.md
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/IoT-Projects.git
```

### 2. Open a Project

Navigate to the required project folder and open the `.ino` file using **Arduino IDE**.

### 3. Install Required Libraries

Install the libraries mentioned in the individual project's `README.md`.

### 4. Configure the Project

Before uploading, configure:

* Wi-Fi SSID
* Wi-Fi password
* API keys
* Authentication tokens
* Cloud platform credentials

### 5. Upload to the Board

Select the appropriate board and COM port in Arduino IDE, then upload the program to the ESP32 or ESP8266.

---

## 🔐 Security Notice

**Never upload sensitive credentials to GitHub.**

Before committing code, remove or replace:

```text
Wi-Fi passwords
API keys
Blynk authentication tokens
Sinric Pro credentials
Email passwords
Cloud credentials
```

Use placeholders such as:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

---

## 📈 Future Enhancements

The projects in this repository can be further extended with:

* 📱 Mobile applications
* 🌐 Advanced web dashboards
* ☁️ Cloud databases
* 📊 Real-time data visualization
* 📧 Automated notifications
* 🔔 Threshold-based alerts
* 📡 MQTT communication
* 🏠 Complete smart home automation
* 🤖 AI-powered IoT applications
* 📈 Historical data analysis

---

## 🎯 Purpose

The main purpose of this repository is to document and showcase practical implementations of **IoT and embedded systems concepts** using ESP32 and ESP8266.

Each project focuses on a specific concept, ranging from basic sensor interfacing to cloud connectivity, web-based monitoring, and smart home automation.

---

## 👩‍💻 Author

**Hemasri S S**

B.E. Computer Science and Engineering

This repository contains IoT projects developed for **learning, experimentation, academic work, and practical implementation of embedded and IoT technologies**.

---

⭐ If you find these projects useful, consider giving the repository a star!
