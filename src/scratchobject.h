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
    int timerValue;

public:
    // Описываем объект 
    ScratchObject(OBJ_TYPE objType, String objName, short objX, short objY, short objPin, int objTimer)
    : ObjType(objType), name(objName), x(objX), y(objY), pin(objPin), isActive(false), timerValue(objTimer) {}
    virtual ~ScratchObject() {}

    // Механика объекта
    virtual void activate() = 0;           // активация статуса объекта
    virtual void deactivate() = 0;         // деактивация статуса объекта
    virtual void toggle() = 0;             // переключить статус объекта
    virtual String getStatus() const = 0;  // получить статус объекта
    virtual bool wait() = 0;               // спрайт ждет
    virtual String say(const char* cstring = "") = 0;  // сказать

    String getName() const { return name; }
    bool getIsActive() const { return isActive; }
};

#endif // SCRATCHOBJECT_H
