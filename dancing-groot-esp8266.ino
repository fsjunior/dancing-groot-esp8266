/*
 *  This file is part of Dancing Groot Project
 *  Copyright (c) 2017 Francisco de Souza Junior (chico.net.br).
 *  
 *  GROOT is trademark from Marvel Characters, Inc. and I use it here 
 *  only for educational and hobbyist purposes, without any financial 
 *  reward.
 *
 *  Foobar is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 
 */

#include "DancingController.h"

DancingController dancingController(D2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char c;
  if(Serial.available()) {
    c = Serial.read();
    switch(c) {
      case 'd':
        dancingController.dance();      
      break;
      case 'a':
        dancingController.shake();
       break;
      case 's':
        dancingController.stop();    
      break;
    }
  }
}
