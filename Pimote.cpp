/*
  Pimote.h - Conversion for Energenie Pimote from Raspberry Pi to
  Arduino.
  Copyright (c) 2016 Jiri Dohnalek.  All right reserved.
*/


#include "Arduino.h" // include core Arduino function
#include "Pimote.h"  // include Pimote definition


// Constructor /////////////////////////////////////////////////////////////////


Pimote::Pimote(int io17, int io22, int io23, int io27, int io24, int io25)
{
  gpio17 = io17; // Encoded Signal D0
  gpio22 = io22; // Encoder Signal D1
  gpio23 = io23; // Encoder Signal D2
  gpio27 = io27; // Encoder Signal D3
  gpio24 = io24; // MODSEL mode select signal (OOK/FSK)
  gpio25 = io25; // CE modular enable (Output ON/OFF)

  Setup();
}


// Public Methods //////////////////////////////////////////////////////////////


void Pimote::Setup(void)
{
  int pin[] = {gpio17, gpio22, gpio23, gpio27, gpio24, gpio25};
  for(int i=0; i<6; i++){ pinMode(pin[i], OUTPUT);  }
  for(int i=0; i<6; i++){ pinMode(pin[i], LOW); }
  delay(500);
}


void Pimote::On(int s)
{
  if(s >= 0 && s <= 4){
    State(s, on);
  }
}


void Pimote::Off(int s)
{
  if(s >= 0 && s <= 4){
    State(s, off);
  }
}


// Private Variables ///////////////////////////////////////////////////////////


char* Pimote::on[5]  = {"1011", "1111", "1110","1101", "1100"};
char* Pimote::off[5] = {"0011", "0111", "0110","0101", "0100"};


// Private Methods /////////////////////////////////////////////////////////////


void Pimote::State(int socket, char* on_or_off[])
{
  int pin[] = {gpio27, gpio23, gpio22, gpio17};
  for(int i=0; i<4; i++){
    digitalWrite(pin[i], LOW);
    if(on_or_off[socket][i] - '0' == 1 ){
      digitalWrite(pin[i], HIGH);
    }
  }
  delay(100);
  digitalWrite(gpio25, HIGH);
  delay(250);
  digitalWrite(gpio25, LOW);
}
