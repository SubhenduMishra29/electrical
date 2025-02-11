#ifndef WATCHDOGTIMER_H
#define WATCHDOGTIMER_H

class WatchdogTimer {
public:
    enum class Timeout {
        Timeout_16ms,
        Timeout_32ms,
        Timeout_64ms,
        Timeout_125ms,
        Timeout_250ms,
        Timeout_500ms,
        Timeout_1s,
        Timeout_2s,
        Timeout_4s,
        Timeout_8s
    };

    void enable(Timeout timeout);
    void disable();
    
    // Other Watchdog Timer related methods
};

#endif // WATCHDOGTIMER_H
