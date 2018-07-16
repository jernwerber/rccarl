from microbit import *
import radio

# Radio
radio.on() # Turn on the radio
radio_channel = 10 # Set the channel - must be the same as the RX
radio_delay = 50 # radio_delay is the time between radio sends (default: 50 ms)
radio.config(channel=radio_channel) # Configure the radio to use radio_channel

direction_state = 0
last_sent = 0 # Variable for tracking the last time 
tilt_threshold = 512 # When tilt is greater than this value, reverse (default: 512, a larger positive value means more extreme tilt necessary)

while True:
    tilt = accelerometer.get_y()
    if tilt > tilt_threshold:
        direction_state = -1        
    else:
        direction_state = 0    
    
    if (running_time()-last_sent) > radio_delay:
        if button_a.is_pressed() and button_b.is_pressed():
            if direction_state == 0:
                display.show(Image.ARROW_N, wait=False, clear=True)
                radio.send('F')
                last_sent = running_time()
            elif direction_state == -1:
                display.show(Image.ARROW_S, wait=False, clear=True)
                radio.send('B')
                last_sent = running_time()
        elif button_a.is_pressed():
            display.show(Image.ARROW_W, wait=False, clear=True)
            radio.send('L')
            last_sent = running_time()
        elif button_b.is_pressed():
            display.show(Image.ARROW_E, wait=False, clear=True)
            radio.send('R')
            last_sent = running_time()