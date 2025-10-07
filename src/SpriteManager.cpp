#include "SpriteManager.h"
#include "Sprites/Led.h"
#include "Sprites/Monitor.h"

SpriteManager::SpriteManager() : spriteCount(0) {}

template<typename T>
T* SpriteManager::createSprite(String name) {
    if (spriteCount >= MAX_SPRITES) return nullptr;
    
    for (int i = 0; i < spriteCount; i++) {
        if (sprites[i]->getName() == name) {
            return nullptr;
        }
    }
    
    T* sprite = new T(name);
    sprites[spriteCount++] = sprite;
    return sprite;
}

template Led* SpriteManager::createSprite<Led>(String);
template Monitor* SpriteManager::createSprite<Monitor>(String);

Led* SpriteManager::createLed(String name, uint8_t pin) {
    Led* led = createSprite<Led>(name);
    if (led) {
        led->setPin(pin);
    }
    return led;
}

Monitor* SpriteManager::createMonitor(String name) {
    return createSprite<Monitor>(name);
}

bool SpriteManager::createTimer(String timerName, unsigned long interval, bool repeat) {
    return timerManager.createTimer(timerName, interval, repeat);
}

bool SpriteManager::isTimerTriggered(String timerName) {
    return timerManager.isTimerTriggered(timerName);
}

void SpriteManager::resetTimer(String timerName) {
    timerManager.resetTimer(timerName);
}

void SpriteManager::updateAll() {
    timerManager.updateTimers();
    
    for (int i = 0; i < spriteCount; i++) {
        sprites[i]->update();
    }
}

void SpriteManager::drawAll() {
    for (int i = 0; i < spriteCount; i++) {
        sprites[i]->draw();
    }
}

Sprite* SpriteManager::getSprite(String name) {
    for (int i = 0; i < spriteCount; i++) {
        if (sprites[i]->getName() == name) {
            return sprites[i];
        }
    }
    return nullptr;
}

SpriteManager::~SpriteManager() {
    for (int i = 0; i < spriteCount; i++) {
        delete sprites[i];
    }
}