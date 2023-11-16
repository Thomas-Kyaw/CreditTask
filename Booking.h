//
// Created by Aung Khant Kyaw on 2023/11/05.
//

#ifndef BOOKING_H
#define BOOKING_H

#include <string> // Include standard string library
#include "Subject.h" // Include the Subject class definition
class Lecturer; // Forward declaration of the Lecturer class
class Room; // Forward declaration of the Room class
enum class BookingStatus { PENDING, APPROVED, REJECTED }; // Enumeration for booking statuses

class Booking {
private:
    std::string bookingID; // Unique identifier for the booking
    std::string roomNumber; // Number of the room booked
    BookingStatus status; // Current status of the booking
    float startTime; // Start time of the booking
    float endTime; // End time of the booking
    Lecturer* lecturer; // Pointer to the Lecturer who made the booking
    Subject* subject; // Pointer to the Subject for which the room was booked
    std::weak_ptr<Room> room; // Weak pointer to the Room that is booked
    bool isValid; // Flag to indicate if the booking is valid

public:
    // Constructor
    Booking(const std::string& id, const std::string& roomNum, float start, float end, Lecturer* lec, Subject* subj, std::shared_ptr<Room> rm);

    // Update booking when room is deleted
    void updateOnRoomDeletion();

    // Accessors
    // Get the booking ID
    std::string getBookingID() const { return bookingID; }
    // Get the room number of the booking
    std::string getRoomNumber() const { return roomNumber; }
    // Get the status of the booking
    BookingStatus getStatus() const { return status; }
    // Get the start time of the booking
    float getStartTime() const { return startTime; }
    // Get the end time of the booking
    float getEndTime() const { return endTime; }
    // Get the lecturer associated with the booking
    Lecturer* getLecturer() const { return lecturer; }
    // Get the subject associated with the booking
    Subject* getSubject() const { return subject; }
    // Get the room associated with the booking
    Room* getRoom() const { return room.lock().get(); }

    // Mutators
    // Set a new status for the booking
    void setStatus(BookingStatus newStatus) { status = newStatus; }

    // Other methods and members as needed
    // Get detailed information about the booking
    std::string getDetails() const;
    std::string bookingStatusToString(BookingStatus status) const;
    // Mark the booking as invalid
    void markInvalid() {
        isValid = false;
    }
};

#endif // BOOKING_H
