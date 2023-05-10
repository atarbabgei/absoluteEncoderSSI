# Absolute Encoder SSI

This repository provides an Arduino code for reading data from an absolute encoder with Serial data output SSI protocol. The code has been modified to be compatible with some absolute encoders that have a Chip Select (CS) pin. 

## Inspiration
The code is inspired by a forum post on the Arduino Forum, which can be found [here](https://forum.arduino.cc/t/absolute-rotary-encoder-ssi-spi-how/153103/15).

## Supported Encoder and Arduino Board
The code has been tested with the following components:
- Encoder: CALT HAE28 (HAE28U5V12A0.22) 12bit 5V Absolute Rotary Encoder
- Arduino Board: Arduino Uno R3

Please note that this code might also work with other SSI Absolute Encoders that use the same principle.

## Wiring Instructions
To connect the absolute encoder to your Arduino board, follow these wiring instructions:

![image](https://github.com/atarbabgei/absoluteEncoderSSI/assets/7202497/8203545b-0f10-45ac-9f74-a0d0de23568b)


| CALT HAE28 Wire Color | Encoder Pin | Arduino Pin |
|--------------------|-------------|-------------|
| Red       | Power       | +5V         |
| Black       | GND         | GND         |
| Blue       | Clock       | Pin 5       |
| Green       | Data        | Pin 6       |
| Yellow        | Chip Select | Pin 7       |

Make sure to check the specific pinout and connections of your encoder if it differs from the example above.

## Usage
1. Connect the absolute encoder to your Arduino board following the wiring instructions provided.
2. Upload the code to your Arduino board using the Arduino IDE or any other compatible software.
3. Open the serial monitor in the Arduino IDE or any other serial monitor software.
4. Run the code and observe the data read from the absolute encoder on the serial monitor.

Feel free to modify the code to suit your specific requirements or integrate it into your own projects.

If you have any questions or encounter any issues, please don't hesitate to open an issue on the GitHub repository.
