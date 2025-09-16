#ifndef SCRATCHOBJECT_H
#define SCRATCHOBJECT_H

#include <Arduino.h>

class ScratchObject
{
protected:
    String name;
    bool isActive;

public:
    ScratchObject(const String &objName) : name(objName), isActive(false) {}
    ScratchObject(bool &objActive) : isActive(objActive) {}
    
    virtual ~ScratchObject() {}

    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void toggle() = 0;
    virtual String getStatus() const = 0;

    String getName() const { return name; }
    bool getIsActive() const { return isActive; }
};

#endif // ARDUSCRATCH_H