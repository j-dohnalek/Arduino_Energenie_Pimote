/**
 *
 * Controling the Energenie Pimote sockets from any Arduino based board
 * Copyright (C) 2017  Jiri Dohnalek
 *
 * File: Pimote.h
 *
 * Pimote.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * Pimote.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef Pimote_h
#define Pimote_h


class Pimote
{
  public:

    // Setup the sockets
    void begin();
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
    void on(int s);
    // Turn socket off
    void off(int s);

  private:

    static char *sck_on[];    // on bits
    static char *sck_off[];   // off bits
    int gpio17; // Encoded Signal D0
    int gpio22; // Encoder Signal D1
    int gpio23; // Encoder Signal D2
    int gpio27; // Encoder Signal D3
    int gpio24; // MODSEL mode select signal (OOK/FSK)
    int gpio25; // CE modular enable (Output ON/OFF)

    // Set the state of the socket
    void state(int socket, char* on_or_off[]);
};


#endif
