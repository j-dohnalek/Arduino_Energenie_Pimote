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
    Pimote(int io17, int io22, int io23, int io27, int io24, int io25);
    void On(int s);
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

    void Setup(void);
    void State(int socket, char* on_or_off[]);
};


#endif
