#include "Monitor.h"

Monitor::Monitor(String name) : Sprite(name), showMessage(false) {}

void Monitor::update() {
    // Nothing to update
}

void Monitor::draw() {
    if (showMessage && visible) {
        Serial.println("[" + name + "]: " + message);
        showMessage = false;
    }
}

void Monitor::say(String text) {
    message = text;
    showMessage = true;
}