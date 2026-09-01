#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
 
// ==========================
// WiFi Credentials
// ==========================
const char* ssid = "";
const char* password = "";

// ==========================
// DHT11
// ==========================
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ==========================
// HC-SR04
// ==========================
#define TRIG_PIN D5
#define ECHO_PIN D6

// ==========================
// PIR
// ==========================
#define PIR_PIN D7

// ==========================
// Web Server
// ==========================
ESP8266WebServer server(80);

// ==========================
// HTML Dashboard
// ==========================
String webpage = R"rawliteral(

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">

<title>ESP8266 IoT Dashboard</title>

<style>

body{
font-family:Arial;
background:#f0f0f0;
text-align:center;
}

.card{
background:white;
width:300px;
margin:15px auto;
padding:20px;
border-radius:15px;
box-shadow:0px 0px 10px gray;
}

.value{
font-size:28px;
font-weight:bold;
color:blue;
}
.thermometer-container{
display:flex;
flex-direction:column;
align-items:center;
margin-top:10px;
}

.thermometer{
width:40px;
height:180px;
border:4px solid white;
border-radius:25px;
position:relative;
overflow:hidden;
background:rgba(255,255,255,0.1);
}

.thermo-fill{
position:absolute;
bottom:0;
width:100%;
height:0%;
background:#00c6ff;
transition:height 1s ease,
background 1s ease;
}

.bulb{
width:60px;
height:60px;
background:#00c6ff;
border-radius:50%;
margin-top:-10px;
transition:background 1s ease;
}
.tank-container{
display:flex;
justify-content:center;
margin-top:10px;
}

.tank{
width:80px;
height:180px;
border:4px solid white;
border-radius:15px;
overflow:hidden;
position:relative;
background:rgba(255,255,255,0.1);
}

.water-fill{
position:absolute;
bottom:0;
width:100%;
height:0%;
background:#00c6ff;
transition:height 1s ease,
background 1s ease;
}

.ring-bg{
fill:none;
stroke:#444;
stroke-width:12;
}

.ring-progress{
fill:none;
stroke:#00ff88;
stroke-width:12;
stroke-linecap:round;

transform:rotate(-90deg);
transform-origin:90px 90px;

transition:
stroke-dashoffset 1s ease,
stroke 1s ease;
}

.motionSafe{
color:green;
font-weight:bold;
}

.motionDetected{
color:red;
font-weight:bold;
}
.motionSafe{
color:green;
font-weight:bold;
}

.motionDetected{
color:red;
font-weight:bold;
animation:pulse 1s infinite;
}

@keyframes pulse{
0%{transform:scale(1);}
50%{transform:scale(1.1);}
100%{transform:scale(1);}
}
</style>
</head>

<body>

<h1>ESP8266 IoT Dashboard</h1>

<div class="card">

<h2>🌡 Temperature</h2>

<div class="value" id="temp">--</div>

<div class="thermometer-container">

<div class="thermometer">
<div id="thermoFill" class="thermo-fill"></div>
</div>

<div id="thermoBulb" class="bulb"></div>

</div>

</div>
<div class="card">

<h2>💧 Humidity</h2>

<div class="value" id="hum">--</div>

<div class="tank-container">

<div class="tank">

<div id="waterFill"
class="water-fill">
</div>

</div>

</div>

</div>
<div class="card">

<h2>📏 Distance</h2>

<div class="value" id="dist">--</div>

<svg width="180" height="180">

<circle
cx="90"
cy="90"
r="70"
class="ring-bg"
/>

<circle
cx="90"
cy="90"
r="70"
id="distanceRing"
class="ring-progress"
/>

</svg>

</div>

<div class="card">
<h2>Motion Status</h2>
<div class="value" id="motion">--</div>
</div>

<script>
const radius = 70;

const circumference =
2 * Math.PI * radius;

const ring =
document.getElementById(
"distanceRing"
);

ring.style.strokeDasharray =
circumference;

ring.style.strokeDashoffset =
circumference;

function updateData(){

fetch('/data')
.then(response => response.json())
.then(data => {

document.getElementById("temp").innerHTML =
data.temperature + " °C";
let tempValue = data.temperature;

let fillPercent =
Math.min((tempValue / 50) * 100, 100);

document.getElementById("thermoFill")
.style.height =
fillPercent + "%";

let color = "#00c6ff";

if(tempValue > 35)
{
  color = "#ff4444";
}
else if(tempValue > 25)
{
  color = "#00ff88";
}

document.getElementById("thermoFill")
.style.background = color;

document.getElementById("thermoBulb")
.style.background = color;

document.getElementById("hum").innerHTML =
data.humidity + " %";
let humidityValue =
data.humidity;

document.getElementById("waterFill")
.style.height =
humidityValue + "%";
let waterColor = "#00c6ff";

if(humidityValue > 80)
{
waterColor = "#0044ff";
}
else if(humidityValue > 60)
{
waterColor = "#00c6ff";
}
else if(humidityValue > 40)
{
waterColor = "#00ff88";
}
else
{
waterColor = "#ffaa00";
}

document.getElementById("waterFill")
.style.background =
waterColor;

document.getElementById("dist").innerHTML =
data.distance + " cm";
let distance =
data.distance;

// Assume sensor range 0–200 cm

let percent =
100 - ((distance / 200) * 100);

percent =
Math.max(
0,
Math.min(100, percent)
);

let offset =
circumference -
(percent / 100)
* circumference;

ring.style.strokeDashoffset =
offset;
let ringColor =
"#00ff88";

if(distance < 50)
{
ringColor =
"#ff4444";
}
else if(distance < 100)
{
ringColor =
"#ffaa00";
}

ring.style.stroke =
ringColor;

if(data.motion == 1)
{
document.getElementById("motion").innerHTML =
"🚨 Motion Detected";

document.getElementById("motion").className =
"value motionDetected";
}
else
{
document.getElementById("motion").innerHTML =
"✅ No Motion";

document.getElementById("motion").className =
"value motionSafe";
}
if(data.motion == 1)
{
document.getElementById("motion")
.innerHTML =
"🚨 MOTION DETECTED";

document.getElementById("motion")
.className =
"value motionDetected";
}
else
{
document.getElementById("motion")
.innerHTML =
"🟢 SAFE";

document.getElementById("motion")
.className =
"value motionSafe";
}
});

}

setInterval(updateData,2000);
updateData();

</script>

</body>
</html>

)rawliteral";

// ==========================
// HC-SR04 Function
// ==========================
float getDistance()
{
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);

digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);

digitalWrite(TRIG_PIN, LOW);

long duration = pulseIn(ECHO_PIN, HIGH, 30000);

if(duration == 0)
return 0;

float distance = duration * 0.0343 / 2;

return distance;
}

// ==========================
// Root Page
// ==========================
void handleRoot()
{
server.send(200, "text/html", webpage);
}

// ==========================
// Sensor Data API
// ==========================
void handleData()
{
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();

if(isnan(temperature))
temperature = 0;

if(isnan(humidity))
humidity = 0;

float distance = getDistance();

int motion = digitalRead(PIR_PIN);

String json = "{";

json += "\"temperature\":" + String(temperature,1) + ",";
json += "\"humidity\":" + String(humidity,1) + ",";
json += "\"distance\":" + String(distance,1) + ",";
json += "\"motion\":" + String(motion);

json += "}";

server.send(200, "application/json", json);
}

// ==========================
// Setup
// ==========================
void setup()
{
Serial.begin(115200);

dht.begin();

pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);

pinMode(PIR_PIN, INPUT);

WiFi.begin(ssid, password);

Serial.print("Connecting to WiFi");

while(WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}

Serial.println();
Serial.println("WiFi Connected");

Serial.print("IP Address: ");
Serial.println(WiFi.localIP());

server.on("/", handleRoot);
server.on("/data", handleData);

server.begin();

Serial.println("Web Server Started");
}

// ==========================
// Loop
// ==========================
void loop()
{
server.handleClient();
}
