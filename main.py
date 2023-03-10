"""
This program sends a byte out, and waits for an array of bytes.

Call-and-response (handshaking) method with OpticalPowerMeter.ino

created 03/01/2023
by Frédéric Marcotte
"""

import serial


with serial.Serial(port='/dev/ttyACM0', baudrate='9600', timeout=1) as ser:
    
    while True:

        # trigger Serial.available()
        ser.write(b'Y')

        # read sensor values as an array of bytes
        sensorValues = ser.read(size=160)

        print( [ int.from_bytes( sensorValues[2*i:2*(i+1)], byteorder='little' ) for i in range(80) ] )
