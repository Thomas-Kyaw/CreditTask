//
// Created by Aung Khant Kyaw on 2023/11/06.
//

#include "Building.h"
#include <algorithm>

Building::Building(const std::string& code) : buildingCode(code) {}

Building::~Building() {
    for (Room* room : rooms) {
        delete room;
    }
}

void Building::addRoom(const std::string& roomNumber, int capacity) {
    // Implementation to add a room
}

void Building::editRoom(const std::string& roomNumber, int newCapacity) {
    // Implementation to edit a room's details
}

Room* Building::findRoom(const std::string& roomNumber) {
    // Implementation to find a room
    return nullptr; // Replace with actual search logic
}

void Building::deleteRoom(const std::string& roomNumber) {
    // Implementation to delete a room
}

// ... Other method implementations

