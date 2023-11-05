//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ROOM_H
#define ROOM_H

#include "Booking.h"
#include <vector>
#include <string>

class Room {
private:
    std::string roomNumber;
    std::vector<Booking> bookings; // Stores only approved bookings

public:
    Room(const std::string& number);
    bool isAvailable(float desiredStartTime, float desiredEndTime) const;
    void addBooking(const Booking& booking);
    // Other methods and members as needed
};

#endif // ROOM_H


