#include <VarSpeedServo.h>

VarSpeedServo servoblau;
int d = 3000;
int schalter=3;
int servo=8;
int tasterstatus = 0;
int min_random = 0;
int max_random = 4;
int random_num = 0;
const int delay_time = 200;
const int delay_time_short = 50;
const int delay_time_long = 1500;
const int closed_position = 8;

void setup() {
  servoblau.attach(servo);
  pinMode(schalter, INPUT);
}

void behaviour_1() {
  servoblau.write(closed_position,40,true);    
  delay(delay_time);
  servoblau.write(100,40,true);
  delay(delay_time);  
  servoblau.write(closed_position,40,true);
}

void behaviour_2() {
  servoblau.write(closed_position,40,true);    
  delay(delay_time);
  servoblau.write(30,10,true);
  delay(delay_time_short);  
  servoblau.write(100,70,true);
  delay(delay_time);
  servoblau.write(closed_position,70,true);
}

void behaviour_3() {
  servoblau.write(closed_position,40,true);    
  delay(delay_time);
  servoblau.write(50,50,true);
  delay(delay_time_short);  
  servoblau.write(8,50,true);
  delay(delay_time);  
  servoblau.write(40,50,true);
  delay(delay_time_short);  
  servoblau.write(15,50,true);
  delay(delay_time);  
  servoblau.write(100,100,true);
  delay(delay_time);
  servoblau.write(closed_position,70,true);
}

void behaviour_4() {
  servoblau.write(closed_position,40,true);    
  delay(delay_time);
  servoblau.write(70,5,true);
  delay(delay_time_long);  
  servoblau.write(100,70,true);
  delay(delay_time_short);
  servoblau.write(closed_position,100,true);
}

void loop() {
  tasterstatus=digitalRead(schalter);
  
  if(tasterstatus==LOW){
    random_num = random(min_random, max_random);
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
    }
  }  
}
