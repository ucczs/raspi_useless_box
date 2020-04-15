#include <VarSpeedServo.h>

VarSpeedServo servoblau;
int d = 3000;
int schalter=3;
int servo=8;
int tasterstatus = 0;
int random_num = 0;

int rand_min = 0;
int rand_max = 6;

const int DELAY = 200;
const int DELAY_SHORT = 50;
const int DELAY_LONG = 1500;

const int POS_CLOSED = 8;
const int POS_SWITCH = 100;

void setup() {
  servoblau.attach(servo);
  pinMode(schalter, INPUT);
}

void behaviour_1() {
  servoblau.write(POS_CLOSED,40,true);    
  delay(DELAY);
  servoblau.write(POS_SWITCH,40,true);
  delay(DELAY);  
  servoblau.write(POS_CLOSED,40,true);
}

void behaviour_2() {
  servoblau.write(POS_CLOSED,40,true);    
  delay(DELAY);
  servoblau.write(30,10,true);
  delay(DELAY_SHORT);  
  servoblau.write(POS_SWITCH,70,true);
  delay(DELAY);
  servoblau.write(POS_CLOSED,70,true);
}

void behaviour_3() {
  servoblau.write(POS_CLOSED,40,true);    
  delay(DELAY);
  servoblau.write(85,50,true);
  delay(DELAY_LONG);  
  servoblau.write(60,20,true);
  delay(DELAY_LONG);  
  servoblau.write(POS_SWITCH,20,true);
  delay(DELAY_SHORT);  
  servoblau.write(POS_CLOSED,20,true);
}

void behaviour_4() {
  servoblau.write(POS_CLOSED,40,true);    
  delay(DELAY);
  servoblau.write(70,5,true);
  delay(DELAY_LONG);  
  servoblau.write(POS_SWITCH,100,true);
  delay(DELAY_SHORT);
  servoblau.write(POS_CLOSED,100,true);
}

void behaviour_5() {
  servoblau.write(POS_CLOSED,70,true);
  servoblau.write(POS_SWITCH,150,true);
  delay(DELAY);  
  servoblau.write(POS_CLOSED,150,true);
}

void behaviour_6() {
  delay(DELAY_LONG);
  delay(DELAY_LONG);
  servoblau.write(POS_CLOSED,70,true);
  servoblau.write(POS_SWITCH,150,true);
  delay(DELAY);  
  servoblau.write(POS_CLOSED,150,true);
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
