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
    // Check if room already exists
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });

    if (it != rooms.end()) {
        std::cout << "Room " << roomNumber << " already exists." << std::endl;
        return;
    }

    // If room does not exist, create and add to the list
    Room* newRoom = new Room(roomNumber, capacity);
    rooms.push_back(newRoom);
    std::cout << "Room " << roomNumber << " added with capacity " << capacity << "." << std::endl;
}

void Admin::editRoom(const std::string& roomNumber, int newCapacity) {
    // Find the room
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });

    if (it == rooms.end()) {
        std::cout << "Room " << roomNumber << " not found." << std::endl;
        return;
    }

    // Edit the room's capacity
    (*it)->setCapacity(newCapacity);
    std::cout << "Room " << roomNumber << " capacity changed to " << newCapacity << "." << std::endl;
}

void Admin::deleteRoom(const std::string& roomNumber) {
    // Find the room
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room* room) {
        return room->getRoomNumber() == roomNumber;
    });

    if (it == rooms.end()) {
        std::cout << "Room " << roomNumber << " not found." << std::endl;
        return;
    }
    // Delete the room
    delete *it;
    rooms.erase(it);
    std::cout << "Room " << roomNumber << " has been deleted." << std::endl;
}

void Admin::approveBooking(const std::string& bookingID) {
    auto it = std::find_if(pendingBookings.begin(), pendingBookings.end(),
                           [&](const Booking* booking) { return booking->getBookingID() == bookingID; });

    if (it != pendingBookings.end() && (*it)->getStatus() == BookingStatus::PENDING) {
        Room* room = findRoom((*it)->getRoomNumber()); // Assuming a method to find a room by number
        if (room && room->isAvailable((*it)->getStartTime(), (*it)->getEndTime())) {
            (*it)->setStatus(BookingStatus::APPROVED);
            room->addBooking(**it); // Assuming Room class has an addBooking method
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

