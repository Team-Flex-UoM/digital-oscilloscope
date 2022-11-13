/*
 * Copyright (c) 2018, circuits4you.com
 * All rights reserved.
 * Create a TCP Server on ESP8266 NodeMCU.
 * TCP Socket Server Send Receive Demo
 */

#include <ESP8266WiFi.h>

#include "espconn.h"
#include "user_config.h"

#define SendKey 0 // Button to send data Flash BTN on NodeMCU

int port = 8888; // Port number
WiFiServer server(port);

// Server connect to WiFi Network
const char *ssid = "SLT FIBER ABEY";   // Enter your wifi SSID
const char *password = "rc62669699ac"; // Enter your wifi Password

int count = 0;
//=======================================================================
//                    Power on setup
//=======================================================================
void setup()
{
  Serial.begin(115200);
  pinMode(SendKey, INPUT_PULLUP); // Btn to send data
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); // Connect to wifi

  // Wait for connection
  Serial.println("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println(port);
}
//=======================================================================
//                    Loop
//=======================================================================

void loop()
{
  WiFiClient client = server.available();
  // client.keepAlive();
  if (client)
  {
    if (client.connected())
    {
      Serial.println("Client Connected");
      Serial.println(client.isKeepAliveEnabled());
    }

    int i = 0;

    while (client.connected())
    {
      while (client.available() > 0)
      {
        // read data from the connected client
        Serial.write(client.read());
      }
      client.print(i++);
      // client.write('\0');
      // client.flush();
      // delay(100);
      // break;
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}
//=======================================================================