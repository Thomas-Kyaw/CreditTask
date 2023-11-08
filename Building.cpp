//
// Created by Aung Khant Kyaw on 2023/11/06.
//

// Building.cpp

// Building.cpp

#include "Building.h"
#include "Room.h"
#include <algorithm>
#include <stdexcept>
#include <memory> // For std::unique_ptr

Building::Building(const std::string& code) : buildingCode(code) {}

Building::~Building() {
    // unique_ptr's will automatically delete the Room objects そうらしい
}

void Building::addRoom(const std::string& roomNumber, int capacity) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::unique_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        throw std::runtime_error("Room already exists.");
    }
    rooms.push_back(std::make_unique<Room>(this, roomNumber, capacity));
}

void Building::editRoom(const std::string& roomNumber, int newCapacity) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::unique_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        (*it)->setCapacity(newCapacity);
    } else {
        throw std::runtime_error("Room not found.");
    }
}

Room* Building::findRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::unique_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        return it->get(); // Return the raw pointer managed by unique_ptr
    }
    return nullptr; // Room not found
}

void Building::deleteRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::unique_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        rooms.erase(it); // unique_ptr will automatically delete the Room object
    } else {
        throw std::runtime_error("Room not found.");
    }
}

// ... Other method implementations as needed

