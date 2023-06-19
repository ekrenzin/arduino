#include "Button.h"

Button::Button(int pin) {
  this->pin = pin;
  this->buttonState = 0;
  this->lastButtonState = 0;
  this->buttonPressTime = 0;
  pinMode(pin, INPUT_PULLUP);
}

void Button::setOnPressStartFunction(void (*function)()) {
  onPressStartFunction = function;
}

void Button::checkButton() {
  buttonState = digitalRead(pin);
  if (buttonState == LOW) {
    if (lastButtonState == HIGH) { // Button was just pressed
      buttonPressTime = millis();
      Serial.println("Start");
      if (onPressStartFunction) {
        onPressStartFunction();
      }
    }
  } else if (buttonState == HIGH) {
    if (lastButtonState == LOW) { // Button was just released
      Serial.println("End");
    }
  }
  lastButtonState = buttonState;
}

