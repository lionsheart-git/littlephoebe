#include "blink_lib.hpp"

#include "Arduino.h"

void setup() {
    blink_setup(); // Setup for blinking
}

void loop() {
    blink(1000); // Blink for a second
}