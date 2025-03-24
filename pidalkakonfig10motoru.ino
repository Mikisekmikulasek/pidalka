#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 110 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 550 // this is the 'maximum' pulse length count (out of 4096)
#define USMIN  500 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2500

#define xzadek1 0 
#define ymodul2 1   
#define xmodul3 2    
#define ymodul4 3  
#define xmodul5 4  
#define ymodul6 5 
#define xmodul7 6 
#define ymodul8 7
#define xhlava9 8
       

#define mid_xzadek1 85
#define mid_ymodul2 95
#define mid_xmodul3 90
#define mid_ymodul4 95
#define mid_xmodul5 90
#define mid_ymodul6 95
#define mid_xmodul7 85
#define mid_ymodul8 92
#define mid_xhlava9 97

#define max_xzadek1 180
#define max_ymodul2 180
#define max_xmodul3 180
#define max_ymodul4 180
#define max_xmodul5 180
#define max_ymodul6 180
#define max_xmodul7 180
#define max_ymodul8 180
#define max_xhlava9 180

#define min_xzadek1 0
#define min_ymodul2 0
#define min_xmodul3 0
#define min_ymodul4 0
#define min_xmodul5 0
#define min_ymodul6 0
#define min_xmodul7 0
#define min_ymodul8 0
#define min_xhlava9 0

#define usoft_xzadek1 43
#define usoft_ymodul2 90
#define usoft_xmodul3 50
#define usoft_ymodul4 95
#define usoft_xmodul5 120
#define usoft_ymodul6 95
#define usoft_xmodul7 50
#define usoft_ymodul8 92
#define usoft_xhlava9 60

#define uhard_xzadek1 0
#define uhard_ymodul2 90
#define uhard_xmodul3 30
#define uhard_ymodul4 95
#define uhard_xmodul5 160
#define uhard_ymodul6 95
#define uhard_xmodul7 30
#define uhard_ymodul8 92
#define uhard_xhlava9 20

#define slide_uhard_xzadek1 15
#define slide_mid_xzadek1 110


#define slide_uhard_xhlava9 0
#define slide_mid_xhlava9 120
uint16_t current_xzadek1_pos{0};
uint16_t current_ymodul2_pos{0};
uint16_t current_xmodul3_pos{0};
uint16_t current_ymodul4_pos{0};
uint16_t current_xmodul5_pos{0};
uint16_t current_ymodul6_pos{0};
uint16_t current_xmodul7_pos{0};
uint16_t current_ymodul8_pos{0};
uint16_t current_xhlava9_pos{0};



#define COSMETIC_DELAY 400
#define SERVO_DELAY 20

#define SLOW_SERVO_DELAY 10  // Delší pauza mezi mezikroky
#define EXTRA_DELAY 50    

long angleToPulse(uint16_t angle)
{
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void move(uint8_t part, uint16_t pos)
{
  pwm.setPWM(part, 0, angleToPulse(pos));
}



 // Pauza mezi pohybem každého serva



  // Aktualizujeme pozice pro další cyklus
 








void MID_POS()
{
  move(xzadek1, mid_xzadek1);
  move(ymodul2, mid_ymodul2);
  move(xmodul3, mid_xmodul3);
  move(ymodul4, mid_ymodul4);
  move(xmodul5, mid_xmodul5);
  move(ymodul6, mid_ymodul6);
  move(xmodul7, mid_xmodul7);
  move(ymodul8, mid_ymodul8);
  move(xhlava9, mid_xhlava9);

 current_xzadek1_pos = mid_xzadek1;
 current_ymodul2_pos = mid_ymodul2;
 current_xmodul3_pos = mid_xmodul3;
 current_ymodul4_pos = mid_ymodul4;
 current_xmodul5_pos = mid_xmodul5;
 current_ymodul6_pos = mid_ymodul6;
 current_xmodul7_pos = mid_xmodul7;
 current_ymodul8_pos = mid_ymodul8;
 current_xhlava9_pos = mid_xhlava9;

}

void MAX_POS()
{
  move(xzadek1, max_xzadek1);
  move(ymodul2, max_ymodul2);
  move(xmodul3, max_xmodul3);
  move(ymodul4, max_ymodul4);
  move(xmodul5, max_xmodul5);
  move(ymodul6, max_ymodul6);
  move(xmodul7, max_xmodul7);
  move(ymodul8, max_ymodul8);
  move(xhlava9, max_xhlava9);

 current_xzadek1_pos = max_xzadek1;
 current_ymodul2_pos = max_ymodul2;
 current_xmodul3_pos = max_xmodul3;
 current_ymodul4_pos = max_ymodul4;
 current_xmodul5_pos = max_xmodul5;
 current_ymodul6_pos = max_ymodul6;
 current_xmodul7_pos = max_xmodul7;
 current_ymodul8_pos = max_ymodul8;
 current_xhlava9_pos = max_xhlava9;

}



void MIN_POS()
{
  move(xzadek1, min_xzadek1);
  move(ymodul2, min_ymodul2);
  move(xmodul3, min_xmodul3);
  move(ymodul4, min_ymodul4);
  move(xmodul5, min_xmodul5);
  move(ymodul6, min_ymodul6);
  move(xmodul7, min_xmodul7);
  move(ymodul8, min_ymodul8);
  move(xhlava9, min_xhlava9);

 current_xzadek1_pos = min_xzadek1;
 current_ymodul2_pos = min_ymodul2;
 current_xmodul3_pos = min_xmodul3;
 current_ymodul4_pos = min_ymodul4;
 current_xmodul5_pos = min_xmodul5;
 current_ymodul6_pos = min_ymodul6;
 current_xmodul7_pos = min_xmodul7;
 current_ymodul8_pos = max_ymodul8;
 current_xhlava9_pos = min_xhlava9;

}


void USOFT_POS()
{
  move(xzadek1, usoft_xzadek1);
  move(ymodul2, usoft_ymodul2);
  move(xmodul3, usoft_xmodul3);
  move(ymodul4, usoft_ymodul4);
  move(xmodul5, usoft_xmodul5);
  move(ymodul6, usoft_ymodul6);
  move(xmodul7, usoft_xmodul7);
  move(ymodul8, usoft_ymodul8);
  move(xhlava9, usoft_xhlava9);

 current_xzadek1_pos = usoft_xzadek1;
 current_ymodul2_pos = usoft_xmodul3;
 current_ymodul4_pos = usoft_ymodul4;
 current_xmodul5_pos = usoft_xmodul5;
 current_ymodul6_pos = usoft_ymodul6;
 current_xmodul7_pos = usoft_xmodul7;
 current_ymodul8_pos = usoft_ymodul8;
 current_xhlava9_pos = usoft_xhlava9;
}

void UHARD_POS()
{
  move(xzadek1, uhard_xzadek1);
  move(ymodul2, uhard_ymodul2);
  move(xmodul3, uhard_xmodul3);
  move(ymodul4, uhard_ymodul4);
  move(xmodul5, uhard_xmodul5);
  move(ymodul6, uhard_ymodul6);
  move(xmodul7, uhard_xmodul7);
  move(ymodul8, uhard_ymodul8);
  move(xhlava9, uhard_xhlava9);

 current_xzadek1_pos = uhard_xzadek1;
 current_ymodul2_pos = uhard_ymodul2;
  current_xmodul3_pos = uhard_xmodul3;
 current_ymodul4_pos = uhard_ymodul4;
 current_xmodul5_pos = uhard_xmodul5;
 current_ymodul6_pos = uhard_ymodul6;
 current_xmodul7_pos = uhard_xmodul7;
 current_ymodul8_pos = uhard_ymodul8;
 current_xhlava9_pos = uhard_xhlava9;
}

void SLIDE_UHARD_POS_XHLAVA9()
{
  move(xzadek1, uhard_xzadek1);
  move(ymodul2, uhard_ymodul2);
  move(xmodul3, uhard_xmodul3);
  move(ymodul4, uhard_ymodul4);
  move(xmodul5, uhard_xmodul5);
  move(ymodul6, uhard_ymodul6);
  move(xmodul7, uhard_xmodul7);
  move(ymodul8, uhard_ymodul8);
  move(xhlava9, slide_uhard_xhlava9);

 current_xzadek1_pos = uhard_xzadek1;
 current_ymodul2_pos = uhard_ymodul2;
  current_xmodul3_pos = uhard_xmodul3;
 current_ymodul4_pos = uhard_ymodul4;
 current_xmodul5_pos = uhard_xmodul5;
 current_ymodul6_pos = uhard_ymodul6;
 current_xmodul7_pos = uhard_xmodul7;
 current_ymodul8_pos = uhard_ymodul8;
 current_xhlava9_pos = slide_uhard_xhlava9;
}
void SLIDE_UHARD_POS_XZADEK1()
{
  move(xzadek1, slide_uhard_xzadek1);
  move(ymodul2, uhard_ymodul2);
  move(xmodul3, uhard_xmodul3);
  move(ymodul4, uhard_ymodul4);
  move(xmodul5, uhard_xmodul5);
  move(ymodul6, uhard_ymodul6);
  move(xmodul7, uhard_xmodul7);
  move(ymodul8, uhard_ymodul8);
  move(xhlava9, uhard_xhlava9);

 current_xzadek1_pos = slide_uhard_xzadek1;
 current_ymodul2_pos = uhard_ymodul2;
 current_xmodul3_pos = uhard_xmodul3;
 current_ymodul4_pos = uhard_ymodul4;
 current_xmodul5_pos = uhard_xmodul5;
 current_ymodul6_pos = uhard_ymodul6;
 current_xmodul7_pos = uhard_xmodul7;
 current_ymodul8_pos = uhard_ymodul8;
 current_xhlava9_pos = uhard_xhlava9;
}

void SLIDE_MID_POS_XHLAVA9()
{
  move(xzadek1, mid_xzadek1);
  move(ymodul2, mid_ymodul2);
  move(xmodul3, mid_xmodul3);
  move(ymodul4, mid_ymodul4);
  move(xmodul5, mid_xmodul5);
  move(ymodul6, mid_ymodul6);
  move(xmodul7, mid_xmodul7);
  move(ymodul8, mid_ymodul8);
  move(xhlava9, slide_mid_xhlava9);

 current_xzadek1_pos = mid_xzadek1;
 current_ymodul2_pos = mid_ymodul2;
 current_xmodul3_pos = mid_xmodul3;
 current_ymodul4_pos = mid_ymodul4;
 current_xmodul5_pos = mid_xmodul5;
 current_ymodul6_pos = mid_ymodul6;
 current_xmodul7_pos = mid_xmodul7;
 current_ymodul8_pos = mid_ymodul8;
 current_xhlava9_pos = slide_mid_xhlava9;
}

void SLIDE_MID_POS_XZADEK1()
{
  move(xzadek1, slide_mid_xzadek1);
  move(ymodul2, mid_ymodul2);
  move(xmodul3, mid_xmodul3);
  move(ymodul4, mid_ymodul4);
  move(xmodul5, mid_xmodul5);
  move(ymodul6, mid_ymodul6);
  move(xmodul7, mid_xmodul7);
  move(ymodul8, mid_ymodul8);
  move(xhlava9, mid_xhlava9);

 current_xzadek1_pos = slide_mid_xzadek1;
 current_ymodul2_pos = mid_ymodul2;
 current_xmodul3_pos = mid_xmodul3;
 current_ymodul4_pos = mid_ymodul4;
 current_xmodul5_pos = mid_xmodul5;
 current_ymodul6_pos = mid_ymodul6;
 current_xmodul7_pos = mid_xmodul7;
 current_ymodul8_pos = mid_ymodul8;
 current_xhlava9_pos = mid_xhlava9;
}
void TO_UHARD_SLIDE_XZADEK1()
{
  int steps = 50; // Jemnější přechod
  float step_xzadek1 = (slide_uhard_xzadek1 - mid_xzadek1) / (float)steps;
  float step_ymodul2 = (uhard_ymodul2 - mid_ymodul2) / (float)steps;
  float step_xmodul3 = (uhard_xmodul3 - mid_xmodul3) / (float)steps;
  float step_ymodul4 = (uhard_ymodul4 - mid_ymodul4) / (float)steps;
  float step_xmodul5 = (uhard_xmodul5 - mid_xmodul5) / (float)steps;
  float step_ymodul6 = (uhard_ymodul6 - mid_ymodul6) / (float)steps;
  float step_xmodul7 = (uhard_xmodul7 - mid_xmodul7) / (float)steps;
  float step_ymodul8 = (uhard_ymodul8 - mid_ymodul8) / (float)steps;
  float step_xhlava9 = (uhard_xhlava9 - mid_xhlava9) / (float)steps;

  for (int i = 0; i <= steps; i++)
  {
      float interpolated_xzadek1 = slide_mid_xzadek1 + (i * step_xzadek1);
    
    // Dynamická korekce úhlu pro udržení sklonu 15°
    float correction_angle = 10 * (0.2 - (float)i / steps);
    float corrected_xzadek1 = interpolated_xzadek1 + correction_angle;


    // Posun zadku od relaxace do SLIDE pozice s korekcí úhlu
    move(xzadek1, corrected_xzadek1);
    delay(SERVO_DELAY);  // Pauza po pohybu zadku

    

    move(xmodul3, mid_xmodul3 + (i * step_xmodul3));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 3

    

    move(xmodul5, mid_xmodul5 + (i * step_xmodul5));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 2

   

    move(xmodul7, mid_xmodul7 + (i * step_xmodul7));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 4

    

    move(xhlava9, mid_xhlava9 + (i * step_xhlava9));
    delay(SERVO_DELAY);
  }

  // Aktualizujeme pozice pro další cyklus
  current_xzadek1_pos = slide_uhard_xzadek1;
  current_ymodul2_pos = uhard_ymodul2;
current_xmodul3_pos = uhard_xmodul3;
 current_ymodul4_pos = uhard_ymodul4;
 current_xmodul5_pos = uhard_xmodul5;
 current_ymodul6_pos = uhard_ymodul6;
 current_xmodul7_pos = uhard_xmodul7;
 current_ymodul8_pos = uhard_ymodul8;
 current_xhlava9_pos = uhard_xhlava9;
}


void TO_MID_SLIDE_XHLAVA9()
{
  int steps = 50; // Jemnější přechod
  float step_xzadek1 = (mid_xzadek1 - uhard_xzadek1) / (float)steps;
  float step_ymodul2 = (mid_ymodul2 - uhard_ymodul2) / (float)steps;
  float step_xmodul3 = (mid_xmodul3 - uhard_xmodul3) / (float)steps;
  float step_ymodul4 = (mid_ymodul4 - uhard_ymodul4) / (float)steps;
  float step_xmodul5 = (mid_xmodul5 - uhard_xmodul5) / (float)steps;
  float step_ymodul6 = (mid_ymodul6 - uhard_ymodul6) / (float)steps;
  float step_xmodul7 = (mid_xmodul7 - uhard_xmodul7) / (float)steps;
  float step_ymodul8 = (mid_ymodul8 - uhard_ymodul8) / (float)steps;
  float step_xhlava9 = (slide_mid_xhlava9 - slide_uhard_xhlava9) / (float)steps;

  for (int i = 0; i <= steps; i++)
  {
      float interpolated_xhlava9 = slide_uhard_xhlava9 + (i * step_xhlava9);
    
    // Dynamická korekce úhlu pro udržení sklonu 15°
    float correction_angle = 15.0 * (1.0 - (float)i / steps);
    float corrected_xhlava9 = interpolated_xhlava9 + correction_angle;


    // Posun zadku od relaxace do SLIDE pozice s korekcí úhlu
    move(xzadek1, uhard_xzadek1 + (i * step_xzadek1));
    delay(SERVO_DELAY);  // Pauza po pohybu zadku

    

    move(xmodul3, uhard_xmodul3 + (i * step_xmodul3));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 3

    

    move(xmodul5, mid_xmodul5 + (i * step_xmodul5));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 2

   

    move(xmodul7, mid_xmodul7 + (i * step_xmodul7));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 4

    

    move(xhlava9, corrected_xhlava9);
    delay(SERVO_DELAY);
  }

  current_xzadek1_pos = mid_xzadek1;
 current_ymodul2_pos = mid_ymodul2;
 current_xmodul3_pos = mid_xmodul3;
 current_ymodul4_pos = mid_ymodul4;
 current_xmodul5_pos = mid_xmodul5;
 current_ymodul6_pos = mid_ymodul6;
 current_xmodul7_pos = mid_xmodul7;
 current_ymodul8_pos = mid_ymodul8;
 current_xhlava9_pos = slide_mid_xhlava9;
}



void setup()  {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);

  delay(COSMETIC_DELAY);
MID_POS();
delay(COSMETIC_DELAY);
UHARD_POS();
 
  
  /*delay(COSMETIC_DELAY);
  MAX_POS();
 delay(COSMETIC_DELAY);
 RELAX_POS();
 delay(COSMETIC_DELAY);
 MIN_POS();
 delay(COSMETIC_DELAY);
 RELAX_POS();*/
}



  void loop() {
  
  
}
