#include "Keyboard.h"

#define ATTENDANCE 0
#define MUTE_AUDIO 1
#define MUTE_VIDEO 2
#define HELLO 3
#define PAW 4

const int buttonPins[5] = {6, 5, 4, 3, 2};
int previousButtonStates[5] = {HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  // Initialize the input pins
  for (int i = 0; i < 5; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  // Initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // Read pushbutton states
  for (int i = 0; i < 5; i++) {
    int buttonState = digitalRead(buttonPins[i]);
    // if the button state has changed,
    if ((buttonState != previousButtonStates[i])
        // and it's currently pressed:
        && (buttonState == HIGH)) {
      switch (i) {
        case ATTENDANCE:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('h');
          delay(100);
          Keyboard.releaseAll();
          delay(100);
          Keyboard.println("Adhiyan Varunkumar 1A");
          break;
        case MUTE_AUDIO:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('a');
          delay(100);
          Keyboard.releaseAll();
          break;
        case MUTE_VIDEO:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('v');
          delay(100);
          Keyboard.releaseAll();
          break;
        case HELLO:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('h');
          delay(100);
          Keyboard.releaseAll();
          break;
        case PAW:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('p');
          delay(100);
          Keyboard.releaseAll();
          break;
      }
      delay(100);
    }
    // save the current button state for comparison next time:
    previousButtonStates[i] = buttonState;
  }
}