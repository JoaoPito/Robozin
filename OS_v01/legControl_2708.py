from servo import Servo
import math
import time



servoX_pin = 17
servoY_pin = 18

servoX = Servo(servoX_pin)
servoY = Servo(servoY_pin)

def calcAngle(a, b, c):

    if(a == 0 or b == 0):
        print("calcAngle: division by 0!")
        return 90

    cosAng = -(a**2) + (b**2) + (c**2)
    cosAng = cosAng/(2*b*c)

    rad = math.acos(cosAng)
    deg = rad * 57296 / 1000

    r = round(deg)
    return 180 - r

def start():
    return

def main():

    x = 5.6 #Distancia servo Y ao X
    y = 7.6 #Dist servo X ao pe

    z = 7.0 #Distancia servo Y ao pe(Dist. requerida)

    try:
        start()

        while(z < y+x):
            servoX_ang = calcAngle(z,x,y)

            print("X: ", servoX_ang)
            servoX.write(servoX_ang)

            servoY_ang = abs(90 - calcAngle(y,x,z))
            print("Y: ", servoY_ang)
            servoY.write(servoY_ang)

            print("Z: ", z)
            #z = z + 0.1
            print("-------")

            time.sleep(0.25)

    except KeyboardInterrupt:
        print("Interrupted by User")

main()