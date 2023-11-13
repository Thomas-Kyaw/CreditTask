//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef COMPUTERLAB_H
#define COMPUTERLAB_H

#include "Room.h"
#include <list>
#include <string>

class ComputerLab : public Room {
    std::string operatingSystem;
    std::list<std::string> softwareInstalled;
    bool hasPrintingFacility;

public:
    ComputerLab(std::shared_ptr<Building> bld, const std::string& num, int cap, const std::string& os, const std::list<std::string>& software, bool printingFacility);
    virtual std::string GetDetails() const override;
};

#endif // COMPUTERLAB_H


