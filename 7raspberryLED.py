from machine import Pin
import time
led = Pin(17, Pin.OUT) # GPIO 17 on Pico
while True:
 led.value(1)
 print("LED ON")
 time.sleep(1)
 led.value(0)
 print("LED OFF")
 time.sleep(1)