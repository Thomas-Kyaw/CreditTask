#include "Building.h"
#include <algorithm>
#include <stdexcept>

Building::Building(const std::string& code) : buildingCode(code) {}

void Building::addRoom(std::unique_ptr<Room> room) {
    // Check if the room already exists and add it to the list
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::unique_ptr<Room>& existingRoom) {
        return existingRoom->getRoomNumber() == room->getRoomNumber();
    });
    if (it == rooms.end()) {
        rooms.push_back(std::move(room)); // Use std::move to transfer ownership
    }
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
