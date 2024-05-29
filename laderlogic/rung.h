// rung.h
#ifndef RUNG_H
#define RUNG_H

#include <string>
#include <vector>

class Rung {
private:
    std::vector<std::pair<std::string, bool>> elements;

public:
    Rung();
    void addElement(std::string name, bool state);
    bool evaluate(std::unordered_map<std::string, bool>& input_states);
};

#endif // RUNG_H

