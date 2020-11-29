import RPi.GPIO as GPIO
import time

class Servo:

  def __init__(self, pin, minPWM=2, maxPWM=12, minAng=0, maxAng=180, startPos=0):
    super().__init__(pin)
    self.minPWM = minPWM
    self.maxPWM = maxPWM

    self.minAng = minAng
    self.maxAng = maxAng    

    self.pin = pin
    GPIO.setup(pin, GPIO.OUT)
    self.s = GPIO.PWM(pin, 50)#50Hz

    self.pos = startPos
    self.s.start(self.calcDutyCycle(startPos))

#Calculates the duty cycle given an angle, its used for calculations during init and write
  def calcDutyCycle(self,angle):
    if(angle>self.maxAng):
      a = 1
    else:
      a = angle/self.maxAng

    pwm = self.maxPWM - self.minPWM
    ret = pwm*a + self.minPWM
    return ret

#Writes an angle to the servo
  def write(self,angle):
    d = self.calcDutyCycle(angle)
    self.s.ChangeDutyCycle(d)

GPIO.setmode(GPIO.BCM)
servo1 = Servo(17)

try:
  while True:
    servo1.write(0)
    time.sleep(1)
    servo1.write(45)
    time.sleep(1)
    servo1.write(90)
    time.sleep(1)
    servo1.write(180)
    time.sleep(1.5)


except KeyboardInterrupt:
  #p.stop()
  GPIO.cleanup()

