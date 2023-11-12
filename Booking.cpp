//
// Created by Aung Khant Kyaw on 2023/11/05.
//

// Booking.cpp

#include "Booking.h"
#include "Lecturer.h"
#include "Room.h"

Booking::Booking(const std::string& id, const std::string& roomNum, float start, float end, Lecturer* lec, Subject* subj, Room* rm)
        : bookingID(id), roomNumber(roomNum), status(BookingStatus::PENDING), startTime(start), endTime(end), lecturer(lec), subject(subj), room(rm) {
    // Add this booking to the room's booking list
    if (room) {
        room->addBooking(this);
    }
}
