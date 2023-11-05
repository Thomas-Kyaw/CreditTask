//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"
#include <algorithm>

#include "Room.h"

// Updated constructor implementation
Room::Room(const std::string& number, int cap) : roomNumber(number), capacity(cap) {
    // Constructor body, if there's any initialization to do
}

// ... (Other methods remain unchanged)
bool Room::isAvailable(float desiredStartTime, float desiredEndTime) const {
    // Check if the room is available during the desired time
    for (const auto& booking : bookings) {
        // If the desired time overlaps with any approved booking, the room is not available
        if (!(desiredEndTime <= booking.getStartTime() || desiredStartTime >= booking.getEndTime())) {
            return false;
        }
    }
    return true;
}

void Room::addBooking(const Booking& booking) {
    // Add a booking to the room's list of bookings
    bookings.push_back(booking);
}




