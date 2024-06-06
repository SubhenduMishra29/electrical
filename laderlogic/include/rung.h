/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of Rung class for representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_H
#define RUNG_H

#include <memory>
#include <unordered_map>
#include <vector>
#include "rung_element.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"

class Rung {
private:
    std::vector<std::shared_ptr<RungElement>> elements;

public:
    void addElement(std::shared_ptr<RungElement> element);
    bool evaluate(std::unordered_map<std::string, bool>& states);
    std::vector<std::shared_ptr<RungElement>>& getElements();
};

#endif // RUNG_H
