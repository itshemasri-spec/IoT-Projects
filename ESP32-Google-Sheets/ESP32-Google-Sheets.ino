#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// WiFi Credentials
const char* ssid = "";
const char* password = "";

// Google Apps Script ID 
String GOOGLE_SCRIPT_ID = "";

// DHT11 Settings 
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  dht.begin();

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Failed to read from DHT11");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String url =
      "https://script.google.com/macros/s/" +
      GOOGLE_SCRIPT_ID +
      "/exec?temp=" +
      String(temperature) +
      "&hum=" +
      String(humidity);

    Serial.println("Sending Data...");
    Serial.println(url);

    http.begin(url);

    int httpCode = http.GET();

    Serial.print("HTTP Response Code: ");
    Serial.println(httpCode);

    if (httpCode > 0)
    {
      String payload = http.getString();
      Serial.println(payload);
    }
    else
    {
      Serial.println("Error Sending Data");
    }

    http.end();
  }

  delay(10000); // Send data every 10 seconds
}
