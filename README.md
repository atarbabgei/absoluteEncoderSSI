# absoluteEncoderSSI
reading data from an absolute encoder with Serial data output SSI protocol using Arduino

Inspired by this forum post
https://forum.arduino.cc/t/absolute-rotary-encoder-ssi-spi-how/153103/15
I made a small adjustment so that it can also compatible with some absolute encoders that has Chip Select (CS) pin.
This kind of encoder can only give output when the CS pin is driven by turning it low just everytime we need to read a new data.

Tested on CALT HAE28 (HAE28U5V12A0.22) Absolute Rotary Encoder and Arduino Uno R3.

This might work on other SSI Absolute Encoders which use the same principle.

Wiring information can be found on the code
