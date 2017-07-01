#include <Pimote.h>

Pimote socket();
socket.setESD0(int p);    // set Encoded Signal D0
socket.setESD1(int p);    // set Encoder Signal D1
socket.setESD2(int p);    // set Encoder Signal D2
socket.setESD3(int p);    // set Encoder Signal D3
socket.setMODSEL(int p);  // set MODSEL mode select signal (OOK/FSK)
socket.setCE(int p);      // set CE modular enable (Output ON/OFF)

void setup()
{
  // Initiate all pins
  socket.begin();
}

void loop()
{
  // Switch all sockets ON
  socket.On(0);
  delay(1000);
  
  // Switch all sockets OFF
  socket.Off(0);
  delay(1000);
  
  // Switch socket 1 ON
  socket.On(1);
  delay(1000);
  
  // Switch socket 1 OFF
  socket.Off(1);
  delay(1000);

}
