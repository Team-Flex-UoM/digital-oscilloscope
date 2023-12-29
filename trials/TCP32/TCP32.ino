/*
 * Copyright (c) 2018, circuits4you.com
 * All rights reserved.
 * Create a TCP Server on ESP8266 NodeMCU.
 * TCP Socket Server Send Receive Demo
 */

#include <WiFi.h>

// #include "espconn.h"
// #include "user_config.h"

#define SendKey 0 // Button to send data Flash BTN on NodeMCU

int port = 8888; // Port number
WiFiServer server(port);

// Server connect to WiFi Network
char * ssid_ap = "test_esp";
char * password_ap = "12345678";
IPAddress ip(192,168,11,4); // arbitrary IP address (doesn't conflict w/ local network)
IPAddress gateway(192,168,11,1);
IPAddress subnet(255,255,255,0);


int count = 0;
//=======================================================================
//                    Power on setup
//=======================================================================
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip,gateway,subnet);
  WiFi.softAP(ssid_ap,password_ap);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Wait for connection
  // Serial.println("Connecting to Wifi");
  
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);
  //   Serial.print(".");
  //   delay(500);
  // }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid_ap);

  // Serial.print("IP address: ");
  // Serial.println(WiFi.localIP());
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
      //Serial.println(client.isKeepAliveEnabled());
    }

    int i = 0;

    while (client.connected())
    {
      while (client.available() > 0)
      {
        // read data from the connected client
        Serial.write(client.read());
      }
      client.println(millis());
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