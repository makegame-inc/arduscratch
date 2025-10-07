#ifndef SPRITE_H
#define SPRITE_H

#include <Arduino.h>

class Sprite {
protected:
    String name;
    bool visible;
    
public:
    Sprite(String spriteName);
    
    virtual void update() = 0;
    virtual void draw() = 0;
    
    void show();
    void hide();
    bool isVisible();
    String getName();
    
    virtual ~Sprite();
};

#endif