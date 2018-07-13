#include <Servo.h>;

Servo clawL;
Servo clawR;
int pos =0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(12,OUTPUT); //A Motor Dir
  pinMode(9,OUTPUT); //A Brake
  analogWrite(3,0); //A speed
  
  pinMode(13,OUTPUT); //B Motor Dir
  pinMode(8,OUTPUT); //B Brake
  analogWrite(11,0); //B speed

  clawL.attach(7);
  clawR.attach(5); //this is the pin that is being used
  clawL.write(0);
  clawR.write(0);
  

  Serial.begin(9600); //bit rate
  Serial.println("Ready to go!");
  }

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
    char key = Serial.read();
    Serial.println(key); 

    if(key=='w'){
      moveA(200,false);
      moveB(200,true);//they are different because the motors are flipped so if they were the same it would turn
    } 
    else if(key =='a'){
      moveA(200,false);
      moveB(200,false);
    }
    else if(key =='d'){
      moveB(200,true);
      moveA(200,true);      
    }
    else if(key == 's'){
      moveA(200,true);
      moveB(200,false);
    }
    else if(key == 'k'){
      moveA(0,true);
      moveB(0,false);
    }
    else if(key=='i'){
      clawL.write(160); //this is a value from 0-180 the angel of rotation
      clawR.write(0); //this is a value from 0-180 the angel of rotation
    }
    else if(key=='j'){
      clawL.write(120); //this is a value from 0-180 the angel of rotation
      clawR.write(10);
    }
  }
}

void moveA(int speed, boolean dir) {
  if(dir ==true){
    digitalWrite(12,LOW);
  }else{
    digitalWrite(12,HIGH);
  }

  digitalWrite(9,LOW);
  analogWrite(3,speed);  
}

void moveB(int speed, boolean dir) {
  if(dir ==true){
    digitalWrite(13,LOW);
  }else{
    digitalWrite(13,HIGH);
  }

  digitalWrite(8,LOW);
  analogWrite(11,speed);  
}

