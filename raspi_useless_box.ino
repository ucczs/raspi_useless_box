#include <VarSpeedServo.h>

VarSpeedServo servoblau;
int d = 3000;
int schalter=3;
int servo=8;
int tasterstatus = 0;
int random_num = 0;

int rand_min = 0;
int rand_max = 6;

const bool WAIT_TO_FINISH = true;

const int DELAY = 200;
const int DELAY_SHORT = 50;
const int DELAY_LONG = 1500;

const int POS_CLOSED = 8;
const int POS_SWITCH = 100;

const int SPEED_MAX = 70;
const int SPEED_MEDIUM = 50;
const int SPEED_SLOW = 20;
const int SPEED_SUPER_SLOW = 5;

void setup() {
  servoblau.attach(servo);
  pinMode(schalter, INPUT);
}

void behaviour_1() {
  servoblau.write(POS_CLOSED,   SPEED_MEDIUM,       WAIT_TO_FINISH);    
  delay(DELAY);
  servoblau.write(POS_SWITCH,   SPEED_MEDIUM,       WAIT_TO_FINISH);
  delay(DELAY);  
  servoblau.write(POS_CLOSED,   SPEED_MEDIUM,       WAIT_TO_FINISH);
}

void behaviour_2() {
  servoblau.write(POS_CLOSED,   SPEED_MEDIUM,       WAIT_TO_FINISH);    
  delay(DELAY); 
  servoblau.write(30,           SPEED_SUPER_SLOW,   WAIT_TO_FINISH);
  delay(DELAY_SHORT);  
  servoblau.write(POS_SWITCH,   SPEED_MAX,          WAIT_TO_FINISH);
  delay(DELAY);
  servoblau.write(POS_CLOSED,   SPEED_MAX,          WAIT_TO_FINISH);
}

void behaviour_3() {
  servoblau.write(POS_CLOSED,   SPEED_MEDIUM,      WAIT_TO_FINISH);    
  delay(DELAY);
  servoblau.write(75,           SPEED_MEDIUM,       WAIT_TO_FINISH);
  delay(DELAY_LONG);  
  servoblau.write(60,           SPEED_SLOW,         WAIT_TO_FINISH);
  delay(DELAY_LONG);  
  servoblau.write(POS_SWITCH,   SPEED_SLOW,         WAIT_TO_FINISH);
  delay(DELAY_SHORT);  
  servoblau.write(POS_CLOSED,   SPEED_SLOW,         WAIT_TO_FINISH);
}

void behaviour_4() {
  servoblau.write(POS_CLOSED,   SPEED_MEDIUM,       WAIT_TO_FINISH);    
  delay(DELAY);
  servoblau.write(70,           SPEED_SUPER_SLOW,   WAIT_TO_FINISH);
  delay(DELAY_LONG);  
  servoblau.write(POS_SWITCH,   SPEED_MAX,          WAIT_TO_FINISH);
  delay(DELAY_SHORT);
  servoblau.write(POS_CLOSED,   SPEED_MAX,          WAIT_TO_FINISH);
}

void behaviour_5() {
  servoblau.write(POS_CLOSED,   SPEED_MAX,          WAIT_TO_FINISH);
  servoblau.write(POS_SWITCH,   SPEED_MAX,          WAIT_TO_FINISH);
  delay(DELAY);  
  servoblau.write(POS_CLOSED,   SPEED_MAX,          WAIT_TO_FINISH);
}

void behaviour_6() {
  delay(DELAY_LONG);
  delay(DELAY_LONG);
  servoblau.write(POS_CLOSED,   SPEED_MAX,  WAIT_TO_FINISH);
  servoblau.write(POS_SWITCH,   SPEED_MAX,  WAIT_TO_FINISH);
  delay(DELAY);  
  servoblau.write(POS_CLOSED,   SPEED_MAX,  WAIT_TO_FINISH);
}


void loop() {
  tasterstatus=digitalRead(schalter);
  
  if(tasterstatus==LOW){
    random_num = random(rand_min, rand_max);
    switch (random_num) {
      case 0:
        behaviour_1();
        break;
      case 1:
        behaviour_2();
        break;
      case 2:
        behaviour_3();
        break;
      case 3:
        behaviour_4();
        break;
      case 4:
        behaviour_5();
        break;
      case 5:
        behaviour_6();
        break;
    }
  }  
}
