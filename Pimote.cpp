/**
 *
 * Controling the Energenie Pimote sockets from any Arduino based board
 * Copyright (C) 2017  Jiri Dohnalek
 * 
 * File: Pimote.cpp
 * 
 * Pimote.cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * Pimote.cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */


#include "Arduino.h" // include core Arduino function
#include "Pimote.h"  // include Pimote definition

// Public Methods //////////////////////////////////////////////////////////////

void setESD0(int p){
  // Encoded Signal D0
  gpio17 = p;
}

void setESD1(int p){
  // Encoder Signal D1
  gpio22 = p;
}

void setESD2(int p){
  // Encoder Signal D2
  gpio23 = p;
}

void setESD3(int p){
  // Encoder Signal D3
  gpio27 = p;
}

void setMODSEL(int p){
  // MODSEL mode select signal (OOK/FSK)
  gpio24 = p;
}

void setCE(int p){
  // CE modular enable (Output ON/OFF)
  gpio25 = p;
}

// Enable all pins
void Pimote::begin(void)
{
  int pin[] = {gpio17, gpio22, gpio23, gpio27, gpio24, gpio25};
  // Set the pins to output
  for(int i=0; i<6; i++){ pinMode(pin[i], OUTPUT);  }
  // Set the pins low
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

// Binary mapping of the output state
char* Pimote::on[5]  = {"1011", "1111", "1110","1101", "1100"};
char* Pimote::off[5] = {"0011", "0111", "0110","0101", "0100"};


// Private Methods /////////////////////////////////////////////////////////////


void Pimote::State(int socket, char* on_or_off[])
{
  // Check the state of each pin
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
