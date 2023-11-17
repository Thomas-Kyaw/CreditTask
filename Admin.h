#ifndef ADMIN_H
#define ADMIN_H

#include "User.h" // Include the User base class
#include "Building.h" // Include the Building class
#include "Booking.h" // Include the Booking class
#include <vector> // Include the standard vector library
#include <string> // Include the standard string library
#include <map> // Include the standard map library
#include <memory> // Include the standard memory library for smart pointers

// Admin class derived from User class
class Admin : public User {
private:
    // Map storing building codes and their corresponding Building objects as shared pointers
    std::map<std::string, std::shared_ptr<Building>> buildings;

    // Vector storing pending bookings as shared pointers
    std::vector<std::shared_ptr<Booking>> Bookings;

public:
    // Constructor for Admin, taking name as a parameter
    Admin(const std::string &name);

    // Methods for room management
    void addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity);
    void editRoom(const std::string& buildingCode, const std::string& roomNumber, int newCapacity);
    void deleteRoom(const std::string& buildingCode, const std::string& roomNumber);

    // Methods for booking management
    void approveBooking(const std::string& bookingID);
    void rejectBooking(const std::string& bookingID);

    void addPendingBooking(std::shared_ptr<Booking> booking) {
        Bookings.push_back(booking);
    }

    std::vector<std::shared_ptr<Booking>> getBookings(){
        return  Bookings;
    }

    void addBuilding(std::shared_ptr<Building> building);
    // Method to delete a building
    void deleteBuilding(const std::string& buildingCode);

    // Helper methods
    std::shared_ptr<Building> getBuilding(const std::string& buildingCode); // Retrieve a building based on its code
    Room* findRoom(const std::string& roomNumber); // Find a room based on its number
    std::shared_ptr<Booking> findBooking(const std::string& bookingID); // Find a booking based on its ID
};

#endif // ADMIN_H
