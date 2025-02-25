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



#define maxu_zadek1 315
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
#define SERVO_DELAY 5

#define SLOW_SERVO_DELAY 10  // Delší pauza mezi mezikroky
#define EXTRA_DELAY 50    

long angleToPulse(uint16_t angle)
{
  return map(angle, 0, 360, SERVOMIN, SERVOMAX);
}

void move(uint8_t part, uint16_t pos)
{
  pwm.setPWM(part, 0, angleToPulse(pos));
}



 // Pauza mezi pohybem každého serva



  // Aktualizujeme pozice pro další cyklus
 

void TRANSITION_SLIDE_HLAVA_TO_RELAX()
{
  int steps = 50; // Jemnější přechod
  float step_zadek1 = (mid_zadek1 - maxu_zadek1) / (float)steps;
  float step_modul2 = (mid_modul2 - maxu_modul2) / (float)steps;
  float step_modul3 = (mid_modul3 - maxu_modul3) / (float)steps;
  float step_modul4 = (mid_modul4 - maxu_modul4) / (float)steps;
  float step_hlava5 = (relax_slide_hlava5 - maxu_slide_hlava5) / (float)steps;

  for (int i = 0; i <= steps; i++)
  {
    float interpolated_hlava5 = maxu_slide_hlava5 + (i * step_hlava5);
    
    // Dynamická korekce úhlu pro udržení sklonu 15°
    float correction_angle = 15.0 * (1.0 - (float)i / steps);
    float corrected_hlava5 = interpolated_hlava5 + correction_angle;

    move(zadek1, maxu_zadek1 + (i * step_zadek1));
    delay(SLOW_SERVO_DELAY);  // Pauza po pohybu zadku

    move(modul2, maxu_modul2 + (i * step_modul2));
    delay(SLOW_SERVO_DELAY);  // Pauza po pohybu modulu 2

    move(modul3, maxu_modul3 + (i * step_modul3));
    delay(SLOW_SERVO_DELAY);  // Pauza po pohybu modulu 3

    move(modul4, maxu_modul4 + (i * step_modul4));
    delay(SLOW_SERVO_DELAY);  // Pauza po pohybu modulu 4

    move(hlava5, corrected_hlava5);
    delay(SLOW_SERVO_DELAY); // Celková pauza mezi cykly
  }

  current_zadek1_pos = mid_zadek1;
  current_modul2_pos = mid_modul2;
  current_modul3_pos = mid_modul3;
  current_modul4_pos = mid_modul4;
  current_hlava5_pos = relax_slide_hlava5;
}


void TRANSITION_RELAX_TO_SLIDE_ZADEK()
{
  int steps = 50; // Jemnější přechod
  float step_zadek1 = (maxu_slide_zadek1 - relax_slide_zadek1) / (float)steps;
  float step_modul2 = (maxu_modul2 - mid_modul2) / (float)steps;
  float step_modul3 = (maxu_modul3 - mid_modul3) / (float)steps;
  float step_modul4 = (maxu_modul4 - mid_modul4) / (float)steps;
  float step_hlava5 = (maxu_hlava5 - mid_hlava5) / (float)steps;

  for (int i = 0; i <= steps; i++)
  {
      float interpolated_zadek1 = relax_slide_zadek1 + (i * step_zadek1);
    
    // Dynamická korekce úhlu pro udržení sklonu 15°
    float correction_angle = 10.0 * (0.5 - (float)i / steps);
    float corrected_zadek1 = interpolated_zadek1 + correction_angle;


    // Posun zadku od relaxace do SLIDE pozice s korekcí úhlu
    move(zadek1, corrected_zadek1);
    delay(SERVO_DELAY);  // Pauza po pohybu zadku

    move(modul2, mid_modul2 + (i * step_modul2));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 2

    move(modul3, mid_modul3 + (i * step_modul3));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 3

    move(modul4, mid_modul4 + (i * step_modul4));
    delay(SERVO_DELAY);  // Pauza po pohybu modulu 4

    move(hlava5, mid_hlava5 + (i * step_hlava5));
    delay(SERVO_DELAY);
  }

  // Aktualizujeme pozice pro další cyklus
  current_zadek1_pos = maxu_slide_zadek1;
  current_modul2_pos = maxu_modul2;
  current_modul3_pos = maxu_modul3;
  current_modul4_pos = maxu_modul4;
  current_hlava5_pos = maxu_hlava5;
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

void MOVE_TO_MAXU_SMOOTH(bool isHead) {
  uint16_t startPos, targetPos, relaxPos;
  
  if (isHead) {
    startPos = relax_slide_hlava5;  // Hlava v uvolněné klouzací pozici
    targetPos = maxu_hlava5;  // Hlava v maximální poloze
    relaxPos = mid_hlava5;   // Středová (relax) pozice
  } else {
    startPos = relax_slide_zadek1;  // Zadek v uvolněné klouzací pozici
    targetPos = maxu_zadek1;  // Zadek v maximální poloze
    relaxPos = mid_zadek1;   // Středová (relax) pozice
  }

  // Krok 1: Mírně nadzvedni část těla, aby se uvolnil brusný papír
  uint16_t liftPos = startPos + 20;  // Malé nadzvednutí
  move(isHead ? hlava5 : zadek1, liftPos);
  delay(SERVO_DELAY);

  // Krok 2: Postupně posouvej modul směrem k maxu 
  for (uint16_t pos = liftPos; pos <= targetPos; pos += 5) {
    move(isHead ? hlava5 : zadek1, pos);
    delay(SERVO_DELAY);
  }
}

void setup()  {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

  delay(COSMETIC_DELAY);
  RELAX_POS();
  TRANSITION_SLIDE_HLAVA_TO_RELAX();
  delay(COSMETIC_DELAY);
  TRANSITION_RELAX_TO_SLIDE_ZADEK();
  
 
}



  void loop() {
  TRANSITION_SLIDE_HLAVA_TO_RELAX();
  
  TRANSITION_RELAX_TO_SLIDE_ZADEK();
  

}
