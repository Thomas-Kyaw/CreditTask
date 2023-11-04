//
// Created by Aung Khant Kyaw on 2023/11/05.
//

#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Room.h"
#include "Lecturer.h"

// Enumeration for booking status
enum class BookingStatus { APPROVED, REJECTED, PENDING };

class Booking {
private:
    std::string bookingID;
    Room* room;
    Lecturer* lecturer;
    BookingStatus status;
    float startTime;
    float endTime;

public:
    Booking(const std::string& id, Room* rm, Lecturer* lec, float start, float end);
    ~Booking();

    bool checkAvailability(float start, float end) const;

    // Accessor and Mutator methods (setters and getters) for each attribute
    std::string getBookingID() const;
    void setBookingID(const std::string& id);

    Room* getRoom() const;
    void setRoom(Room* rm);

    Lecturer* getLecturer() const;
    void setLecturer(Lecturer* lec);

    BookingStatus getStatus() const;
    void setStatus(BookingStatus sts);

    float getStartTime() const;
    void setStartTime(float start);

    float getEndTime() const;
    void setEndTime(float end);

    // Additional methods
    std::string getStatusString() const;
};

#endif // BOOKING_H

