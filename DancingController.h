#ifndef _DANCING_CONTROLLER_H_
#define _DANCING_CONTROLLER_H_

#include <Servo.h>
#include <Ticker.h>


enum class DanceStatus : int {
    stopped = 0, 
    dancing = 250, 
    shaking = 150
};


class DancingController {
  private:
    Servo servo;
    Ticker danceTicker;
    int pin;
    DanceStatus danceStatus;

    void start();


  public:
    DancingController(int pin);
  
    //void setDanceStatus(DanceStatus danceStatus);

    void stop();
    void dance();
    void shake();
    
};




#endif /* _DANCING_CONTROLLER_H_ */
