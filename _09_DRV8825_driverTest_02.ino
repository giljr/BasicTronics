
/*
   Project name: DRV8825 Driver & Stepper Motor 24BYJ48 #basicTronic-09
     Studing DRV8825 & 24BYJ48 Stepper Motor
     Flavour II - Testing Steppper Nodes
     Hex File: _09_DRV8825_driverTest_02.ino
   Revision History:
     Jun, 2017
       - Medium webpage: 
   Description:
          Simple: a platform to test the servo with DRV8825B DRIVER for my 
          balanced car project (thanks to Brokking.net)
   MCU:                  Arduino 1.8.3 - @16MHz       http://www.arduino.cc/
   Connections:
      See Official youtube channel vids:
   Based on:   Arduino Stepper Drivers Tutorial-2/2 by R Jordan Kreindler in arduino
               from
   Datasheet DRV8825  INTEGRATED DRIVER FOR BIPOLAR MOTOR
   https://www.pololu.com/file/download/drv8825.pdf?file_id=0J590
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License v3 as published by
   the Free Software Foundation
*/
// ******************************
//  Sketch by R. Jordan Kreindler, written October 2016
//    to work with DRV8825 stepper driver module
//  Rotates stepper in full, 1/2, 1/4, 1/8, 1/16, and 1/32 step modes
//    with the parameter "rotations" specifying how many times to
//    rotate for each stepping mode
// ******************************

#include <LiquidCrystal.h>
// LiquidCrystal (RS,  E, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // For standalone, non-shield, LCD

int ms1Pin   = A0;                  // Stepstick MS0 to Arduino digital pin 9
int ms2Pin   = A1;                  // Stepstock MS1 to Arduino digital pin 10
int ms3Pin   = A2;                  // Stepstick MS2 to Arduino digital pin 11

int stepPin  = A3;                  // Stepstick STEP pin to Arduino digital pin 12
int dirPin   = A4;                  // Stepstick DIR pin to Arduino digital  pin 13

int numSteps = 708;                 //720/5.625 degree = 128/2 = 64 //int numSteps = 48;Number of steps in 360 degree rotation
int rotations = 3;                  // Number of rotations of the rotor for each

int delay1  =   2;                  // Delay between coil activations (ms)
int delay2  =   2000;               // Delay between subsequent rotations
int i;                              // int to use in for loop

//------------------------------
void setup() {

  pinMode(ms1Pin,          OUTPUT); // MS1 set to receive Arduino signals
  pinMode(ms2Pin,          OUTPUT); // MS2 set to receive Arduino signals
  pinMode(ms3Pin,          OUTPUT); // MS3 set to receive Arduino signals
  pinMode(stepPin,         OUTPUT); // stepPin set to receive Arduino signals
  pinMode(dirPin,          OUTPUT); // DIR set to receive Arduino signals
  lcd.begin(16, 2);                 // Sets the size of the LCD in characters and lines
  lcd.clear();                      // Clear the LCD screen of characters and symbols}
  lcd.setCursor(0,0);
  lcd.print("   Stepstick");
  lcd.setCursor(0,1);
  lcd.print(" Mode: ");
}

//------------------------------

void loop() {

  delay(delay2);
  digitalWrite(dirPin, LOW);
    lcd.setCursor(7, 1);           // Move the cursor to 1th position on 1st line
    lcd.print("Full Step    ");
                                   // Rotate stepper rotatations revolutions, using full step method
  digitalWrite(ms1Pin, LOW);
  digitalWrite(ms2Pin, LOW);
  digitalWrite(ms3Pin, LOW);

  for (i = 1; i <= (numSteps * 1 * rotations); ++i) {
    digitalWrite(stepPin, LOW);    // Prepare to take a step
    digitalWrite(stepPin, HIGH) ;  // Take a step
    delay(delay1);                 // Allow some delay between energizing
                                   // the coils to allow stepper rotor time to respond.
  }
  delay(delay2);

  digitalWrite(dirPin, HIGH);
                                   // Rotate stepper rotatations revolutions, using half step method
  digitalWrite(ms1Pin, HIGH);
  digitalWrite(ms2Pin, LOW);
  digitalWrite(ms3Pin, LOW);
    lcd.setCursor(7, 1);            // Move the cursor to 1th position on 1st line
    lcd.print("2 Step        ");
  for (i = 1; i <= (numSteps * 2 * rotations); ++i) {
    digitalWrite(stepPin, LOW);     // Prepare to take a step
    digitalWrite(stepPin, HIGH) ;   // Take a step
    delay(delay1);                  // Allow some delay between energizing
                                    // the coils to allow stepper rotor time to respond.
  }


  delay(delay2);
  digitalWrite(dirPin, LOW);

  // Rotate stepper a rotatations revolutions, using quarter stepping
  digitalWrite(ms1Pin, LOW);
  digitalWrite(ms2Pin, HIGH);
  digitalWrite(ms3Pin, LOW);
    lcd.setCursor(7, 1);            // Move the cursor to 1th position on 1st line
    lcd.print("4 Step        ");
  for (i = 1; i <= (numSteps * 4 * rotations); ++i) {
    digitalWrite(stepPin, LOW);     // Prepare to take a step
    digitalWrite(stepPin, HIGH) ;   // Take a step
    delay(delay1);                  // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }

                                    // Rotate stepper rotations revolution, using microstepping
                                    //  8 steps/step

  delay(delay2);
  digitalWrite(dirPin, HIGH);

  digitalWrite(ms1Pin, HIGH);
  digitalWrite(ms2Pin, HIGH);
  digitalWrite(ms3Pin, LOW);
  
    lcd.setCursor(7, 1);              // Move the cursor to 1th position on 1st line
    lcd.print("8 Step        ");
  for (i = 1; i <= (numSteps * 8 * rotations); ++i) {
    digitalWrite(stepPin, LOW);       // Prepare to take a step
    digitalWrite(stepPin, HIGH) ;     // Take a step
    delay(delay1);                    // Allow some delay between energizing
                                      // the coils to allow stepper rotor time to respond.
  }

                                      // Rotate stepper rotations revolution, using microstepping
                                      //  16 steps/step

  delay(delay2);
  digitalWrite(dirPin, LOW);

  digitalWrite(ms1Pin, LOW);
  digitalWrite(ms2Pin, LOW);
  digitalWrite(ms3Pin, HIGH);
  lcd.setCursor(7,1);
  lcd.print("16 Step          ");
  for (i = 1; i <= numSteps * 16 * rotations; ++i) {
    digitalWrite(stepPin, LOW);         // Prepare to take a step
    digitalWrite(stepPin, HIGH) ;       // Take a step
    delay(delay1);                      // Allow some delay between energizing
                                        // the coils to allow stepper rotor time to respond.
  }

                                        // Rotate stepper rotations revolution, using microstepping
                                        //  32 steps/step

  delay(delay2);
  digitalWrite(dirPin, HIGH);

  digitalWrite(ms1Pin, HIGH);
  digitalWrite(ms2Pin, HIGH);
  digitalWrite(ms3Pin, HIGH);
  lcd.setCursor(7,1);
  lcd.print("32 Step          ");
  for (i = 1; i <= numSteps * 32 * rotations; ++i) {
    digitalWrite(stepPin, LOW);         // Prepare to take a step
    digitalWrite(stepPin, HIGH) ;       // Take a step
    delay(delay1);                      // Allow some delay between energizing
                                        // the coils to allow stepper rotor time to respond.
  }


}

