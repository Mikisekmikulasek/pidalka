#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)
#define USMIN  500 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2500

#define zadek1 0 
#define modul2 1   // bulvy nahoru dolu 70-110 _90 je stred
#define modul3 2    // pravy horni vicko 90-165
#define modul4 3  // 
#define hlava5 4     //         

#define mid_zadek1 185
#define mid_modul2 205
#define mid_modul3 190
#define mid_modul4 200
#define mid_hlava5 205



#define maxu_zadek1 312
#define maxu_modul2 240
#define maxu_modul3 10
#define maxu_modul4 240
#define maxu_hlava5 340




#define maxu_slide_zadek1 295
#define maxu_slide_hlava5 325
#define relax_slide_zadek1 170
#define relax_slide_hlava5 190
 


uint16_t current_zadek1_pos{0};
uint16_t current_modul2_pos{0};
uint16_t current_modul3_pos{0};
uint16_t current_modul4_pos{0};
uint16_t current_hlava5_pos{0};


#define COSMETIC_DELAY 400
#define SERVO_DELAY 15


long angleToPulse(uint16_t angle)
{
  return map(angle, 0, 360, SERVOMIN, SERVOMAX);
}

void move(uint8_t part, uint16_t pos)
{
  pwm.setPWM(part, 0, angleToPulse(pos));
}




void RELAX_POS()
{
  move(zadek1, mid_zadek1);
  move(modul2, mid_modul2);
  move(modul3, mid_modul3);
  move(modul4, mid_modul4);
  move(hlava5, mid_hlava5);

 current_zadek1_pos = mid_zadek1;
 current_modul2_pos = mid_modul2;
 current_modul3_pos = mid_modul3;
 current_modul4_pos = mid_modul4;
 current_hlava5_pos = mid_hlava5;
}

void MAXU_POS()
{
  move(zadek1, maxu_zadek1);
  move(modul2, maxu_modul2);
  move(modul3, maxu_modul3);
  move(modul4, maxu_modul4);
  move(hlava5, maxu_hlava5);

 current_zadek1_pos = maxu_zadek1;
 current_modul2_pos = maxu_modul2;
 current_modul3_pos = maxu_modul3;
 current_modul4_pos = maxu_modul4;
 current_hlava5_pos = maxu_hlava5;
}




void SLIDE_HLAVA_START_POS()
{
  move(zadek1, maxu_zadek1);
  move(modul2, maxu_modul2);
  move(modul3, maxu_modul3);
  move(modul4, maxu_modul4);
  move(hlava5, maxu_slide_hlava5);

 current_zadek1_pos = maxu_zadek1;
 current_modul2_pos = maxu_modul2;
 current_modul3_pos = maxu_modul3;
 current_modul4_pos = maxu_modul4;
 current_hlava5_pos = maxu_slide_hlava5;
}
void  SLIDE_HLAVA_RELAX_POS()
{
  move(zadek1, mid_zadek1);
  move(modul2, mid_modul2);
  move(modul3, mid_modul3);
  move(modul4, mid_modul4);
  move(hlava5, relax_slide_hlava5);

 current_zadek1_pos = mid_zadek1;
 current_modul2_pos = mid_modul2;
 current_modul3_pos = mid_modul3;
 current_modul4_pos = mid_modul4;
 current_hlava5_pos = relax_slide_hlava5;
}



void SLIDE_ZADEK_START_POS()
{
  move(zadek1, maxu_slide_zadek1);
  move(modul2, maxu_modul2);
  move(modul3, maxu_modul3);
  move(modul4, maxu_modul4);
  move(hlava5, maxu_hlava5);

 current_zadek1_pos = maxu_slide_zadek1;
 current_modul2_pos = maxu_modul2;
 current_modul3_pos = maxu_modul3;
 current_modul4_pos = maxu_modul4;
 current_hlava5_pos = maxu_hlava5;
}

void RELAX_ZADEK_START_POS()
{
  move(zadek1, relax_slide_zadek1);
  move(modul2, mid_modul2);
  move(modul3, mid_modul3);
  move(modul4, mid_modul4);
  move(hlava5, mid_hlava5);

 current_zadek1_pos = relax_slide_zadek1;
 current_modul2_pos = mid_modul2;
 current_modul3_pos = mid_modul3;
 current_modul4_pos = mid_modul4;
 current_hlava5_pos = mid_hlava5;
}

void setup()  {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

  delay(COSMETIC_DELAY);
  RELAX_POS();
}



  void loop() {
     RELAX_POS();
delay (1000);
  RELAX_ZADEK_START_POS();
 delay (1000);
  SLIDE_ZADEK_START_POS();
 delay (1000);
  MAXU_POS();
 delay (1000);
  SLIDE_HLAVA_START_POS();
 delay (1000);
  SLIDE_HLAVA_RELAX_POS();
   delay (1000);


}



