#ifndef SPRITE_H
#define SPRITE_H

#include "scratchobject.h"

class Sprite : public ScratchObject
{
public:
    // Конструктор вызывает конструктор базового класса
    Sprite(OBJ_TYPE objType, String objName, short objX, short objY, short objPin) : ScratchObject(objType, objName, objX, objY, objPin) {}

    virtual ~Sprite() {};

    void activate() override;
    void deactivate() override;
    void toggle() override;
    String getStatus() const override;
};

#endif // SPRITE_H
