#include "sprite.h"

Sprite::Sprite(bool objActive) : ScratchObject(objActive) {}

Sprite::~Sprite() {}

void Sprite::activate()
{
    isActive = true;
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
