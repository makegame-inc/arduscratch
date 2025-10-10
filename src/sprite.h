#ifndef SPRITE_H
#define SPRITE_H

#include "scratchobject.h"

class Sprite : public ScratchObject
{
private:
    bool flagBeginSetting = false;
    void beginSetting()
    {
        if (!flagBeginSetting)
        {
            Serial.begin(9600);
            flagBeginSetting = true;
        }
    }
public:
    // Конструктор вызывает конструктор базового класса
    Sprite(OBJ_TYPE objType, String objName, short objX, short objY, short objPin, int objTimer) :
    ScratchObject(objType, objName, objX, objY, objPin, objTimer) {}

    Sprite(OBJ_TYPE objType, String objName, short objPin):
    ScratchObject(objType, objName, 0, 0, objPin, 0) {}

    virtual ~Sprite() {};

    void activate() override;
    void deactivate() override;
    void toggle() override;
    String getStatus() const override;
    bool wait() override;
    virtual String say(const char* cstring = "");
};

#endif // SPRITE_H
