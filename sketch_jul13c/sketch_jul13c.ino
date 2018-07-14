
void setup() {
  // put your setup code here, to run once:
  
  pinMode(12,OUTPUT); //A Motor Dir
  pinMode(9,OUTPUT); //A Brake
  analogWrite(3,0); //A speed
  
  pinMode(13,OUTPUT); //B Motor Dir
  pinMode(8,OUTPUT); //B Brake
  analogWrite(11,0); //B speed
  

  Serial.begin(9600); //baud rate
  Serial.println("Ready to go!");

 
  }
int realspeed = 100;
void loop() {
  // put your main code here, to run repeatedly:
 
  if(Serial.available()){
    
     char key = Serial.read();
     Serial.println(key);
     Serial.println(realspeed);
     if(key=='w'){
       moveA(realspeed,false);
       moveB(realspeed,true);//they are different because the motors are flipped so if they were the same it would turn
      } 
     else if(key =='a'){
      moveA(realspeed,false);
      moveB(realspeed,false);
      }
     else if(key =='d'){
      moveB(realspeed,true);
      moveA(realspeed,true);      
      }
     else if(key == 's'){
      moveA(realspeed,true);
      moveB(realspeed,false);
      }
     else if(key == 'k'){
      moveA(0,true);
      moveB(0,false);
      
    } else if(key == 'o') {
      if(realspeed <= 235) realspeed += 20;
    } else if(key == 'p') {
      if(realspeed >= 80){
        realspeed -= 20;
      }
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


