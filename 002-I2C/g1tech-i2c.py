import smbus
from time import sleep

bus = smbus.SMBus(1)
SLAVE_ADDRESS = 0x04

def request_reading():
    reading = int(bus.read_byte(SLAVE_ADDRESS))
    print(reading)

while True:
    request_reading()
    sleep(0.25)
