//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "ComputerLab.h"

ComputerLab::ComputerLab(const std::string& num, int cap, const std::string& os, const std::list<std::string>& software, bool printingFacility)
        : Room(num, cap), operatingSystem(os), softwareInstalled(software), hasPrintingFacility(printingFacility) {}

bool ComputerLab::bookRoom() {

    return false; // Placeholder
}

std::string ComputerLab::getDetails() const {

    return ""; // Placeholder
}

