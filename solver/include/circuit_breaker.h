#ifndef CIRCUIT_BREAKER_H
#define CIRCUIT_BREAKER_H

#include <string>

class CircuitBreaker {
private:
    std::string id;
    bool isClosed;

public:
    CircuitBreaker(const std::string& id, bool isClosed);
    ~CircuitBreaker();

    std::string getId() const;
    bool getStatus() const;
    void setStatus(bool status);
};

#endif // CIRCUIT_BREAKER_H
