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

void Admin::addRoom(const std::string& roomNumber, int capacity) {
    // Implementation to add a room
}

void Admin::editRoom(const std::string& roomNumber, int newCapacity) {
    // Implementation to edit a room
}

void Admin::deleteRoom(const std::string& roomNumber) {
    // Implementation to delete a room
}

void Admin::approveBooking(const std::string& bookingID) {
    auto it = std::find_if(pendingBookings.begin(), pendingBookings.end(),
                           [&](const Booking* booking) { return booking->getBookingID() == bookingID; });

    if (it != pendingBookings.end() && (*it)->getStatus() == BookingStatus::PENDING) {
        Room* room = findRoom((*it)->getRoomNumber()); // Assuming a method to find a room by number
        if (room && room->isAvailable((*it)->getStartTime(), (*it)->getEndTime())) {
            (*it)->setStatus(BookingStatus::APPROVED);
            room->addBooking(**it); // Dereference twice to pass the Booking object
        } else {
            std::cout << "Cannot approve booking: Room is not available at the requested time." << std::endl;
        }
    } else {
        std::cout << "Booking ID not found or not pending." << std::endl;
    }
}

void Admin::rejectBooking(const std::string& bookingID) {
    // Implementation to reject a booking
}

Room* Admin::findRoom(const std::string& roomNumber) {
    // Implementation to find a room by its number
}

Booking* Admin::findBooking(const std::string& bookingID) {
    // Implementation to find a booking by its ID
}


