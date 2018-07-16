from microbit import *
import radio

radio.on()
radio.config(queue=1,channel=10)
valid_instructions = ['F','L','B','R']
last_instruction = 0
instruction_delay = 50

def output_instruction(val0, val1, val2):
    pin0.write_digital(val0)
    pin1.write_digital(val1)
    pin2.write_digital(val2)
    
while True:
    instruction = radio.receive()
    if instruction:
        last_instruction = running_time()
        if instruction in valid_instructions:
            if instruction == 'F':
                output_instruction(1,0,0)
            elif instruction == 'L':
                output_instruction(1,1,0)
            elif instruction == 'R':
                output_instruction(1,0,1)
            elif instruction == 'B':
                output_instruction(0,1,0)
            display.show(instruction,wait=False,clear=True)
            sleep(5)
            
    else:
        if (running_time() - last_instruction) > 50:
            output_instruction(0,0,0)
    
    