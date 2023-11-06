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
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        throw std::runtime_error("Room already exists.");
    }
    rooms.push_back(new Room(roomNumber, capacity));
}

void Building::editRoom(const std::string& roomNumber, int newCapacity) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        (*it)->setCapacity(newCapacity);
    } else {
        throw std::runtime_error("Room not found.");
    }
}

Room* Building::findRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        return *it;
    }
    return nullptr; // Room not found
}

void Building::deleteRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        delete *it; // Free the memory if you're using raw pointers
        rooms.erase(it);
    } else {
        throw std::runtime_error("Room not found.");
    }
}
// ... Other method implementations

