//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"
#include "Building.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>
#include "Globals.h"

Room::Room(std::shared_ptr<Building> buildingPtr, const std::string& roomNumber, int capacity)
        : building(buildingPtr), roomNumber(roomNumber), capacity(capacity) {
    // ... constructor implementation
    uniqueRoomID = generateRoomID();
}

unsigned int Room::getUniqueRoomID() const {
    return uniqueRoomID;
}

Room::~Room() {
    /*for (auto& booking : bookings) {
        delete booking;
    }
    bookings.clear();*/
}

bool Room::isAvailable(const std::string& desiredDate, float desiredStartTime, float desiredEndTime) const {
    std::cout << "Checking availability for Date: " << desiredDate << ", Time: " << desiredStartTime << " - " << desiredEndTime << "\n";
    for (const auto& booking : bookings) {
        std::cout << "Existing Booking - Date: " << booking->getBookingDate() << ", Time: " << booking->getStartTime() << " - " << booking->getEndTime() << "\n";
        if (booking->getBookingDate() == desiredDate &&
            !(desiredEndTime <= booking->getStartTime() || desiredStartTime >= booking->getEndTime())) {
            std::cout << "Booking overlaps. Room not available.\n";
            return false; // Booking overlaps on the same date
        }
    }
    std::cout << "Room is available.\n";
    return true; // No overlapping bookings on the desired date
}

void Room::addBooking(std::shared_ptr<Booking> booking) {
    auto self = shared_from_this();
    bookings.push_back(booking);
}

void Room::removeBooking(std::shared_ptr<Booking> booking) {
    bookings.erase(std::remove_if(bookings.begin(), bookings.end(),
                                  [booking](const std::shared_ptr<Booking>& b) { return b == booking; }), bookings.end());
}

void Room::notifyBookingsRoomDeletion() {
    for (auto& booking : bookings) {
        booking->markInvalid(); // Add a method in Booking to mark it as invalid
    }
}

Building* Room::getBuilding() const {
    auto sharedBuilding = building.lock(); // Lock the weak_ptr to get a shared_ptr
    if (sharedBuilding) {
        return sharedBuilding.get(); // Return the raw pointer
    } else {
        return nullptr; // Return nullptr if the Building no longer exists
    }
}

void Room::setCapacity(int newCapacity) {
    capacity = newCapacity;
}

int Room::getCapacity() const {
    return capacity;
}

std::string Room::getRoomNumber() const {
    return roomNumber;
}

std::string Room::GetDetails() const {
    std::string details = "Room Number: " + roomNumber + "\n";
    details += "Capacity: " + std::to_string(capacity) + "\n";
    // Add more details if necessary
    return details;
}
// Other methods
