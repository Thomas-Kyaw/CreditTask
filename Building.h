//
// Created by Aung Khant Kyaw on 2023/11/06.
//

#ifndef BUILDING_H
#define BUILDING_H

#include "Room.h"
#include <string>
#include <vector>

class Building {
private:
    std::string buildingCode;
    std::vector<Room*> rooms;

public:
    Building(const std::string& code);
    ~Building();
    void addRoom(const std::string& roomNumber, int capacity);
    void editRoom(const std::string& roomNumber, int newCapacity);
    Room* findRoom(const std::string& roomNumber);
    void deleteRoom(const std::string& roomNumber);
    // ... Other methods
};

#endif // BUILDING_H

