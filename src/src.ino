#include "scratchobject.h"
#include "sprite.h"

Sprite Sprite1(ALL, "Sprite 1", 13);

void setup(){}

void loop()
{
    Sprite1.say("hello i am Sprite 1");    
}