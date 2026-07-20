#include "events.h"

void blinkR() {
  digitalWrite(13, !digitalRead(13));
}
void blinkG() {
    digitalWrite(12,!digitalRead(12));
}void blinkB() {
    digitalWrite(11,!digitalRead(11));
}

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  attachEvent(blinkR, 500);
  attachEvent(blinkG, 1000);
  attachEvent(blinkB, 1500);
  
  startEvents();
}

// "lock" the loop for demonstration
void loop(){
  while (1);
}
  