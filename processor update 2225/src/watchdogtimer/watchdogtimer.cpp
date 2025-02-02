#include "watchdogtimer.h"
#include <iostream>

void WatchdogTimer::enable(Timeout timeout) {
    std::cout << "Watchdog Timer enabled with timeout: " << static_cast<int>(timeout) << "\n";
    // Implementation for enabling the Watchdog Timer with the specified timeout
}

void WatchdogTimer::disable() {
    std::cout << "Watchdog Timer disabled\n";
    // Implementation for disabling the Watchdog Timer
}
