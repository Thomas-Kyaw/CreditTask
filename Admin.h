//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Room.h"
#include "Booking.h"
#include <vector>
#include <string>

class Admin : public User {
private:
    std::vector<Room*> rooms;
    std::vector<Booking*> pendingBookings;

public:
    Admin(const std::string &name);
    ~Admin();

    void addRoom(const std::string& roomNumber, int capacity);
    void editRoom(const std::string& roomNumber, int newCapacity);
    void deleteRoom(const std::string& roomNumber);
    void approveBooking(const std::string& bookingID);
    void rejectBooking(const std::string& bookingID);

    // Helper methods
    Room* findRoom(const std::string& roomNumber);
    Booking* findBooking(const std::string& bookingID);
};

#endif // ADMIN_H



