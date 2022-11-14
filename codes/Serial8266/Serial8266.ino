/*
 * Copyright (c) 2018, circuits4you.com
 * All rights reserved.
 * Create a TCP Server on ESP8266 NodeMCU.
 * TCP Socket Server Send Receive Demo
 */

#include <ESP8266WiFi.h>

//=======================================================================
//                    Power on setup
//=======================================================================
void setup()
{
  Serial.begin(115200);
  Serial.print("Serial");
}
//=======================================================================
//                    Loop
//=======================================================================

void loop()
{
  int a = analogRead(A0);
  Serial.println(millis());
}
//=======================================================================