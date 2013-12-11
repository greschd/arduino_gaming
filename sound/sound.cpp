// Author:  Mario S. Könz <mskoenz@gmx.net>
// Date:    15.10.2013 01:07:01 CEST
// File:    empty template.cpp

/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ or COPYING for more details. */

#include <Arduino.h>
#include <tool.hpp>
#include <ustd.hpp>
#include <SPI.h>


class program {
public:

    
    program(): clk_(13), mosi_(11), sel_(8) {
        setup();
    }
    void setup() {
        Serial.begin(460800);
        SPI.begin();
        SPI.setDataMode(SPI_MODE3);
        pinMode(mosi_, OUTPUT);
        pinMode(clk_, OUTPUT);
        pinMode(sel_, OUTPUT);
        digitalWrite(sel_, HIGH);
        write(0);
    }
    
    void write(uint8_t value) {
        digitalWrite(sel_, LOW);
        
        SPI.transfer(value);
        
        digitalWrite(sel_, HIGH);
    }
    
    void loop() {
        write(0);
        delay(1);
        write(2);
        delay(1);
        write(1);
        delay(1);
        write(3);
        delay(1);

    }

private:
    const uint8_t clk_;
    const uint8_t mosi_;
    const uint8_t sel_;
    
};

#include <main.hpp>
