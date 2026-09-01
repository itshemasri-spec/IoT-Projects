#include <WiFi.h>
#include <WebServer.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type and pins
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4 // Change this if you have more or fewer 8x8 panels
#define CLK_PIN   18
#define DATA_PIN  23
#define CS_PIN    5

// Initialize the LED Matrix
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// WiFi credentials
const char* ssid = "";
const char* password = "";

WebServer server(80);

// Global variable to store current text
char matrixMessage[100] = "ESP32 Ready";

// HTML Web Page Source Code
const char HTML_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 LED Matrix Controller</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; background-color: #f4f4f9; margin: 0; padding: 20px; }
        .container { max-width: 500px; margin: auto; background: white; padding: 30px; border-radius: 10px; box-shadow: 0 4px 15px rgba(0,0,0,0.1); }
        h1 { color: #333; }
        input[type="text"] { width: 80%; padding: 12px; margin: 20px 0; border: 2px solid #ddd; border-radius: 5px; font-size: 16px; }
        button { background-color: #007bff; color: white; padding: 12px 24px; border: none; border-radius: 5px; font-size: 16px; cursor: pointer; transition: background 0.3s; }
        button:hover { background-color: #0056b3; }
        .status { margin-top: 20px; color: green; font-weight: bold; }
    </style>
</head>
<body>
    <div class="container">
        <h1>LED Matrix Text</h1>
        <input type="text" id="textInput" placeholder="Enter text here..." maxlength="99">
        <br>
        <button onclick="sendText()">Update Display</button>
        <div id="statusMessage" class="status"></div>
    </div>

    <script>
        function sendText() {
            var text = document.getElementById("textInput").value;
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/msg?text=" + encodeURIComponent(text), true);
            xhr.onload = function () {
                if (xhr.status === 200) {
                    document.getElementById("statusMessage").innerText = "Display Updated Successfully!";
                    setTimeout(() => { document.getElementById("statusMessage").innerText = ""; }, 3000);
                }
            };
            xhr.send();
        }
    </script>
</body>
</html>
)=====";

// Route handler for Root Page
void handleRoot() {
  server.send(200, "text/html", HTML_PAGE);
}

// Route handler to capture the text parameter from the Web URL
void handleMessage() {
  if (server.hasArg("text")) {
    String message = server.arg("text");
    message.toCharArray(matrixMessage, sizeof(matrixMessage));
    
    // Reset display animations to show the new text
    myDisplay.displayReset(); 
    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize LED matrix hardware
  myDisplay.begin();
  myDisplay.setInvert(false);
  // Set parameters: Alignment, speed, pause time, effect-in, effect-out
  myDisplay.displayText(matrixMessage, PA_CENTER, 100, 2000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup Web Server Routes
  server.on("/", handleRoot);
  server.on("/msg", handleMessage);
  server.begin();
}

void loop() {
  server.handleClient();

  // Keep rendering and scrolling the display animation loop
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}

