//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"
#include "Building.h"
#include <algorithm>

// Make sure the constructor definition matches the declaration in Room.h
Room::Room(const std::string& number, int cap, Building* bldg)
        : roomNumber(number), capacity(cap), building(bldg) {
    // Constructor implementation
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
// Other methods





