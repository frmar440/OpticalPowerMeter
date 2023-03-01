import serial
import time


with serial.Serial('/dev/ttyACM0') as ser:
    
    while True:

        # trigger Serial.available()
        ser.write(b'Y')

        # read sensor values as an array of bytes
        sensorValues = ser.read(size=160)

        print(sensorValues)

        time.sleep(3)
