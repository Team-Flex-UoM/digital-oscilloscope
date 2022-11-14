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

char *ssid_ap = "test_esp8266";
char *password_ap = "12345678";
IPAddress ip(192, 168, 11, 4); // arbitrary IP address (doesn't conflict w/ local network)
IPAddress gateway(192, 168, 11, 1);
IPAddress subnet(255, 255, 255, 0);

int count = 0;
//=======================================================================
//                    Power on setup
//=======================================================================
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid_ap, password_ap);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
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
      int samples[100];
      unsigned long t1 = millis();
      for (int i = 0; i < 100; i++)
        samples[i] = analogRead(A0);
      unsigned long t2 = millis();
      client.print(t2 - t1);
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