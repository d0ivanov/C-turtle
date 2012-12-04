#include "L293DN.h"

int M1F = 8, M1B = 9, M2F = 10, M2B = 11;// MotorNDirection
L293DN_MotorController motors(M1F, M1B, M2F, M2B, 2); 

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
    byte input = Serial.read();
    Serial.println(input);
    switch (input)
    {
      case 49 : motors.moveBothBackward();
        break;
      case 50 : motors.moveBothForward();
        break;
      case 51 : motors.rotateRight();
        break;
      case 52 : motors.rotateLeft();
        break;
    }
  }
}
