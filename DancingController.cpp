
#include "DancingController.h"


#define MIN_DANCE_SERVO_MS 1300
#define MAX_DANCE_SERVO_MS 1500


static inline int getTimeoutFromDanceStatus(DanceStatus danceStatus)
{
  return static_cast<int>(danceStatus);
}



DancingController::DancingController(int pin):pin(pin)
{
  //servo.attach(pin);  
  this->stop();
}


void DancingController::stop()
{
  danceStatus = DanceStatus::stopped;
  danceTicker.detach();
  if(servo.attached())
    servo.detach();
}

static void danceCallback(Servo *servo)
{
  //Servo *servo = static_cast<Servo *>(data);

  if(servo->readMicroseconds() == MAX_DANCE_SERVO_MS) 
    servo->write(MIN_DANCE_SERVO_MS);
  else
    servo->write(MAX_DANCE_SERVO_MS);
  
}

void DancingController::start()
{
  if(!servo.attached()) {
    servo.attach(pin);
  }
  
  danceTicker.detach();
  danceTicker.attach_ms(getTimeoutFromDanceStatus(danceStatus), danceCallback, &servo);


  
  //void attach_ms(uint32_t milliseconds, void (*callback)(TArg), TArg arg)
  //typedef void (*callback_with_arg_t)(void*);
}

void DancingController::dance()
{
  danceStatus = DanceStatus::dancing;
  start();
 
}
void DancingController::shake()
{
  danceStatus = DanceStatus::shaking;
  start();
}



 
