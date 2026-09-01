#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

const char* ssid = "";
const char* password = "";

DHT dht(DHTPIN, DHTTYPE);
ESP8266WebServer server(80);

String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>ESP8266 Dashboard</title>

<style>
body{
    font-family: Arial;
    text-align:center;
    background:#f0f0f0;
}
.card{
    background:white;
    width:250px;
    margin:auto;
    padding:20px;
    border-radius:10px;
    box-shadow:0 0 10px gray;
}
.value{
    font-size:30px;
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

<br>

<div class="card">
<h2>Humidity</h2>
<div class="value" id="hum">--</div>
</div>

<script>

setInterval(function(){

fetch('/data')
.then(response => response.json())
.then(data => {

document.getElementById("temp").innerHTML =
data.temperature + " °C";

document.getElementById("hum").innerHTML =
data.humidity + " %";

});

},1000);

</script>

</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", webpage);
}

void handleData() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  String json = "{";
  json += "\"temperature\":" + String(t) + ",";
  json += "\"humidity\":" + String(h);
  json += "}";

  server.send(200, "application/json", json);
}

void setup() {

  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/data", handleData);

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();
}
