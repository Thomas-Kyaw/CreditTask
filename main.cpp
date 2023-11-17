#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include "Globals.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <limits>

// Forward declarations for functions
void adminActions(Admin& admin, std::vector<std::shared_ptr<Building>>& buildings);
void lecturerActions(Lecturer& lecturer, const std::vector<std::shared_ptr<Building>>& buildings);
Subject subject("CS101", "Computer Science");
Subject subjectq("ECE101", "Electronics Engineering");
void flushCin();

int main() {
    // Initial Setup
    /*std::cout << "Room Booking System\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Lecturer\n";
    std::cout << "Select your role: ";

    int role;
    std::cin >> role;
    flushCin();  // Clear any lingering input*/

    // Predetermined data setup
    std::vector<std::shared_ptr<Building>> buildings;
    for (int i = 1; i <= 6; ++i) {
        auto buildingPtr = std::make_shared<Building>("B" + std::to_string(i));
        globalAdmin.addBuilding(buildingPtr);
        buildingPtr->addRoom("R" + std::to_string(i * 100 + 1), 30 + i * 5);  // Example: R101, R102, ...
        buildings.push_back(buildingPtr);
    }

    Lecturer lecturer("Dr. Smith", "Lec1", nullptr);

    bool exitProgram = false;
    while (!exitProgram) {
        std::cout << "Room Booking System\n";
        std::cout << "1. Admin\n";
        std::cout << "2. Lecturer\n";
        std::cout << "3. Exit\n";
        std::cout << "Select your role: ";

        int role;
        std::cin >> role;
        flushCin();  // Clear any lingering input

        switch (role) {
            case 1:
                adminActions(globalAdmin, buildings);
                break;
            case 2:
                lecturerActions(lecturer, buildings);
                break;
            case 3:
                exitProgram = true;
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid role selected.\n";
                break;
        }
    }
    return 0;
}

void adminActions(Admin& admin, std::vector<std::shared_ptr<Building>>& buildings) {
    // Implement the Admin specific actions here
    int choice;
    do {
        std::cout << "\nAdmin Actions:\n";
        std::cout << "1. Add Room\n";
        std::cout << "2. Edit Room\n";
        std::cout << "3. Delete Room\n";
        std::cout << "4. Approve Booking\n";
        std::cout << "5. Reject Booking\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        flushCin();

        switch (choice) {
            case 1: {
                // Add Room logic
                std::string buildingCode, roomNumber;
                int capacity;
                std::cout << "Enter building code: ";
                std::cin >> buildingCode;
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                std::cout << "Enter room capacity: ";
                std::cin >> capacity;
                admin.addRoom(buildingCode, roomNumber, capacity);
                break;
            }
            case 2: {
                // Edit Room logic
                std::string buildingCode, roomNumber;
                int newCapacity;
                std::cout << "Enter building code: ";
                std::cin >> buildingCode;
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                std::cout << "Enter new room capacity: ";
                std::cin >> newCapacity;
                admin.editRoom(buildingCode, roomNumber, newCapacity);
                break;
            }
            case 3: {

                // Delete Room logic
                std::string buildingCode, roomNumber;
                std::cout << "Enter building code: ";
                std::cin >> buildingCode;
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                admin.deleteRoom(buildingCode, roomNumber);
                break;
            }
            case 4: {
                // Display all pending bookings
                auto Bookings = admin.getBookings();
                std::cout << "Pending Bookings:\n";
                for (const auto& booking : Bookings) {
                    std::cout << booking->getDetails() << std::endl;
                }
                // Approve Booking logic
                std::string bookingID;
                std::cout << "Enter booking ID to approve: ";
                std::cin >> bookingID;
                admin.approveBooking(bookingID);
                break;
            }
            case 5: {
                // Display all pending bookings
                auto Bookings = admin.getBookings();
                std::cout << "Pending Bookings:\n";
                for (const auto& booking : Bookings) {
                    std::cout << booking->getDetails() << std::endl;
                }
                // Reject Booking logic
                std::string bookingID;
                std::cout << "Enter booking ID to reject: ";
                std::cin >> bookingID;
                admin.rejectBooking(bookingID);
                break;
            }
        }
    } while (choice != 0);
}

void lecturerActions(Lecturer& lecturer, const std::vector<std::shared_ptr<Building>>& buildings) {
    // Implement Lecturer specific actions here
    int choice;
    do {
        std::cout << "\nLecturer Actions:\n";
        std::cout << "1. Book Room\n";
        std::cout << "2. Cancel Booking\n";
        std::cout << "3. Search Room\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        flushCin();

        switch (choice) {
            case 1: {
                // Book Room logic
                std::string buildingCode, roomNumber, date;
                float startTime, endTime;
                std::cout << "Enter building code: ";
                std::cin >> buildingCode;
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cout << "Enter start time: ";
                std::cin >> startTime;
                std::cout << "Enter end time: ";
                std::cin >> endTime;

                auto building = globalAdmin.getBuilding(buildingCode);
                if (building) {
                    Room* room = building->findRoom(roomNumber);
                    if (room) {
                        if (lecturer.bookRoom(room, &subject, date, startTime, endTime)) {
                            std::cout << "Room booked successfully.\n";
                        } else {
                            std::cout << "Failed to book room.\n";
                        }
                    } else {
                        std::cout << "Room not found.\n";
                    }
                } else {
                    std::cout << "Building not found.\n";
                }
                break;
            }
            case 2: {
                // Display all current bookings
                std::cout << "Current Bookings:\n";
                for (const auto& booking : lecturer.getBookings()) {
                    std::cout << booking->getDetails() << std::endl;
                }

                // Cancel Booking logic
                std::string bookingID;
                std::cout << "Enter booking ID to cancel: ";
                std::cin >> bookingID;
                if (lecturer.cancelBooking(bookingID)) {
                    std::cout << "Booking cancelled successfully.\n";
                } else {
                    std::cout << "Failed to cancel booking. Ensure the booking ID is correct.\n";
                }
                break;
            }
            case 3: {
                // Search Room logic
                int capacity;
                std::cout << "Enter required room capacity: ";
                std::cin >> capacity;

                std::vector<Room*> suitableRooms;
                for (const auto& building : buildings) {
                    auto rooms = lecturer.searchRoomsByCapacity(building->getAllRooms(), capacity);
                    suitableRooms.insert(suitableRooms.end(), rooms.begin(), rooms.end());
                }

                std::cout << "Suitable rooms:\n";
                for (const auto& room : suitableRooms) {
                    std::cout << room->GetDetails() << "\n";
                }
                break;
            }
        }
    } while (choice != 0);
}

void flushCin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
