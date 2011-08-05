/* Copyright 2011 David Irvine
 * 
 * This file is part of Loguino
 *
 * Loguino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Loguino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Loguino.  If not, see "http://www.gnu.org/licenses/".
 * 
 * $Rev$:   
 * $Author$: 
 * $Date$:  

*/


#include "config.h"
#include "Logger_Serial.h"
//ifdef ENABLE_SERIAL_OUTPUT

//! When the serial device is online, active is set to true.
bool SerialLogger::active;

//! Flushes the serial buffer.
bool SerialLogger::flush(){
    if (active){
        SO_SERIAL_PORT.flush();
		return true;
    }
	return false;
}

/**
 * Initializes the SerialLogger module by setting the BAUD rate on the serial 
 * port. Sets active to true.
 */
bool SerialLogger::begin()
{
    SO_SERIAL_PORT.begin(SO_SERIAL_PORT_SPEED);
    active=true;
    return true;
}


/**
 * Calls the toCSV method on the message and writes the data to the serial 
 * port.
 */
bool SerialLogger::log(Message &msg){
    if (!active){
        return false;
    }
    SO_SERIAL_PORT.println(msg.toCSV());
	return true;
}
//endif
