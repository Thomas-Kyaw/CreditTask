    #include "Building.h"
    #include "Room.h"
    #include "Booking.h"
    #include "Lecturer.h"
    #include "Subject.h"
    #include "Admin.h"
    #include <iostream>
    #include <memory>

    int main() {
        // Admin for managing rooms and buildings
        Admin admin("Admin1");

        // Admin creates a building
        auto buildingPtr = admin.getBuilding("B1");

        // Admin adds a room to the building
        admin.addRoom("B1", "R101", 30);

        // Retrieve the room pointer for further use
        Room* roomRawPtr = buildingPtr->findRoom("R101");

        Lecturer lecturer("Dr. Smith", "Lec1", roomRawPtr);
        Subject subject("CS101", "Computer Science");

        // Create Booking with shared_ptr to Room
        auto sharedRoomPtr = std::make_shared<Room>(*roomRawPtr);
        Booking booking("B1", "R101", 9.0f, 10.0f, &lecturer, &subject, sharedRoomPtr);

        std::cout << "Booking created for room: " << sharedRoomPtr->getRoomNumber() << std::endl;

        // Admin adds another room
        admin.addRoom("B1", "R102", 40);

        // Admin tries to delete a room
        admin.deleteRoom("B1", "R102");

        // Check if the room is deleted
        if (buildingPtr->findRoom("R102")) {
            std::cout << "Room R102 still exists." << std::endl;
        } else {
            std::cout << "Room R102 has been deleted." << std::endl;
        }

        // Delete building
        admin.deleteBuilding("B1");
        buildingPtr = nullptr; // Invalidate the building pointer

        // Attempt to access room and booking after building deletion
        if (roomRawPtr) {
            std::cout << "Room number after building deletion: " << roomRawPtr->getRoomNumber() << std::endl;
        } else {
            std::cout << "Room not accessible after building deletion." << std::endl;
        }

        if (sharedRoomPtr) {
            std::cout << "Booking details after building deletion: " << booking.getDetails() << std::endl;
        } else {
            std::cout << "Booking details not accessible after building deletion." << std::endl;
        }

        return 0;
    }
