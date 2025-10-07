#include "sprite.h"

void Sprite::activate()
{
    isActive = true;

    // pinMode(pinSprite, OUTPUT);    // 0x1
    // digitalWrite(pinSprite, HIGH); // 0x1
}

void Sprite::deactivate()
{
    isActive = false;
}

void Sprite::toggle()
{
    isActive = !isActive;
}

String Sprite::getStatus() const
{
    return isActive ? "on" : "off";
}

bool Sprite::timer()
{
    
}