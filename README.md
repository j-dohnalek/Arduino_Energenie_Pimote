<h1>Arduino Pimote Library</h1>

<h2>Usage</h2>
Energenie Pimote remotely controlled sockets<br />
Product: https://energenie4u.co.uk/catalogue/product/ENER002-2PI

<h2>Power</h2>
3.3-5V

<h2>Additional Information</h2>
More information on https://jdohnalek.com

<h2>Methods</h2>

Create the object
```C
Pimote socket();
```
Set all the neccessary pins
```C
socket.setESD0(int p);    // set Encoded Signal D0
socket.setESD1(int p);    // set Encoder Signal D1
socket.setESD2(int p);    // set Encoder Signal D2
socket.setESD3(int p);    // set Encoder Signal D3
socket.setMODSEL(int p);  // set MODSEL mode select signal (OOK/FSK)
socket.setCE(int p);      // set CE modular enable (Output ON/OFF)
```
Initialize the pins
```C
socket.begin()
```

Turn socket On
```C
socket.On(int s);
```

Turn socket Off
```C
socket.Off(int s);
```
