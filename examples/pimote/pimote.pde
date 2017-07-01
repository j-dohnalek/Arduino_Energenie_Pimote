/**
 *
 * Controling the Energenie Pimote sockets from any Arduino based board
 * Copyright (C) 2017  Jiri Dohnalek
 * 
 * File: pimote.pde
 * 
 * pimote.pde is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.

 * pimote.pde is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

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
