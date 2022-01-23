/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Example uses a static library to show off generate_arduino_library().

  This example code is in the public domain.
 */

#include "blink_lib.hpp"

#include "Arduino.h"

void setup() {
    blink_setup(); // Setup for blinking
}

void loop() {
    blink(10000); // Blink for a second
}
