//
// Created by Aung Khant Kyaw on 2023/11/04.
//

// ComputerLab.cpp
#include "ComputerLab.h"

ComputerLab::ComputerLab(Building* bld, const std::string& num, int cap, const std::string& os, const std::list<std::string>& software, bool printingFacility)
        : Room(bld, num, cap), operatingSystem(os), softwareInstalled(software), hasPrintingFacility(printingFacility) {
    // Additional initialization for ComputerLab if needed
}

std::string ComputerLab::GetDetails() const {
    std::string details = Room::GetDetails();
    details += "Type: Computer Lab\n";
    details += "Operating System: " + operatingSystem + "\n";
    details += "Printing Facility: " + std::string(hasPrintingFacility ? "Yes" : "No") + "\n";
    details += "Software Installed: ";
    for (const auto& software : softwareInstalled) {
        details += software + ", ";
    }
    if (!softwareInstalled.empty()) {
        details.pop_back(); // Remove the last comma
        details.pop_back(); // Remove the last space
    }
    details += "\n";
    return details;
}



