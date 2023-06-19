// File: Button.h
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
  private:
    int pin;
    int buttonState;
    int lastButtonState;
    unsigned long buttonPressTime;
    void (*onPressStartFunction)();

  public:
    Button(int pin);
    void setOnPressStartFunction(void (*function)());
    void checkButton();
};

#endif
