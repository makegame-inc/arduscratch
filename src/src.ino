#include "scratchobject.h"
#include "sprite.h"

Sprite Sprite1(ALL, "Sprite 1", 13);

// void setup()
// {
// }

int main()
{
    init();
    
    while (true)
    {
        Sprite1.say("hello i am Sprite 1");
        Sprite1.activate();
        delay(1000);
        Sprite1.deactivate();
        delay(1000);
    }
}