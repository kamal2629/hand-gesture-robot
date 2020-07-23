#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); 

char tiltDirection;
int motorInput1 = 2;
int motorInput2 = 3;
int motorInput3 = 4;
int motorInput4 = 5;

void setup() {

  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

  Serial.begin(9600);      
  BTSerial.begin(9600);    
}

void loop() {
  if (BTSerial.available()) {  
    tiltDirection = BTSerial.read();
    if(tiltDirection == 'F'){
      Serial.println("Backword");
      reverse();
    }else if(tiltDirection == 'B'){
      Serial.println("Forward");
      forward();
    }else if(tiltDirection == 'R'){
      Serial.println("Left");
      left();
    }else if(tiltDirection == 'L'){
      Serial.println("Right");
      right();
    }else if(tiltDirection == 'S'){
      Serial.println("Stop");
    }
      stopCar();
    }
  }

void forward()
{
  
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void reverse()
{
  
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
  delay(10);
}
void right()
{
  
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
  delay(10);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
  delay(10);
  
}
void left()
{
  
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
  delay(10);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
  delay(10);
}

void stopCar() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
  delay(10);
}
