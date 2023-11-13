#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Building.h"
#include "Booking.h"
#include <vector>
#include <string>
#include <map>
#include <memory>

class Admin : public User {
private:
    std::map<std::string, std::shared_ptr<Building>> buildings; // Map of building codes to shared_ptr of Building
    std::vector<std::shared_ptr<Booking>> pendingBookings; // Changed to vector of shared_ptr of Booking

public:
    Admin(const std::string &name);
    // Removed the destructor as it's not needed with smart pointers

    void addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity);
    void editRoom(const std::string& buildingCode, const std::string& roomNumber, int newCapacity);
    void deleteRoom(const std::string& buildingCode, const std::string& roomNumber);
    void approveBooking(const std::string& bookingID);
    void rejectBooking(const std::string& bookingID);
    void deleteBuilding(const std::string& buildingCode);

    // Helper methods
    std::shared_ptr<Building> getBuilding(const std::string& buildingCode); // Changed to return shared_ptr
    Room* findRoom(const std::string& roomNumber); // Changed to return shared_ptr
    std::shared_ptr<Booking> findBooking(const std::string& bookingID); // Changed to return shared_ptr
};

#endif // ADMIN_H
