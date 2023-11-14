#include "Lecturer.h"
#include "Booking.h"
#include "Building.h"
#include <iostream>
#include <algorithm>
#include <sstream>

Lecturer::Lecturer(const std::string &nameVal, const std::string &id, Room* officeRoom)
        : User(nameVal), lecturerID(id), office(officeRoom) {}

Lecturer::~Lecturer() {
    // No need to delete bookings, shared_ptr will handle it
}

std::string Lecturer::generateBookingID() {
    static int idCounter = 0;
    std::stringstream ss;
    ss << "BKG" << ++idCounter;
    return ss.str();
}

bool Lecturer::bookRoom(Room* room, Subject* subject, float startTime, float endTime) {
    if (room->isAvailable(startTime, endTime)) {
        auto roomSharedPtr = room->getSharedPtr();
        if (!roomSharedPtr) {
            std::cerr << "Failed to get shared pointer for room." << std::endl;
            return false;
        }

        auto newBooking = std::make_shared<Booking>(generateBookingID(), room->getRoomNumber(), startTime, endTime, this, subject, roomSharedPtr);
        room->addBooking(newBooking.get()); // Pass the raw pointer
        bookings.push_back(newBooking); // Store the shared_ptr
        return true;
    } else {
        std::cout << "Room is not available for the requested time slot." << std::endl;
        return false;
    }
}

bool Lecturer::cancelBooking(const std::string& bookingID) {
    auto it = std::find_if(bookings.begin(), bookings.end(), [&](const std::shared_ptr<Booking>& booking) {
        return booking->getBookingID() == bookingID;
    });

    if (it != bookings.end()) {
        (*it)->getRoom()->removeBooking(it->get()); // Pass raw pointer to Room
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
        if (room->getCapacity() >= requiredCapacity) {
            suitableRooms.push_back(room);
        }
    }
    return suitableRooms;
}

std::string Lecturer::getName() const {
    return name;
}

