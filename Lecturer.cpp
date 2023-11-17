#include "Lecturer.h"
#include "Booking.h"
#include "Building.h"
#include "Globals.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include "Globals.h"

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

bool Lecturer::bookRoom(Room* room, Subject* subject, const std::string& date, float startTime, float endTime) {
    std::cout << "Attempting to book - Date: " << date << ", Time: " << startTime << " - " << endTime << "\n";
    // Check if the room has been deleted
    auto search = deletedRooms.find(room->getUniqueRoomID());
    if (search != deletedRooms.end()) {
        //std::cout << "Cannot book. The room has been deleted. Room ID: " << room->getUniqueRoomID() << "\n";
        return false;
    } else {
        //std::cout << "Room ID " << room->getUniqueRoomID() << " not found in deleted rooms.\n";
    }

    // Check if the room is available for the requested time slot
    if (room->isAvailable(date, startTime, endTime)) {
        // Create a new booking
        auto roomSharedPtr = room->getSharedPtr();
        if (!roomSharedPtr) {
            return false;
        }

        auto newBooking = std::make_shared<Booking>(generateBookingID(), room->getRoomNumber(), date, startTime, endTime, this, subject, roomSharedPtr);
        roomSharedPtr->addBooking(newBooking); // Add booking to the room
        bookings.push_back(newBooking); // Add booking to lecturer's list of bookings
        globalAdmin.addPendingBooking(newBooking); // Add booking to admin's pending bookings
        return true;
    } else {
        //std::cout << "Room is not available for the requested time slot. Room ID: " << room->getUniqueRoomID() << std::endl;
        return false;
    }
}

bool Lecturer::cancelBooking(const std::string& bookingID) {
    auto it = std::find_if(bookings.begin(), bookings.end(), [&](const std::shared_ptr<Booking>& booking) {
        return booking->getBookingID() == bookingID;
    });

    if (it != bookings.end()) {
        // Mark the booking as invalid before removing it
        (*it)->markInvalid();

        // Remove the booking from the room's booking list
        (*it)->getRoom()->removeBooking(*it); // Pass the shared_ptr directly

        // Erase the booking from the lecturer's list of bookings
        bookings.erase(it);
        return true;
    } else {
        //std::cout << "Booking with ID " << bookingID << " not found." << std::endl;
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
std::string Lecturer::GetDetails() const {
    std::stringstream details;
    details << User::GetDetails() << "\nTeaching Subjects:\n";
    for (const auto& subj : subjects) {
        details << "- " << subj->getCode() << "\n";
    }
    return details.str();
}
