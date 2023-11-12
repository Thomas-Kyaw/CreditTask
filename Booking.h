//
// Created by Aung Khant Kyaw on 2023/11/05.
//

#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Subject.h"
class Lecturer;
class Room;
enum class BookingStatus { PENDING, APPROVED, REJECTED };

class Booking {
private:
    std::string bookingID;
    std::string roomNumber;
    BookingStatus status;
    float startTime;
    float endTime;
    Lecturer* lecturer; // Pointer to the Lecturer who made the booking
    Subject* subject;   // Pointer to the Subject for which the room was booked
    std::weak_ptr<Room> room;        // Pointer to the Room that is booked

public:
    Booking(const std::string& id, const std::string& roomNum, float start, float end, Lecturer* lec, Subject* subj, std::shared_ptr<Room> rm);
    void updateOnRoomDeletion();
    // Accessors
    std::string getBookingID() const { return bookingID; }
    std::string getRoomNumber() const { return roomNumber; }
    BookingStatus getStatus() const { return status; }
    float getStartTime() const { return startTime; }
    float getEndTime() const { return endTime; }
    Lecturer* getLecturer() const { return lecturer; }
    Subject* getSubject() const { return subject; }
    Room* getRoom() const { return room.lock().get();} // Accessor for the room

    // Mutators
    void setStatus(BookingStatus newStatus) { status = newStatus; }

    // Other methods and members as needed
};

#endif // BOOKING_H




