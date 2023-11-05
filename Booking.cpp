//
// Created by Aung Khant Kyaw on 2023/11/05.
//

#include "Booking.h"

Booking::Booking(const std::string& id, const std::string& roomNum, float start, float end, Lecturer* lec, Subject* subj, Room* rm)
        : bookingID(id), roomNumber(roomNum), status(BookingStatus::PENDING), startTime(start), endTime(end), lecturer(lec), subject(subj), room(rm) {
    // Constructor body
}



