// PicoTrimWheel
// Copyright: Gaetan Bahl - 2025
// SPDX-License-Identifier: GPL-3.0-only

#include "picogamepad/PicoGamepad.h"

PicoGamepad gamepad;

// 16 bit integer for holding input values
int val;

//Constants
int pinA = 21;  // Connected to CLK on KY-040
int pinB = 20;  // Connected to DT on KY-040
int encoderCount = 0;
int aLast;
int aVal;
int bVal;

int STEP = 500;

void setup() {
  Serial.begin(115200);

  pinMode (pinA, INPUT);
  pinMode (pinB, INPUT);
  aLast = digitalRead(pinA);
}

void loop() {

  gamepad.SetWheel(encoderCount);
  

  aVal = digitalRead(pinA);
  bVal = digitalRead(pinB);

  if ((aVal != aLast)&&(aVal==LOW)) { // Means the knob is rotating
    if(bVal == LOW){ 
      if(encoderCount <= 32767 - STEP)
        encoderCount = encoderCount + STEP;
      } // If bVal is Low, too, CW  ++
    else {
      if(encoderCount >= -32767 + STEP)
        encoderCount = encoderCount - STEP;
      } // else, CCW --
    
    Serial.print("Counter: "); Serial.println(encoderCount); 
  }
  aLast = aVal;    //Don't forget to reset aLast

  gamepad.send_update();
}
