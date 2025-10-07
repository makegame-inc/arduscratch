#include "Led.h"

Led::Led(String name) : Sprite(name), pin(LED_BUILTIN), state(LOW), lastBlink(0), blinkInterval(0) {}

void Led::setPin(uint8_t ledPin) {
    pin = ledPin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
}

void Led::update() {
    if (blinkInterval > 0) {
        unsigned long currentTime = millis();
        if (currentTime - lastBlink >= blinkInterval) {
            toggle();
            lastBlink = currentTime;
        }
    }
}

void Led::draw() {
    digitalWrite(pin, state);
}

void Led::turnOn() {
    state = HIGH;
    blinkInterval = 0;
    draw();
}

void Led::turnOff() {
    state = LOW;
    blinkInterval = 0;
    draw();
}

void Led::toggle() {
    state = !state;
    draw();
}

void Led::blink(int interval) {
    blinkInterval = interval;
    lastBlink = millis();
}

bool Led::isOn() {
    return state;
}