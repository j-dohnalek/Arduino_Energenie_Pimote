# Arduino Pimote Library

## Usage
Energenie Pimote remotely controlled sockets
Product: https://energenie4u.co.uk/catalogue/product/ENER002-2PI

## Power
3.3-5V

## Additional Information
More information on https://jdohnalek.com

## Configuration

Define the following pins 

```C
socket.setESD0(int p);    // set Encoded Signal D0
socket.setESD1(int p);    // set Encoder Signal D1
socket.setESD2(int p);    // set Encoder Signal D2
socket.setESD3(int p);    // set Encoder Signal D3
socket.setMODSEL(int p);  // set MODSEL mode select signal (OOK/FSK)
socket.setCE(int p); // set CE modular enable (Output ON/OFF)
```
