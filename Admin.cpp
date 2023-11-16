#include "Admin.h"
#include "Room.h"
#include "Building.h"
#include <iostream>
#include <algorithm>
#include <memory>

Admin::Admin(const std::string &nameVal) : User(nameVal) {}

std::shared_ptr<Building> Admin::getBuilding(const std::string& buildingCode) {
    auto it = buildings.find(buildingCode);
    if (it != buildings.end()) {
        return it->second;
    } else {
        auto newBuilding = std::make_shared<Building>(buildingCode);
        buildings[buildingCode] = newBuilding;
        return newBuilding;
    }
}

void Admin::addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity) {
    auto buildingIt = buildings.find(buildingCode);
    if (buildingIt != buildings.end()) {
        auto& building = buildingIt->second;
        building->addRoom(roomNumber, capacity); // Assuming addRoom in Building takes roomNumber and capacity
    } else {
        // Handle the case where the building does not exist
        std::cerr << "Building with code " << buildingCode << " not found." << std::endl;
    }
}

void Admin::editRoom(const std::string& buildingCode, const std::string& roomNumber, int newCapacity) {
    auto building = getBuilding(buildingCode);
    Room* room = building->findRoom(roomNumber);
    if (room) {
        room->setCapacity(newCapacity);
    } else {
        std::cout << "Room not found." << std::endl;
    }
}

void Admin::deleteRoom(const std::string& buildingCode, const std::string& roomNumber) {
    auto building = buildings.find(buildingCode);
    if (building != buildings.end()) {
        auto room = building->second->findRoom(roomNumber);
        if (room) {
            room->notifyBookingsRoomDeletion();
        }
        building->second->deleteRoom(roomNumber);

        // Debugging: Check if the room still exists after deletion
        room = building->second->findRoom(roomNumber);
        if (room) {
            std::cout << "Room " << roomNumber << " still exists in building " << buildingCode << "." << std::endl;
        } else {
            std::cout << "Room " << roomNumber << " successfully deleted from building " << buildingCode << "." << std::endl;
        }
    } else {
        std::cout << "Building " << buildingCode << " not found." << std::endl;
    }
}

void Admin::approveBooking(const std::string& bookingID) {
    std::cout << "Attempting to approve booking ID: " << bookingID << std::endl;
    auto booking = findBooking(bookingID);
    if (booking && booking->getStatus() == BookingStatus::PENDING) {
        // Temporarily comment out the room availability check for debugging
        // auto room = findRoom(booking->getRoomNumber());
        // if (room && room->isAvailable(booking->getStartTime(), booking->getEndTime())) {
        booking->setStatus(BookingStatus::APPROVED);
        std::cout << "Booking " << bookingID << " approved." << std::endl;
        // ...
    } else {
        std::cout << "Booking ID not found or not pending." << std::endl;
    }
}


void Admin::rejectBooking(const std::string& bookingID) {
    auto booking = findBooking(bookingID);
    if (booking) {
        booking->setStatus(BookingStatus::REJECTED);
        // Remove from pendingBookings
        pendingBookings.erase(std::remove(pendingBookings.begin(), pendingBookings.end(), booking), pendingBookings.end());
        std::cout << "Booking with ID " << bookingID << " has been rejected." << std::endl;
    } else {
        std::cout << "Booking with ID " << bookingID << " not found." << std::endl;
    }
}

Room* Admin::findRoom(const std::string& roomNumber) {
    for (auto& buildingPair : buildings) {
        Room* room = buildingPair.second->findRoom(roomNumber);
        if (room) {
            return room;
        }
    }
    return nullptr; // Return nullptr if room is not found
}


std::shared_ptr<Booking> Admin::findBooking(const std::string& bookingID) {
    auto it = std::find_if(pendingBookings.begin(), pendingBookings.end(),
                           [&](const std::shared_ptr<Booking>& booking) { return booking->getBookingID() == bookingID; });

    if (it != pendingBookings.end()) {
        return *it;
    }

    return nullptr; // Return nullptr if booking is not found
}

void Admin::deleteBuilding(const std::string& buildingCode) {
    auto it = buildings.find(buildingCode);
    if (it != buildings.end()) {
        buildings.erase(it);
        std::cout << "Building " << buildingCode << " has been deleted." << std::endl;
    } else {
        std::cout << "Building " << buildingCode << " not found." << std::endl;
    }
}

