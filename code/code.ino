//
// 14-08-2021   Original version.
//---------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick;

#define analogIn A0

int intDeadzoneMin = 515;
int intDeadzoneMax = 850;

void setup () {
  Joystick.setBrakeRange(intDeadzoneMin, intDeadzoneMax);
  
  Joystick.begin();

  pinMode(analogIn, INPUT);
}

void loop () {
  
}
