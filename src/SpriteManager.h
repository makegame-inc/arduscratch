#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <Arduino.h>
#include "Sprite.h"
#include "TimerManager.h"

class SpriteManager {
private:
    static const int MAX_SPRITES = 20;
    Sprite* sprites[MAX_SPRITES];
    int spriteCount;
    TimerManager timerManager;
    
public:
    SpriteManager();
    
    template<typename T>
    T* createSprite(String name);
    
    Led* createLed(String name, uint8_t pin);
    Monitor* createMonitor(String name);
    
    bool createTimer(String timerName, unsigned long interval, bool repeat = false);
    bool isTimerTriggered(String timerName);
    void resetTimer(String timerName);
    
    void updateAll();
    void drawAll();
    Sprite* getSprite(String name);
    ~SpriteManager();
};

#endif