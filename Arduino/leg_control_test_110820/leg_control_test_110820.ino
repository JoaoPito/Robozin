/*Teste de controle das pernas (11/08/20)
Por enquanto so sera calculado o servo X*/

#include <Servo.h>

float x = 5.6f;//Distancia servo Y ao X
float y = 7.6f;//Dist servo X ao pe

float z = 5.0f;//Distancia servo Y ao pe(Dist. requerida)

Servo servoX;
Servo servoY;

int servoY_pin = 9;
int servoX_pin = 5;

int servoX_ang = 0;
int servoY_ang = 0;

void setup(){
  
  Serial.begin(9600);
  
  servoX.attach(servoX_pin,550,2550);
  servoY.attach(servoY_pin,550,2550);
  
  //servoX.write(0);
  //servoY.write(0);
  
  //delay(1000);
  
}

void loop(){ 
  
  servoX_ang = calcAngle(z,x,y);

  Serial.print("X: ");
  Serial.print(servoX_ang);
  servoX.write(servoX_ang);

  servoY_ang = calcAngle(y,x,z);/*Esses 90 graus são so para o servo ficar na horizontal
  no futuro sera calculado o angulo em funçao da posicao do pe*/
  
  Serial.print(" Y: ");
  Serial.println(servoY_ang);
  servoY.write(servoY_ang);
  
  delay(10000);
  //z += 0.5f;
}

int calcAngle(float a, float b, float c){

  if(a == 0 || b==0) {
    return 90;//Para evitar div. por 0, retorna 0 mas pode ser qlqr outro numero
    Serial.println("calcAngle: div by 0!");
  }
  
  int ret = 0; 
  float cosAng = -pow(a,2) + pow(b,2) + pow(c,2);
  cosAng = cosAng/(2*b*c);
  
  float rad = acos(cosAng);
  float deg = rad * 57296 / 1000;  
  
  ret = round(deg);
  /*DEBUG
  Serial.print("calcAngle: cosAng ");
  Serial.print(cosAng);
  Serial.print(" rad ");
  Serial.print(rad);
  Serial.print(" deg ");
  Serial.print(deg);
  Serial.print(" ret ");
  Serial.println(ret);*/
  
  return 180 - ret;
}
