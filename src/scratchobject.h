#ifndef SCRATCHOBJECT_H
#define SCRATCHOBJECT_H

#include <Arduino.h>

enum SPRITE_TYPE
{
    ALL,
    PINS,
    SERIALPORT,
    GRAPHICS,
};

class ScratchObject
{
protected:
    String name;
    bool isActive;
    short pin;

public:
    ScratchObject(const String &objName) : name(objName), isActive(false) {}
    ScratchObject(bool &objActive) : isActive(objActive) {}
    ScratchObject(bool &objActive, short &objPin) : isActive(objActive), pin(objActive) {}
    ScratchObject(SPRITE_TYPE objSpriteType);

    virtual ~ScratchObject() {}

    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void toggle() = 0;
    virtual String getStatus() const = 0;

    String getName() const { return name; }
    bool getIsActive() const { return isActive; }
};

#endif // ARDUSCRATCH_H