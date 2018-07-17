#include <Servo.h>

Servo servo1;
int stat = 0;
int servostat;

void countup(){
  digitalWrite(8, 0);
  digitalWrite(7, 1);
  for (int i=0; i<=180; i++){
    servo1.write(i);
    stat=1;
    delay(3);
    servostat = i;
  }
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  delay(10);
}
void countdown(){
  digitalWrite(9, 0);
  digitalWrite(7, 1);
  for (int i=180; i>=0; i--){
    servo1.write(i);
    stat=0;
    servostat = i;
    delay(3);
  }  
  digitalWrite(7, 0);
  delay(10);
}

void setLED(int stat){
  digitalWrite(9, stat);
  digitalWrite(8, !stat);
}

void setservo(int s){
  switch(s){
    case 1 : countup();stat=1;setLED(stat);break;
    case 0 : countdown();stat=0;setLED(stat);break;
    default: break;
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  servo1.attach(10);
  servo1.write(0);
}

void loop() {
if (digitalRead(2)){
  stat = !stat;
  delay(20);
  setservo(stat);
  delay(50);
}
 Serial.print(stat);
 Serial.print(", ");
 Serial.print(servostat);
 Serial.print(", ");
 Serial.println(digitalRead(2));
}
