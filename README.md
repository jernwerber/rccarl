# Remote Control your Carl (Arduino-based) Robot using 2 micro:bits (rccarl)
## Files
- Micro:bit transmitter (TX) code written in Python: [rccarl-tx.py](rccarl-tx.py)
- Micro:bit receiver (RX) code written in Python: [rccarl-rx.py](rccarl-rx.py)
- Carl Robot Arduino code written in C as an Arduino sketch: [rccarl-arduino.ino](rccarl-arduino.ino)
## Notes
- You can use the Micro:bit TX and RX code as an example of sending and receiving messages, using Python, on Micro:bits.
## Setup
> Note: You will need to attach the Micro:bit (RX) to the Arduino on the Carl. You can attach these with some combination of alligator clips (attached to the Micro:bit's edge) and jumper cables (attached to the corresponding headers/sockets on the Carl Robot board)
- Connect the Arduino 3.3V pin to the Micro:bit (RX) 3V edge pin and the Arduino GND (ground) pin to the Micro:bit GND edge pin.
- Pins 0, 1, and 2 of the Micro:bit (RX) needs to be attached to three pins of the Arduino to transmit the instructions it receives.

In the Arduino code, these pins are define on lines 6-8 as follows:
```
#define UBPIN0 2
#define UBPIN1 3
#define UBPIN2 4
```
where `#define UBPIN0 2` corresponds to the Arduino digital pin 2 (look for D2 on the board) and Micro:bit pin 0. To change this to a different pin, use a different number, e.g. `#define UBPIN0 8` would link Arduino digital pin 8 with Micro:bit pin 0. For analog pins, you would use `#define UBPIN0 A2`, which links Arduino analog pin 2 with Micro:bit pin 0.
