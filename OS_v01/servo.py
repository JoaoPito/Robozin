import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

class Servo:

  def __init__(self, pin, minPWM=2, maxPWM=12, minAng=0, maxAng=180, startPos=0):
    super().__init__()
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
    time.sleep(0.2)
    self.s.ChangeDutyCycle(0)
