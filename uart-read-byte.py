
# test program: read a byte from the uart 
# in a loop.

import serial
PORT = '/dev/ttyACM0'
BAUD = 9600

fd = serial.Serial(port=PORT, baudrate=BAUD)

while True:
    print ord(fd.read())
