#ifndef SPRITE_H
#define SPRITE_H

#include "scratchobject.h"

class Sprite : public ScratchObject
{
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
    bool timer() override;
};

#endif // SPRITE_H
