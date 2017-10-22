/*
 *  This file is part of Dancing Groot Project
 *  Copyright (c) 2017 Francisco de Souza Junior (chico.net.br).
 *  
 *  GROOT is trademark from Marvel Characters, Inc. and I use it here 
 *  only for educational and hobbyist purposes, without any financial 
 *  reward.
 *
 *  dancing-groot-esp8266 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  dancing-groot-esp8266 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with dancing-groot-esp8266.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 
 */

#include "DancingController.h"
#include <WiFiClient.h>
#include "RESTServer.h"
#include <ESP8266mDNS.h>

DancingController dancingController(D2);
RESTServer restServer(80);

void setup() 
{
  Serial.begin(115200);

  WiFi.begin("", ""); //change ssid and password here
  
  Serial.println("");

    // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (!MDNS.begin("groot")) {
      Serial.println("Error setting up MDNS responder!");
  }
  

  restServer.onShake(std::bind(&DancingController::shake, &dancingController));
  
  restServer.begin();
}

void loop() 
{
  restServer.handleClient();
}
