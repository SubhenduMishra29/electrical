#ifndef BUS_H
#define BUS_H

struct Bus {
    double voltageMagnitude;
    double voltageAngle;
    double realPowerInjection;
    double reactivePowerInjection;
    bool isSlack;
};

#endif // BUS_H
