//#include <Wire.h>
//#include "MMA7660.h"
//MMA7660 accelerometer;

#define SERVO1 10
#define SERVO2 9

#include <Servo.h>

Servo servo1;
Servo servo2;

char in[6];
int ang = 0;

int xAng = 125;
int yAng = 35;

void setup()
{
  //accelerometer.init();  
  Serial.begin(9600);

  servo1.attach(SERVO1);
  servo2.attach(SERVO2);

  servo1.write(xAng);
  servo2.write(yAng);
}
void loop()
{
  if (Serial.available() > 0){

  Serial.readBytes(in, 5);
  Serial.print("Com. recebido: ");
  Serial.println(in);
  
  int i = 0;
  while(*(in + i) != '\n'){

    if(*(in + i) == 'l'){
      i++;
      
      ang = atoi(in + i);
      
      servo1.write(xAng + ang);
      servo2.write(yAng - ang);

      Serial.print("Servo 1: ");
      Serial.print(xAng + ang);

      Serial.print(" | Servo 2: ");
      Serial.println(yAng - ang);
      
      break;
    }else if(*(in + i) == 'x'){
      i++;
      
      ang = atoi(in + i);
      
      servo1.write(ang);

      Serial.print("Servo 1: ");
      Serial.println(ang);
      
      break;
    }else if(*(in + i) == 'y'){
      i++;
      
      ang = atoi(in + i);
      
      servo2.write(ang);

      Serial.print("Servo 2: ");
      Serial.println(ang);
      
      break;
    }
    
    i++;
  }
  
  }
}
