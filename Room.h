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
    int capacity;
    std::string roomNumber;
    std::vector<Booking*> bookings; // Stores pointers to bookings

public:
    Room(const std::string& number, int cap);
    bool isAvailable(float desiredStartTime, float desiredEndTime) const;
    void addBooking(Booking* booking); // Changed to take a pointer
    void removeBooking(Booking* booking); // Method to remove a booking
    void setCapacity(int newCapacity) { capacity = newCapacity; }
    int getCapacity() const { return capacity; }
    std::string getRoomNumber() const { return roomNumber; }
    // Other methods and members as needed
};

#endif // ROOM_H





