/*
 * File: Contactor.h
 * Author: Subhendu Mishra
 * Description: Definition of the Contactor class representing an electrical contactor.
 * License: GPL
 */

#ifndef CONTACTOR_H
#define CONTACTOR_H

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Class representing an electrical contactor.
 */
class Contactor {
private:
    std::string manufacturer; /**< Manufacturer of the contactor */
    std::string model; /**< Model of the contactor */
    std::string type; /**< Type of the contactor (e.g., 3RT20, 3RT10, 3RT20 NEMA) */
    std::string size; /**< Size of the contactor (e.g., S00, S0, S1, NEMA size 0) */
    std::string connectionType; /**< Type of connections (screw, spring, ring lug, etc.) */
    bool supportsAC; /**< Indicates whether AC operation is supported */
    bool supportsDC; /**< Indicates whether DC operation is supported */
    std::vector<std::string> accessories; /**< List of available accessories */
    std::vector<std::string> spareParts; /**< List of available spare parts */

public:
    /**
     * @brief Constructor.
     * @param manuf Manufacturer of the contactor.
     * @param mdl Model of the contactor.
     * @param typ Type of the contactor.
     * @param sz Size of the contactor.
     * @param connType Type of connections.
     * @param ac Indicates whether AC operation is supported.
     * @param dc Indicates whether DC operation is supported.
     */
    Contactor(const std::string& manuf, const std::string& mdl, const std::string& typ, const std::string& sz,
              const std::string& connType, bool ac, bool dc)
        : manufacturer(manuf), model(mdl), type(typ), size(sz), connectionType(connType),
          supportsAC(ac), supportsDC(dc) {}

    /**
     * @brief Method to add an accessory.
     * @param accessory The accessory to add.
     */
    void addAccessory(const std::string& accessory) {
        accessories.push_back(accessory);
    }

    /**
     * @brief Method to add a spare part.
     * @param part The spare part to add.
     */
    void addSparePart(const std::string& part) {
        spareParts.push_back(part);
    }

    /**
     * @brief Method to print contactor details.
     */
    void printDetails() const {
        std::cout << "Contactor Details:\n"
                  << "Manufacturer: " << manufacturer << "\n"
                  << "Model: " << model << "\n"
                  << "Type: " << type << "\n"
                  << "Size: " << size << "\n"
                  << "Connection Type: " << connectionType << "\n"
                  << "AC Operation: " << (supportsAC ? "Supported" : "Not Supported") << "\n"
                  << "DC Operation: " << (supportsDC ? "Supported" : "Not Supported") << "\n"
                  << "Accessories:\n";
        for (const auto& accessory : accessories) {
            std::cout << " - " << accessory << "\n";
        }
        std::cout << "Spare Parts:\n";
        for (const auto& part : spareParts) {
            std::cout << " - " << part << "\n";
        }
        // Print more details as needed
    }
};

#endif // CONTACTOR_H
