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
 
#include "RESTServer.h"
#include <ArduinoJson.h>
#include <functional>


#define DATA_ARRAY_SIZE 64


void RESTServer::replySuccess()
{
  StaticJsonBuffer<DATA_ARRAY_SIZE> actualBuffer;
  JsonObject& root = actualBuffer.createObject();
  root["Result"] = true;

  String output;
  root.printTo(output);
  server.send ( 200, "application/json", output);  
}


void RESTServer::handlePing()
{
  replySuccess();
}

void RESTServer::handleShake()
{
  if(shakeCallback)
    shakeCallback();
  replySuccess();
}

RESTServer::RESTServer(int port):server(port)
{ 
  server.on("/shake", HTTP_POST, std::bind(&RESTServer::handleShake, this));
  server.on("/ping", HTTP_GET, std::bind(&RESTServer::handlePing, this));
}

void RESTServer::onShake(std::function<void()> fn)
{
  shakeCallback = fn;
}

void RESTServer::begin()
{
  server.begin();   
}

void RESTServer::handleClient()
{
  server.handleClient();
}

