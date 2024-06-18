// Generator.h
#ifndef GENERATOR_H
#define GENERATOR_H

class Generator {
public:
    double activePower;
    double reactivePower;

    Generator(double activePower, double reactivePower)
        : activePower(activePower), reactivePower(reactivePower) {}
};

#endif // GENERATOR_H
