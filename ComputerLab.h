//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef COMPUTERLAB_H
#define COMPUTERLAB_H

#include "Room.h" // Include the Room class definition
#include <list> // Include the standard list library
#include <string> // Include the standard string library

// ComputerLab class, inheriting from Room
class ComputerLab : public Room {
    std::string operatingSystem; // Operating system used in the lab
    std::list<std::string> softwareInstalled; // List of installed software in the lab
    bool hasPrintingFacility; // Flag to indicate if there is a printing facility

public:
    // Constructor
    ComputerLab(std::shared_ptr<Building> bld, const std::string& num, int cap, const std::string& os, const std::list<std::string>& software, bool printingFacility);
    // Override of GetDetails method to provide detailed information about the computer lab
    virtual std::string GetDetails() const override;
};

#endif // COMPUTERLAB_H
