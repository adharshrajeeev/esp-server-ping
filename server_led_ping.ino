#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>  // Include ESP8266WebServer library for HTTP server functionality
#include <ArduinoJson.h>

// Pin configurations
int ledPin = 12;  // LED pin

// Wi-Fi credentials
const char* ssid = "wifiName";          // Replace with your Wi-Fi SSID
const char* password = "wifiPassword";  // Replace with your Wi-Fi password

ESP8266WebServer server(80);  // Create an instance of the ESP8266WebServer to handle HTTP requests

void setup() {
  // Pin setup
  pinMode(ledPin, OUTPUT);     // Set LED as output

  // Start serial communication for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);

  // Wait for Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Set up HTTP server routes
  server.on("/trigger_led", HTTP_GET, []() {
    // Trigger the LED when the /trigger_led endpoint is hit
    digitalWrite(ledPin, HIGH);  // Turn the LED ON
    server.send(200, "text/plain", "LED is ON");  // Send response back
    Serial.println("LED Triggered");
  });

  server.on("/turnOff", HTTP_GET, []() {
    // Trigger the LED when the /trigger_led endpoint is hit
    digitalWrite(ledPin, LOW);                    // Turn the LED ON
    server.send(200, "text/plain", "LED is OFF");  // Send response back
    Serial.println("LED off triggered");
  });

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // Handle incoming client requests
}
