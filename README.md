# Arduino Pimote Library

## Power
3.3-5V

## Additional Information
More information on https://jdohnalek.com

## Configuration

Include the library
```C
#include <Pimote.h>
Pimote socket;
```

Define the pins as connected to the Pimote 
```C
socket.setESD0(int p);    // set Encoded Signal D0
socket.setESD1(int p);    // set Encoder Signal D1
socket.setESD2(int p);    // set Encoder Signal D2
socket.setESD3(int p);    // set Encoder Signal D3
socket.setMODSEL(int p);  // set MODSEL mode select signal (OOK/FSK)
socket.setCE(int p); // set CE modular enable (Output ON/OFF)
```
Include the begin method
```C
socket.begin();
```

## Usage

Socket 0 includes all sockets<br>
Individual sockets can be addressed using integers between 1-4

Turn socket on
```C
socket.on(int s);
```

Turn socket off
```C
socket.off(int s);

```


