#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Building.h"
#include "Booking.h"
#include <vector>
#include <string>
#include <map>

class Admin : public User {
private:
    std::map<std::string, Building*> buildings; // Map of building codes to Building pointers
    std::vector<Booking*> pendingBookings;

public:
    Admin(const std::string &name);
    ~Admin();

    void addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity);
    void editRoom(const std::string& buildingCode, const std::string& roomNumber, int newCapacity);
    void deleteRoom(const std::string& buildingCode, const std::string& roomNumber);
    void approveBooking(const std::string& bookingID);
    void rejectBooking(const std::string& bookingID);

    // Helper methods
    Building* getBuilding(const std::string& buildingCode); // Changed to return a pointer
    Room* findRoom(const std::string& roomNumber);
    Booking* findBooking(const std::string& bookingID);
};

#endif // ADMIN_H
