#include "sprite.h"

void Sprite::activate()
{
    isActive = true;

    pinMode(pin, OUTPUT);    // 0x1
    digitalWrite(pin, HIGH); // 0x1
}

void Sprite::deactivate()
{
    isActive = false;

    digitalWrite(pin, LOW); // 0x1
}

void Sprite::toggle()
{
    isActive = !isActive;
}

String Sprite::getStatus() const
{
    return isActive ? "on" : "off";
}

bool Sprite::wait()
{
    
}

String Sprite::say(const char* cstring)
{
    Sprite::beginSetting();
    
    String text = Sprite::getName() + ": "; 
    Serial.print(text);
    Serial.println(cstring);
    return cstring;
}