//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"

Room::Room(const std::string& number) : roomNumber(number) {}

bool Room::isAvailable(float desiredStartTime, float desiredEndTime) const {
    for (const auto& booking : bookings) {
        // Check for time overlap
        if (desiredStartTime < booking.getEndTime() && desiredEndTime > booking.getStartTime()) {
            return false; // The room is not available because there is an overlap
        }
    }
    return true; // The room is available
}

void Room::addBooking(const Booking& booking) {
    bookings.push_back(booking);
}


