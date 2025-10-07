// ArduinoScratch.ino
#include "SpriteManager.h"
#include "Sprites/Led.h"
#include "Sprites/Monitor.h"

SpriteManager manager;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting Arduino Scratch System...");
    
    // Создаем объекты
    Led* redLed = manager.createLed("RedLED", 13);
    Led* greenLed = manager.createLed("GreenLED", 12);
    Monitor* serialMonitor = manager.createMonitor("Serial");
    
    // Настраиваем начальное состояние
    redLed->turnOn();
    greenLed->blink(500);
    serialMonitor->say("System started!");
    
    // Создаем таймеры
    manager.createTimer("blink_timer", 1000, true);
    manager.createTimer("message_timer", 3000, true);
    
    Serial.println("System initialized");
}

void loop() {
    manager.updateAll();
    manager.drawAll();
    delay(50);
}