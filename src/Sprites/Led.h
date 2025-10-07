#ifndef LED_SPRITE_H
#define LED_SPRITE_H

#include "../Sprite.h"

class Led : public Sprite {
private:
    uint8_t pin;
    bool state;
    unsigned long lastBlink;
    int blinkInterval;
    
public:
    Led(String name);
    void setPin(uint8_t ledPin);
    
    void update() override;
    void draw() override;
    
    void turnOn();
    void turnOff();
    void toggle();
    void blink(int interval);
    bool isOn();
};

#endif