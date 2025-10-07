#include "TimerManager.h"

TimerManager::TimerManager() : timerCount(0) {}

bool TimerManager::createTimer(String timerName, unsigned long interval, bool repeat) {
    if (timerCount >= MAX_TIMERS) return false;
    
    for (int i = 0; i < timerCount; i++) {
        if (timers[i].name == timerName) {
            return false;
        }
    }
    
    timers[timerCount].name = timerName;
    timers[timerCount].interval = interval;
    timers[timerCount].lastTrigger = millis();
    timers[timerCount].repeating = repeat;
    timers[timerCount].active = true;
    timerCount++;
    
    return true;
}

void TimerManager::updateTimers() {
    unsigned long currentTime = millis();
    
    for (int i = 0; i < timerCount; i++) {
        if (timers[i].active && (currentTime - timers[i].lastTrigger >= timers[i].interval)) {
            timers[i].lastTrigger = currentTime;
            if (!timers[i].repeating) {
                timers[i].active = false;
            }
        }
    }
}

bool TimerManager::isTimerTriggered(String timerName) {
    unsigned long currentTime = millis();
    
    for (int i = 0; i < timerCount; i++) {
        if (timers[i].name == timerName && timers[i].active) {
            if (currentTime - timers[i].lastTrigger == 0) {
                return true;
            }
        }
    }
    return false;
}

void TimerManager::resetTimer(String timerName) {
    for (int i = 0; i < timerCount; i++) {
        if (timers[i].name == timerName) {
            timers[i].lastTrigger = millis();
            timers[i].active = true;
            break;
        }
    }
}

void TimerManager::removeTimer(String timerName) {
    for (int i = 0; i < timerCount; i++) {
        if (timers[i].name == timerName) {
            for (int j = i; j < timerCount - 1; j++) {
                timers[j] = timers[j + 1];
            }
            timerCount--;
            break;
        }
    }
}