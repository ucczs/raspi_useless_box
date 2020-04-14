#include <VarSpeedServo.h>

VarSpeedServo servoblau;
int d = 3000;
int schalter=3;
int servo=8;
int tasterstatus = 0;

void setup() {
  servoblau.attach(servo);
  pinMode(schalter, INPUT);
}

void loop() {
  tasterstatus=digitalRead(schalter);
  
  if(tasterstatus==LOW){
    servoblau.write(5,40,true);    
    delay(300);
    servoblau.write(100,40,true);
    delay(300);  
    servoblau.write(5,40,true);
  }  
}
