#include "Admin.h"
class Room;
#include "Building.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include "Globals.h"

Admin::Admin(const std::string &nameVal) : User(nameVal) {}

std::shared_ptr<Building> Admin::getBuilding(const std::string& buildingCode) {
    //std::cout << "Accessing building: " << buildingCode << "\n";
    auto it = buildings.find(buildingCode);
    if (it != buildings.end()) {
        //std::cout << "Building found: " << buildingCode << "\n";
        return it->second;
    } else {
        std::cout << "Building not found, creating new: " << buildingCode << "\n";
        auto newBuilding = std::make_shared<Building>(buildingCode);
        buildings[buildingCode] = newBuilding;
        std::cout << "Building created and added: " << buildingCode << "\n";
        return newBuilding;
    }
}

void Admin::addBuilding(std::shared_ptr<Building> building) {
    std::string buildingCode = building->getBuildingCode(); // Assumed getter for building code
    if (buildings.find(buildingCode) == buildings.end()) {
        buildings[buildingCode] = building;
        std::cout << "Building added to Admin: " << buildingCode << "\n";
    } else {
        std::cout << "Building already exists in Admin: " << buildingCode << "\n";
    }
}

void Admin::addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity) {
    std::cout << "Adding room: " << roomNumber << " to building: " << buildingCode << "\n";
    auto buildingIt = buildings.find(buildingCode);
    if (buildingIt != buildings.end()) {
        auto& building = buildingIt->second;
        building->addRoom(roomNumber, capacity);
        std::cout << "Room added: " << roomNumber << "\n";
    } else {
        std::cerr << "Failed to add room. Building with code " << buildingCode << " not found.\n";
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
    std::cout << "Deleting room: " << roomNumber << " from building: " << buildingCode << "\n";
    auto buildingIt = buildings.find(buildingCode);
    if (buildingIt != buildings.end()) {
        auto& building = buildingIt->second;
        auto room = building->findRoom(roomNumber);
        if (room) {
            deletedRooms.insert(room->getUniqueRoomID());
            building->deleteRoom(roomNumber);
            std::cout << "Room deleted: " << roomNumber << "\n";
        } else {
            std::cout << "Room " << roomNumber << " not found in building " << buildingCode << ".\n";
        }
    } else {
        std::cout << "Building " << buildingCode << " not found for deletion.\n";
    }
}

void Admin::approveBooking(const std::string& bookingID) {
    std::cout << "Attempting to approve booking ID: " << bookingID << std::endl;
    auto booking = findBooking(bookingID);
    if (booking && booking->getStatus() == BookingStatus::PENDING) {
        auto room = findRoom(booking->getRoomNumber());
        if (room && room->isAvailable(booking->getBookingDate(), booking->getStartTime(), booking->getEndTime())) {
            booking->setStatus(BookingStatus::APPROVED);
            std::cout << "Booking " << bookingID << " approved." << std::endl;
        } else {
            std::cout << "Room is not available at the requested date and time." << std::endl;
        }
    } else {
        std::cout << "Booking ID not found or not pending." << std::endl;
    }
}

void Admin::rejectBooking(const std::string& bookingID) {
    auto booking = findBooking(bookingID);
    if (booking) {
        booking->setStatus(BookingStatus::REJECTED);
        // Remove from pendingBookings
        Bookings.erase(std::remove(Bookings.begin(), Bookings.end(), booking), Bookings.end());
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
    auto it = std::find_if(Bookings.begin(), Bookings.end(),
                           [&](const std::shared_ptr<Booking>& booking) { return booking->getBookingID() == bookingID; });

    if (it != Bookings.end()) {
        return *it;
    }

    return nullptr; // Return nullptr if booking is not found
}

void Admin::deleteBuilding(const std::string& buildingCode) {
    //std::cout << "Deleting building: " << buildingCode << "\n";
    auto it = buildings.find(buildingCode);
    if (it != buildings.end()) {
        it->second->deleteAllRooms();
        buildings.erase(it);
        std::cout << "Building deleted: " << buildingCode << "\n";
    } else {
        std::cout << "Building " << buildingCode << " not found for deletion.\n";
    }
}


