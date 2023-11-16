//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"
#include "Building.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>

Room::Room(std::shared_ptr<Building> buildingPtr, const std::string& roomNumber, int capacity)
        : building(buildingPtr), roomNumber(roomNumber), capacity(capacity) {
    // ... constructor implementation
}

Room::~Room() {
    /*for (auto& booking : bookings) {
        delete booking;
    }
    bookings.clear();*/
}

bool Room::isAvailable(float desiredStartTime, float desiredEndTime) const {
    for (const auto& booking : bookings) {
        if (!(desiredEndTime <= booking->getStartTime() || desiredStartTime >= booking->getEndTime())) {
            return false;
        }
    }
    return true;
}

void Room::addBooking(Booking* booking) {
    bookings.push_back(booking); // Assuming bookings is std::vector<Booking*>
}

void Room::removeBooking(Booking* booking) {
    bookings.erase(std::remove_if(bookings.begin(), bookings.end(),
                                  [booking](const Booking* b) { return b == booking; }), bookings.end());
}

void Room::notifyBookingsRoomDeletion() {
    for (auto& booking : bookings) {
        booking->markInvalid(); // Add a method in Booking to mark it as invalid
    }
}

Building* Room::getBuilding() const {
    auto sharedBuilding = building.lock(); // Lock the weak_ptr to get a shared_ptr
    if (sharedBuilding) {
        return sharedBuilding.get(); // Return the raw pointer
    } else {
        return nullptr; // Return nullptr if the Building no longer exists
    }
}

void Room::setCapacity(int newCapacity) {
    capacity = newCapacity;
}

int Room::getCapacity() const {
    return capacity;
}

std::string Room::getRoomNumber() const {
    return roomNumber;
}

std::string Room::GetDetails() const {
    std::string details = "Room Number: " + roomNumber + "\n";
    details += "Capacity: " + std::to_string(capacity) + "\n";
    // Add more details if necessary
    return details;
}
// Other methods
