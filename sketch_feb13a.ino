#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 500 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 2500 // this is the 'maximum' pulse length count (out of 4096)

#define zadek1 0 
#define modul2 1   // bulvy nahoru dolu 70-110 _90 je stred
#define modul3 2    // pravy horni vicko 90-165
#define modul4 3  // 
#define hlava5 4     //         

#define mid 1500

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
