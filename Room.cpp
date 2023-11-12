//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"
#include "Building.h"
#include <algorithm>

Room::Room(Building* bld, const std::string& number, int cap)
        : building(bld), roomNumber(number), capacity(cap) {
    // Optionally add this room to the building's list of rooms
    if (building) {
        building->addRoom(this);
    }
}

Room::~Room() {
    for (auto& booking : bookings) {
        delete booking;
    }
    bookings.clear();
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
    bookings.push_back(booking);
}

void Room::removeBooking(Booking* booking) {
    bookings.erase(std::remove(bookings.begin(), bookings.end(), booking), bookings.end());
}

// Make sure the getBuilding() definition matches the declaration in Room.h
Building* Room::getBuilding() const {
    return building;
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





