#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int endAng = 180;
int startAng = 0;

void setup()
{
  accelemeter.init();  
  Serial.begin(9600);

  servo1.attach(9);
  servo2.attach(10);
}
void loop()
{
  int8_t x;
  int8_t y;
  int8_t z;
  float ax,ay,az;
  accelemeter.getXYZ(&x,&y,&z);
  
  Serial.print("x= ");
    Serial.print(x); 
    Serial.print(" | y= ");
    Serial.print(y);   
    Serial.print(" | z= ");    
    Serial.println(z);

    if(z<0) Serial.println("ponta-cabeca");
    if(x>5) Serial.println("de frente");
    if(x<-5) Serial.println("de tras");
    if(y>5) Serial.println("direita");
    if(y<-5) Serial.println("esquerda");
  
  //accelemeter.getAcceleration(&ax,&ay,&az);
    //Serial.println("accleration of X/Y/Z: ");
  /*Serial.print(ax);
  Serial.print(" g | ");
  Serial.print(ay);
  Serial.print(" g | ");
  Serial.print(az);
  Serial.println(" g");
  Serial.println("*************");*/
  delay(300);

 // for (pos = startAng; pos <= endAng; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //servo1.write(pos);
    //servo2.write(pos); // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
 // }
  //for (pos = endAng; pos >= startAng; pos -= 1) { // goes from 180 degrees to 0 degrees
    //servo1.write(pos);  
    //servo2.write(pos); // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  //}
}
