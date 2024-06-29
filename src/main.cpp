#include "Arduino.h"
#include <WiFi.h>
#include <config.h>
#include <hardware.h>

// Create a webserver
WiFiServer server(80);

// Defining Classes
Button button(21,18,5,19);
Motor leftMotor(25,26);
Motor rightMotor(32,33);

// Setup Runtime
void setup()
{
    // Starting serial communication
    Serial.begin(115200);
    Serial.println("---Init---");

    // Starting the access point
    Serial.print("Starting the Acess Point... ");
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(ip, gateway, subnet);
    WiFi.softAP(ssid, password);

    Serial.println("OK");

    // Stating the server
    Serial.print("Starting the Web Server... ");
    server.begin();

    Serial.println("OK");

    // Init modules
    button.init();
    leftMotor.init();
    rightMotor.init();

    Serial.println("---Runtime---");
    // Setting "status" led
    button.setLeds(1,0,1);
}

// Loop Runtime
void loop()
{
    WiFiClient client = server.available();
      if (client) {

        // Read the client's request
        String request = client.readStringUntil('\r');
        client.flush();

        // Send the response to the client
        String response = "HTTP/1.1 200 OK\r\n";
        response += "Content-Type: text/html\r\n";
        response += "Connection: close\r\n\r\n";
        response += "<!DOCTYPE HTML>\r\n<html>\r\n";
        response += "<h1>Hello, World!</h1>\r\n";
        response += "</html>\r\n";

        client.print(response);

        // Close the connection
        client.stop();
      }
}
