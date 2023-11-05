//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Lecturer.h"
#include <iostream>
#include <sstream> // For string streams

Lecturer::Lecturer(const std::string &nameVal, const std::string &id, Room* officeRoom)
        : User(nameVal), lecturerID(id), office(officeRoom) {}

Lecturer::~Lecturer() {
    for (auto booking : bookings) {
        delete booking;
    }
}

std::string Lecturer::generateBookingID() {
    static int idCounter = 0; // This will increment with each call
    std::stringstream ss;
    ss << "BKG" << ++idCounter; // Prefix with BKG and append the counter
    return ss.str();
}

bool Lecturer::bookRoom(Room* room, Subject* subject, float startTime, float endTime) {
    if (room->isAvailable(startTime, endTime)) {
        Booking* newBooking = new Booking(generateBookingID(), room->getRoomNumber(), startTime, endTime, this, subject);
        room->addBooking(newBooking);
        bookings.push_back(newBooking);
        return true;
    } else {
        std::cout << "Room is not available for the requested time slot." << std::endl;
        return false;
    }
}

bool Lecturer::cancelBooking(const std::string& bookingID) {
    auto it = std::find_if(bookings.begin(), bookings.end(), [&](const Booking* booking) {
        return booking->getBookingID() == bookingID;
    });

    if (it != bookings.end()) {
        // Assuming Room has a method to remove a booking
        (*it)->getRoom()->removeBooking(*it);
        delete *it;
        bookings.erase(it);
        return true;
    } else {
        std::cout << "Booking with ID " << bookingID << " not found." << std::endl;
        return false;
    }
}

std::vector<Room*> Lecturer::searchRoomsByCapacity(const std::vector<Room*>& allRooms, int requiredCapacity) {
    std::vector<Room*> suitableRooms;
    for (const auto& room : allRooms) {
        if (room->getCapacity() >= requiredCapacity && room->isAvailable()) {
            suitableRooms.push_back(room);
        }
    }
    return suitableRooms;
}


