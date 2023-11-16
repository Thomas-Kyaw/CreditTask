//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ROOM_H
#define ROOM_H

#include "Booking.h" // Include the Booking class
#include <vector> // Include the standard vector library
#include <memory> // Include the standard memory library for smart pointers
#include <string> // Include the standard string library

// Forward declaration of Building to avoid circular dependency
class Building;

// Room class definition
class Room : public std::enable_shared_from_this<Room>{
private:
    std::weak_ptr<Building> building; // Weak pointer to the Building to avoid circular references
    int capacity; // Capacity of the room
    std::string roomNumber; // Number of the room
    std::vector<Booking*> bookings; // Vector storing pointers to the bookings made for this room
    //std::weak_ptr<Room> self; // Weak pointer to self, used for shared_ptr management

public:
    // Constructor
    Room(std::shared_ptr<Building> building, const std::string& roomNumber, int capacity);
    // Destructor to handle cleanup
    ~Room();

    // Check if room is available during the desired time
    bool isAvailable(float desiredStartTime, float desiredEndTime) const;
    // Add a booking to this room
    void addBooking(Booking* booking);
    // Remove a booking from this room
    void removeBooking(Booking* booking);
    // Notify all bookings about the room's deletion
    void notifyBookingsRoomDeletion();
    // Set a new capacity for the room
    void setCapacity(int newCapacity);
    // Get the capacity of the room
    int getCapacity() const;
    // Get the room number
    std::string getRoomNumber() const;
    // Getter for the building this room belongs to
    Building* getBuilding() const;

    // Virtual method to get detailed information about the room
    virtual std::string GetDetails() const;

    // Initialize the weak self-pointer with a shared_ptr of this object
    /*void initializeSelf(std::shared_ptr<Room> selfPtr) {
        self = selfPtr;
    }*/

    // Get a shared pointer to this room
    std::shared_ptr<Room> getSharedPtr() {
        return shared_from_this();
    }
    // Other methods and members as needed
};

#endif // ROOM_H
