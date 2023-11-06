//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"
#include <algorithm>

Room::Room(const std::string& number, int cap) : roomNumber(number), capacity(cap) {
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

// Other methods





