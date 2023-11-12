//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ROOM_H
#define ROOM_H

#include "Booking.h"
#include <vector>
#include <string>

// Forward declaration to avoid circular dependency
class Building;

class Room {
private:
    Building* building; // Pointer to the Building this Room belongs to
    int capacity;
    std::string roomNumber;
    std::vector<Booking*> bookings; // Stores pointers to bookings

public:
    Room(Building* bld, const std::string& number, int cap);
    ~Room(); // Destructor to handle cleanup if necessary
    bool isAvailable(float desiredStartTime, float desiredEndTime) const;
    void addBooking(Booking* booking);
    void removeBooking(Booking* booking);
    void notifyBookingsRoomDeletion();
    void setCapacity(int newCapacity);
    int getCapacity() const;
    std::string getRoomNumber() const;
    Building* getBuilding() const; // Getter for the building pointer

    virtual std::string GetDetails() const;
    // Other methods and members as needed
};

#endif // ROOM_H






