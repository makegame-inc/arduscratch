#ifndef MONITOR_SPRITE_H
#define MONITOR_SPRITE_H

#include "../Sprite.h"

class Monitor : public Sprite {
private:
    String message;
    bool showMessage;
    
public:
    Monitor(String name);
    void update() override;
    void draw() override;
    void say(String text);
};

#endif