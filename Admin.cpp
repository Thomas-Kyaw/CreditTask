#include "Admin.h"
class Room;
#include "Building.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <list>
#include "Globals.h"
#include "ComputerLab.h"
#include "MeetingRoom.h"
#include "Classroom.h"

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
        //std::cout << "Building added to Admin: " << buildingCode << "\n";
    } else {
        std::cout << "Building already exists in Admin: " << buildingCode << "\n";
    }
}

void Admin::addRoom(const std::string& buildingCode, const std::string& roomNumber, int capacity) {

    std::cout << "Select room type (1: Classroom, 2: Computer Lab, 3: Meeting Room): ";
    int roomType;
    std::cin >> roomType;

    std::shared_ptr<Building> building = getBuilding(buildingCode);
    if (!building) {
        std::cout << "Building not found.\n";
        return;
    }

    switch (roomType) {
        case 1: { // Classroom
            std::cout << "Enter Classroom type (1: LectureRoom, 2: TutorialRoom): ";
            int type;
            std::cin >> type;
            ClassroomType classroomType = (type == 1) ? ClassroomType::LectureRoom : ClassroomType::TutorialRoom;
            auto newRoom = std::make_shared<Classroom>(building, roomNumber, capacity, classroomType);
            building->addRoom(roomNumber, capacity);
            break;
        }
        case 2: { // Computer Lab
            std::cin.ignore(); // Clear the buffer
            std::cout << "Enter operating system: ";
            std::string operatingSystem;
            std::getline(std::cin, operatingSystem);

            std::cout << "Enter software installed (comma-separated): ";
            std::string softwareList;
            std::getline(std::cin, softwareList);
            std::list<std::string> softwareInstalled; // Parse softwareList into this list

            std::cout << "Does it have a printing facility? (1 for Yes, 0 for No): ";
            bool hasPrintingFacility;
            std::cin >> hasPrintingFacility;

            auto newRoom = std::make_shared<ComputerLab>(building, roomNumber, capacity, operatingSystem, softwareInstalled, hasPrintingFacility);
            building->addRoom(roomNumber, capacity);
            break;
        }
        case 3: { // Meeting Room
            std::cin.ignore(); // Clear the buffer
            std::cout << "Does it have conference call equipment? (1 for Yes, 0 for No): ";
            bool hasConferenceCallEquipment;
            std::cin >> hasConferenceCallEquipment;

            std::cout << "Does it have a whiteboard? (1 for Yes, 0 for No): ";
            bool hasWhiteboard;
            std::cin >> hasWhiteboard;

            std::cin.ignore(); // Clear the buffer
            std::cout << "Enter seating arrangement: ";
            std::string seatingArrangement;
            std::getline(std::cin, seatingArrangement);

            auto newRoom = std::make_shared<MeetingRoom>(building, roomNumber, capacity, hasConferenceCallEquipment, hasWhiteboard);
            building->addRoom(roomNumber, capacity);
            break;
        }
        default:
            std::cout << "Invalid room type selected.\n";
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
        if (!room) {
            std::cout << "Room not found." << std::endl;
            return;
        }

        // Temporarily remove the pending booking from the room for availability check
        room->removeBooking(booking);

        // Check availability
        if (room->isAvailable(booking->getBookingDate(), booking->getStartTime(), booking->getEndTime())) {
            booking->setStatus(BookingStatus::APPROVED);
            std::cout << "Booking " << bookingID << " approved." << std::endl;
        } else {
            std::cout << "Room is not available at the requested date and time." << std::endl;
        }

        // Add the booking back to the room
        room->addBooking(booking);
    } else {
        std::cout << "Booking ID not found or not pending." << std::endl;
    }
}

void Admin::rejectBooking(const std::string& bookingID) {
    auto booking = findBooking(bookingID);
    if (booking) {
        booking->setStatus(BookingStatus::REJECTED);
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


