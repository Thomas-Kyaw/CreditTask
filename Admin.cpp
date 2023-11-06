//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Admin.h"
#include "Room.h"
#include "Building.h"
#include <iostream>
#include <algorithm>

Admin::Admin(const std::string &nameVal) : User(nameVal) {}

Admin::~Admin() {
    for (auto &pair : buildings) {
        delete pair.second;
    }
    buildings.clear();

    for (auto booking : pendingBookings) {
        delete booking;
    }
    pendingBookings.clear();
}

Building* Admin::getBuilding(const std::string& buildingCode) {
    auto it = buildings.find(buildingCode);
    if (it != buildings.end()) {
        return it->second;
    } else {
        // If the building doesn't exist, create it and add to the map
        Building* newBuilding = new Building(buildingCode);
        buildings[buildingCode] = newBuilding;
        return newBuilding;
    }
}

void Admin::addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity) {
    Building* building = getBuilding(buildingCode);
    building->addRoom(roomNumber, capacity);
}

void Admin::editRoom(const std::string& buildingCode, const std::string& roomNumber, int newCapacity) {
    Building* building = getBuilding(buildingCode);
    Room* room = building->findRoom(roomNumber);
    if (room) {
        room->setCapacity(newCapacity);
    } else {
        std::cout << "Room not found." << std::endl;
    }
}

void Admin::deleteRoom(const std::string& buildingCode, const std::string& roomNumber) {
    Building* building = getBuilding(buildingCode);
    building->deleteRoom(roomNumber);
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
    for (auto& buildingPair : buildings) {
        Building* building = buildingPair.second;
        Room* room = building->findRoom(roomNumber);
        if (room) {
            return room;
        }
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

