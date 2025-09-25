#ifndef SCRATCHOBJECT_H
#define SCRATCHOBJECT_H

#include <Arduino.h>

enum OBJ_TYPE
{
    ALL,
    PINS,
    SERIALPORT,
    GRAPHICS,
};

class ScratchObject
{
protected:
    OBJ_TYPE ObjType;
    String name;
    short x;
    short y;
    short pin;
    bool isActive;

public:
    // Конструктор инициализирует члены базового класса
    ScratchObject(OBJ_TYPE objType, String objName, short objX, short objY, short objPin) : ObjType(objType), name(objName), x(objX), y(objY), pin(objPin), isActive(false) {}

    virtual ~ScratchObject() {}

    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void toggle() = 0;
    virtual String getStatus() const = 0;

    String getName() const { return name; }
    bool getIsActive() const { return isActive; }
};

#endif // SCRATCHOBJECT_H
