// #include "scratchobject.h"
#include "sprite.h"

Sprite LED(true, 13);
Sprite LED(PINS);
// Sprite(typeSprite, "Name", x, y, pins)

void setup(){}

void loop()
{
    LED.activate();
}