#ifndef LECTURER_H
#define LECTURER_H

#include "User.h" // Include the User base class
class Room; // Include the Room class
#include "Subject.h" // Include the Subject class
#include "Booking.h" // Include the Booking class
#include "Building.h" // Include the Building class
#include <vector> // Include the standard vector library
#include <string> // Include the standard string library
#include <memory> // Include the standard memory library for smart pointers

// Lecturer class, derived from User
class Lecturer : public User {
private:
    std::string lecturerID; // Unique identifier for the lecturer
    Room* office; // Pointer to the lecturer's office room
    std::vector<Subject*> subjects; // Vector of pointers to subjects taught by the lecturer
    std::vector<std::shared_ptr<Booking>> bookings; // Vector of shared pointers to bookings made by the lecturer


public:
    // Constructor
    Lecturer(const std::string &name, const std::string &id, Room* officeRoom);
    // Destructor
    ~Lecturer();

    // Override GetDetails method
    std::string GetDetails() const override;

    // Method to generate a unique booking ID
    std::string generateBookingID();
    // Method to book a room
    bool bookRoom(Room* room, Subject* subject, const std::string& date, float startTime, float endTime);
    // Method to cancel a booking
    bool cancelBooking(const std::string& bookingID);
    // Method to search for rooms by their capacity
    std::vector<Room*> searchRoomsByCapacity(const std::vector<Room*>& allRooms, int requiredCapacity);
    // Method to get the lecturer's name
    std::string getName() const;

    // Method to get the bookings made by the lecturer
    const std::vector<std::shared_ptr<Booking>>& getBookings() const {
        return bookings;
    }
};

#endif // LECTURER_H
