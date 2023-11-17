#include "Building.h"
#include "Room.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <memory>
#include "Globals.h"

Building::Building(const std::string& code) : buildingCode(code) {

}

void Building::addRoom(std::shared_ptr<Room> room) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::shared_ptr<Room>& existingRoom) {
        return existingRoom->getRoomNumber() == room->getRoomNumber();
    });
    if (it == rooms.end()) {
        rooms.push_back(room);
    } else {
        throw std::runtime_error("Room already exists.");
    }
}

void Building::editRoom(const std::string& roomNumber, int newCapacity) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::shared_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        (*it)->setCapacity(newCapacity);
    } else {
        throw std::runtime_error("Room not found.");
    }
}

Room* Building::findRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::shared_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        return it->get(); // Return the raw pointer managed by shared_ptr
    }
    return nullptr; // Room not found
}

void Building::deleteRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::shared_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        deletedRooms.insert((*it)->getUniqueRoomID());
        rooms.erase(it);
        std::cout << "Room " << roomNumber << " deleted from building " << buildingCode << "." << std::endl;
    } else {
        std::cout << "Room " << roomNumber << " not found in building " << buildingCode << "." << std::endl;
    }
}

/*std::shared_ptr<Room> Building::getRoomSharedPtr(const std::string& roomNumber) {
    for (auto& room : rooms) {
        if (room->getRoomNumber() == roomNumber) {
            return room; // Assuming 'rooms' is now a vector of shared_ptr<Room>
        }
    }
    return nullptr; // If room not found
}*/

std::shared_ptr<Room> Building::getRoomSharedPtr(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const std::shared_ptr<Room>& room) {
        return room->getRoomNumber() == roomNumber;
    });
    if (it != rooms.end()) {
        return *it; // Directly return the shared_ptr
    }
    return nullptr;
}

size_t Building::getRoomCount() const {
    return rooms.size(); // Assuming 'rooms' is the container holding the rooms
}

void Building::deleteAllRooms() {
    for (const auto& room : rooms) {
        deletedRooms.insert(room->getUniqueRoomID());
    }
    rooms.clear();
    std::cout << "All rooms deleted lmfao" << std::endl;
}

std::vector<Room*> Building::getAllRooms() const {
    std::vector<Room*> allRooms;
    for (const auto& room : rooms) {
        allRooms.push_back(room.get());
    }
    return allRooms;
}
// ... Other method implementations as needed
