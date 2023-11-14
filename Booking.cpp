//
// Created by Aung Khant Kyaw on 2023/11/05.
//

// Booking.cpp

#include "Booking.h"
#include "Lecturer.h"
#include "Room.h"
#include <iostream>
#include <algorithm>
#include <memory>

Booking::Booking(const std::string& id, const std::string& roomNum, float start, float end, Lecturer* lec, Subject* subj, std::shared_ptr<Room> rm)
        : bookingID(id), roomNumber(roomNum), status(BookingStatus::PENDING), startTime(start), endTime(end), lecturer(lec), subject(subj), room(rm) {
    // Add this booking to the room's booking list
    auto roomPtr = room.lock();
    if (roomPtr) {
        roomPtr->addBooking(this);
    }
}

void Booking::updateOnRoomDeletion() {
    room.reset();
    // Additional shit goes here
}

std::string Booking::getDetails() const {
    auto roomSharedPtr = room.lock(); // Attempt to lock the weak pointer
    if (roomSharedPtr) {
        // Room is valid, proceed with accessing its details
        std::string details = "Booking Details:\n";
        details += "Room: " + roomNumber + "\n";
        details += "Time: " + std::to_string(startTime) + " - " + std::to_string(endTime) + "\n";
        details += "Lecturer: " + lecturer->getName() + "\n";
        details += "Subject: " + subject->getDetails() + "\n";
        return details;
    } else {
        // Room is no longer valid
        return "Booking details not available (room deleted or inaccessible).";
    }
}


