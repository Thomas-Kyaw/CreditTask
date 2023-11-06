//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ROOM_H
#define ROOM_H

// Forward declaration of Building to avoid circular dependency
class Building;

#include "Booking.h"
#include <vector>
#include <string>

class Room {
private:
    int capacity;
    std::string roomNumber;
    Building* building; // Pointer to the Building this room belongs to
    std::vector<Booking*> bookings; // Stores pointers to bookings

public:
    // Make sure the constructor declaration includes the Building* parameter
    Room(const std::string& number, int cap, Building* building);
    bool isAvailable(float desiredStartTime, float desiredEndTime) const;
    void addBooking(Booking* booking);
    void removeBooking(Booking* booking);
    void setCapacity(int newCapacity);
    int getCapacity() const;
    std::string getRoomNumber() const;
    Building* getBuilding() const; // Method to get the building of the room

    // Other methods and members as needed
};

#endif // ROOM_H






