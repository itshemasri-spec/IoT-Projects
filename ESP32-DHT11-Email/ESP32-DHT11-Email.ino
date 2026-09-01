#include <WiFi.h>
#include <ESP_Mail_Client.h>
#include <DHT.h>

// WiFi Credentials
#define WIFI_SSID "project"
#define WIFI_PASSWORD "12345678"

// Gmail Credentials
#define AUTHOR_EMAIL "itshemasri@gmail.com"
#define AUTHOR_PASSWORD "rtxbyzbycbtatntr"
#define RECIPIENT_EMAIL "23cse055@vcew.ac.in"

// DHT11 Configuration
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

SMTPSession smtp;

void setup() {
  Serial.begin(115200);

  dht.begin();

  Serial.println("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C  Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Send email if temperature exceeds 36°C
  if (temp > 36) {
    sendEmail(temp, hum);

    // Prevent continuous emails
    delay(60000);
  }

  delay(5000);
}

void sendEmail(float temp, float hum) {

  Session_Config config;

  config.server.host_name = "smtp.gmail.com";
  config.server.port = 465;

  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;

  SMTP_Message message;

  message.sender.name = "ESP32 Alert";
  message.sender.email = AUTHOR_EMAIL;

  message.subject = "Temperature Alert";

  message.addRecipient("User", RECIPIENT_EMAIL);

  String htmlMsg =
    "<h2>Temperature Alert!</h2>"
    "<p>Temperature: " + String(temp) + " °C</p>"
    "<p>Humidity: " + String(hum) + " %</p>";

  message.html.content = htmlMsg.c_str();

  if (!smtp.connect(&config)) {
    Serial.println("SMTP Connection Failed");
    return;
  }

  if (MailClient.sendMail(&smtp, &message)) {
    Serial.println("Email Sent Successfully");
  } else {
    Serial.println("Email Failed");
    Serial.println(smtp.errorReason());
  }
}
