// Program for using a hall effect sensor as a analog break input for PC.
//
// woulf
// 14-08-2021   Original version.
//---------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick;

#define analogIn A0

unsigned int intAnalogRead;
int intDeadzoneMin = 515;
int intDeadzoneMax = 850;

void setup () {
  Joystick.setBrakeRange(intDeadzoneMin, intDeadzoneMax);
  
  Joystick.begin();

  pinMode(analogIn, INPUT);
}

void loop () {
  intAnalogRead = analogRead(analogIn);

  if (intAnalogRead > intDeadzoneMin && intAnalogRead < intDeadzoneMax) {
    Joystick.setBrake(intAnalogRead);
  }
}
