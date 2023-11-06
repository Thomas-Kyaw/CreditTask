//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Admin.h"
#include <iostream>
#include <algorithm>

Admin::Admin(const std::string &nameVal) : User(nameVal) {}

Admin::~Admin() {
    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    for (auto booking : pendingBookings) {
        delete booking;
    }
    pendingBookings.clear();
}

void Admin::addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity) {
    // Implementation to add a room to a building
}

void Admin::editRoom(const std::string& buildingCode, const std::string& roomNumber, int newCapacity) {
    // Implementation to edit a room's details
}

void Admin::deleteRoom(const std::string& buildingCode, const std::string& roomNumber) {
    // Implementation to delete a room from a building
}

void Admin::approveBooking(const std::string& bookingID) {
    auto it = std::find_if(pendingBookings.begin(), pendingBookings.end(),
                           [&](const Booking* booking) { return booking->getBookingID() == bookingID; });

    if (it != pendingBookings.end() && (*it)->getStatus() == BookingStatus::PENDING) {
        Room* room = findRoom((*it)->getRoomNumber()); // Assuming a method to find a room by number
        if (room && room->isAvailable((*it)->getStartTime(), (*it)->getEndTime())) {
            (*it)->setStatus(BookingStatus::APPROVED);
            room->addBooking(*it); // Assuming Room class has an addBooking method
        } else {
            std::cout << "Cannot approve booking: Room is not available at the requested time." << std::endl;
        }
    } else {
        std::cout << "Booking ID not found or not pending." << std::endl;
    }
}

void Admin::rejectBooking(const std::string& bookingID) {
    auto it = std::find_if(pendingBookings.begin(), pendingBookings.end(),
                           [&](const Booking* booking) { return booking->getBookingID() == bookingID; });

    if (it != pendingBookings.end()) {
        (*it)->setStatus(BookingStatus::REJECTED);
        std::cout << "Booking with ID " << bookingID << " has been rejected." << std::endl;
    } else {
        std::cout << "Booking with ID " << bookingID << " not found." << std::endl;
    }
}

Room* Admin::findRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });

    if (it != rooms.end()) {
        return *it;
    }

    return nullptr; // Return nullptr if room is not found
}

Booking* Admin::findBooking(const std::string& bookingID) {
    auto it = std::find_if(pendingBookings.begin(), pendingBookings.end(),
                           [&](const Booking* booking) { return booking->getBookingID() == bookingID; });

    if (it != pendingBookings.end()) {
        return *it;
    }

    return nullptr; // Return nullptr if booking is not found
}

