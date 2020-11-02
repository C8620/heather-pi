import serial
import pynmea2

def parseGPS(str):
    if str.find('GGA') > 0:
        msg = pynmea2.parse(str)
        print "%s %s %s" % (msg.lat,msg.lon,msg.altitude)


serialPort = serial.Serial("/dev/ttyUSB0", 9600, timeout=0.5)

for num in range (10,20):
    str = serialPort.readline()
    parseGPS(str)