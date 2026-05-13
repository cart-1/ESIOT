from machine import Pin, time_pulse_us
import time

TRIG = Pin(14, Pin.OUT)
ECHO = Pin(15, Pin.IN)

def get_distance():
    TRIG.value(0)
    time.sleep_us(2)

    TRIG.value(1)
    time.sleep_us(10)
    TRIG.value(0)

    duration = time_pulse_us(ECHO, 1, 30000)

    if duration < 0:
        return None

    distance_cm = (duration / 2) * 0.0343
    return distance_cm

while True:
    distance = get_distance()

    if distance is not None:
        print("Distance: {:.2f} cm".format(distance))
    else:
        print("Out of range")

    time.sleep(1)