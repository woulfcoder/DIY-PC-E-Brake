// Program for using a hall effect sensor as a analog break input for PC.
//
// woulf
// 14-08-2021   Original version.
//---------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_MULTI_AXIS,
  0, 0, false, false, false, false, false, false, false, false, true, true, false);

#define analogIn A0


// set to define the range of the analog read input
static int intDeadzoneMin = 510;
static int intDeadzoneMax = 840;

unsigned int intAnalogRead = 0;

void setup () {
  Joystick.setBrakeRange(intDeadzoneMin, intDeadzoneMax);
  
  Joystick.begin();

  pinMode(analogIn, INPUT);
}

void loop () {
  intAnalogRead = analogRead(analogIn);

  if (intAnalogRead > intDeadzoneMin) {
    Joystick.setBrake(intAnalogRead);
  }
  else {
    Joystick.setBrake(0);
  }
  
  delay(10);
}
