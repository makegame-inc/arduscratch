#include "scratchobject.h"
#include "sprite.h"

Sprite LED(true, 13);

void setup(){}

void loop()
{
    LED.activate();
}