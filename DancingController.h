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
 
#ifndef _DANCING_CONTROLLER_H_
#define _DANCING_CONTROLLER_H_

#include <Servo.h>
#include <Ticker.h>



class DancingController {
  private:
    Servo servo;
    int pin;

  public:
    DancingController(int pin);

    void shake();
};




#endif /* _DANCING_CONTROLLER_H_ */
