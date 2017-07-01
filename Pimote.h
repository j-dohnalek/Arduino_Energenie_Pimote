/*
  Pimote.cpp - Conversion for Energenie Pimote from Raspberry Pi to
  Arduino.
  Copyright (c) 2016 Jiri Dohnalek.  All right reserved.
*/
#ifndef Pimote_h
#define Pimote_h


class Pimote
{
  public:
  
    // Setup the sockets
    void begin(void);
    // set Encoded Signal D0
    void setESD0(int p);
    // set Encoder Signal D1
    void setESD1(int p);
    // set Encoder Signal D2
    void setESD2(int p);
    // set Encoder Signal D3
    void setESD3(int p);
    // set MODSEL mode select signal (OOK/FSK)
    void setMODSEL(int p);
    // set CE modular enable (Output ON/OFF)
    void setCE(int p);
    // Turn socket on
    void On(int s);
    // Turn socket off
    void Off(int s);

  private:
  
    static char* on[];    // on bits
    static char* off[];   // off bits
    int gpio17; // Encoded Signal D0
    int gpio22; // Encoder Signal D1
    int gpio23; // Encoder Signal D2
    int gpio27; // Encoder Signal D3
    int gpio24; // MODSEL mode select signal (OOK/FSK)
    int gpio25; // CE modular enable (Output ON/OFF)
  
    // Set the state of the socket
    void State(int socket, char* on_or_off[]);
};


#endif
