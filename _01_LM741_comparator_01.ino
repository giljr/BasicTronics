/*
   Project name: #basicTronic-01
     Studing LM741 as Comparator & Opamp
     Flavour III - Testing a ramp voltage on pwm signal delivered by Arduino
     Hex File: _01_LM741_comparator_01.ino
   Revision History:
     Apr, 2017
       - Medium webpage: https://goo.gl/s1K0Ya
   Description:
          Uses an Arduino to test LM741 comparator behaviour and plot the results with
          spreadsheet table (https://goo.gl/siwBQ4)
   MCU:                  Arduino 1.8.2 - @16MHz       http://www.arduino.cc/
   Connections:
      See Official youtube channel vids:
   Based on:   Circuitos com amplificadores operacionais (ART318)
               from http://www.newtoncbraga.com.br/index.php/artigos/54-dicas/2055-art318.html
               Voltage Measurements in Oscilloscope
               From http://www.hobbyprojects.com/oscilloscope_tutorial/voltage_measurements.html
               Making a mini Audio Amplifier using Operational Ampifier(LM358)
               from https://projectnitmn.wordpress.com/2016/06/02/blog-post-title-2/
   Datasheet Atmega328P  8-bit AVR Microcontrollers:
   http://www.atmel.com/Images/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License v3 as published by
   the Free Software Foundation
*/
/*
  Comparator741
  Uses an Arduino to test LM741 comparator behaviour and plot the results with processing
  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/Comparator741
*/

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

#define INVERTED_INPUT_PIN 10
const int READ_PWM_PIN = A0;
const int READ_FILTERED_PIN = A1;
const int READ_DIGITAL_PIN = 8;

int inverted_value = 0;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)
  pinMode(INVERTED_INPUT_PIN, OUTPUT);

  FlexiTimer2::set(10, sample);
  FlexiTimer2::start();
}

void loop() {
   for (inverted_value = 0; inverted_value <= 255; inverted_value += 10) {
    analogWrite(INVERTED_INPUT_PIN, inverted_value);
    delay(100);
  }
  for (inverted_value = 255; inverted_value >= 0; inverted_value -= 10) {
    analogWrite(INVERTED_INPUT_PIN, inverted_value);
    delay(100);
  }
}

// sample values and pipe to processing
void sample() {
  String result = "";
  Serial.println(result + inverted_value + "," + analogRead(READ_PWM_PIN) + "," + analogRead(READ_FILTERED_PIN) + "," + digitalRead(READ_DIGITAL_PIN));
}
