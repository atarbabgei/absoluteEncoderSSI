# absoluteEncoderSSI
reading data from an absolute encoder with Serial data output SSI protocol using Arduino

Inspired by this forum post
https://forum.arduino.cc/t/absolute-rotary-encoder-ssi-spi-how/153103/15
I made a small adjustment so that it can also compatible with some absolute encoders that has chip select pin (CS Pin).
This kind of encoder can only give output when the CS pin is driven (by turning it low just everytime we read data)

Tested on CALT HAE28 Absolute Rotary Encoder and Arduino Uno
https://www.china-encoder.com/product/hae28-absolute-rotary-encoder/

Wiring information can be found on the code
