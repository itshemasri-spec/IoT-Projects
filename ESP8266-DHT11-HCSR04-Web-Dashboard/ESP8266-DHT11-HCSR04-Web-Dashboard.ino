#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

// =======================
// WiFi Credentials
// =======================

const char* ssid = "";
const char* password = "";

// =======================
// DHT11 Configuration
// =======================

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// =======================
// HC-SR04 Configuration
// =======================

#define TRIG_PIN D5
#define ECHO_PIN D6

// =======================
// Web Server
// =======================

ESP8266WebServer server(80);

// =======================
// HTML Page
// =======================

String webpage = R"rawliteral(

<!DOCTYPE html>
<html>

<head>

<meta name="viewport" content="width=device-width, initial-scale=1">

<title>ESP8266 IoT Dashboard</title>

<style>

body{
font-family:Arial;
text-align:center;
background:#f2f2f2;
margin:20px;
}

h1{
color:#333;
}

.card{
background:white;
width:280px;
margin:15px auto;
padding:20px;
border-radius:15px;
box-shadow:0px 0px 10px gray;
}

.value{
font-size:32px;
font-weight:bold;
color:blue;
}

</style>

</head>

<body>

<h1>IoT Dashboard</h1>

<div class="card">
<h2>Temperature</h2>
<div class="value" id="temp">--</div>
</div>

<div class="card">
<h2>Humidity</h2>
<div class="value" id="hum">--</div>
</div>

<div class="card">
<h2>Distance</h2>
<div class="value" id="dist">--</div>
</div>

<script>

function updateData(){

fetch('/data')
.then(response => response.json())
.then(data => {

document.getElementById("temp").innerHTML =
data.temperature + " °C";

document.getElementById("hum").innerHTML =
data.humidity + " %";

document.getElementById("dist").innerHTML =
data.distance + " cm";

});

}

setInterval(updateData,2000);

updateData();

</script>

</body>

</html>

)rawliteral";

// =======================
// Distance Function
// =======================

float getDistance() {

digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);

digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);

digitalWrite(TRIG_PIN, LOW);

long duration = pulseIn(ECHO_PIN, HIGH, 30000);

float distance = duration * 0.0343 / 2;

return distance;
}

// =======================
// Root Page
// =======================

void handleRoot() {

server.send(200, "text/html", webpage);

}

// =======================
// Sensor Data API
// =======================

void handleData() {

float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
float distance = getDistance();

if (isnan(temperature))
temperature = 0;

if (isnan(humidity))
humidity = 0;

String json = "{";
json += "\"temperature\":" + String(temperature,1) + ",";
json += "\"humidity\":" + String(humidity,1) + ",";
json += "\"distance\":" + String(distance,1);
json += "}";

server.send(200, "application/json", json);

}

// =======================
// Setup
// =======================

void setup() {

Serial.begin(115200);

dht.begin();

pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);

WiFi.begin(ssid, password);

Serial.println();
Serial.print("Connecting to WiFi");

while (WiFi.status() != WL_CONNECTED) {

delay(500);
Serial.print(".");

}

Serial.println();
Serial.println("WiFi Connected!");

Serial.print("IP Address: ");
Serial.println(WiFi.localIP());

server.on("/", handleRoot);
server.on("/data", handleData);

server.begin();

Serial.println("Web Server Started");

}

// =======================
// Loop
// =======================

void loop() {

server.handleClient();

}
