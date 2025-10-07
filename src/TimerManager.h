#ifndef TIMER_MANAGER_H
#define TIMER_MANAGER_H

#include <Arduino.h>

class TimerManager {
private:
    static const int MAX_TIMERS = 10;
    
    struct Timer {
        String name;
        unsigned long interval;
        unsigned long lastTrigger;
        bool repeating;
        bool active;
    };
    
    Timer timers[MAX_TIMERS];
    int timerCount;
    
public:
    TimerManager();
    
    bool createTimer(String timerName, unsigned long interval, bool repeat = false);
    void updateTimers();
    bool isTimerTriggered(String timerName);
    void resetTimer(String timerName);
    void removeTimer(String timerName);
};

#endif