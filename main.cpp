#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include "Admin.h"
#include <iostream>
#include <memory>

int main() {
    // Use a unique_ptr for automatic deallocation of Building
    auto buildingPtr = std::make_unique<Building>("B1");

    // Create Room as a unique_ptr and add it to the building
    auto roomPtr = std::make_unique<Room>(buildingPtr.get(), "R101", 30);
    Room* roomRawPtr = roomPtr.get(); // Get raw pointer for other uses
    buildingPtr->addRoom(std::move(roomPtr)); // Transfer ownership to Building

    Lecturer lecturer("Dr. Smith", "Lec1", roomRawPtr);
    Subject subject("CS101", "Computer Science");

    // Create Booking with shared_ptr to Room
    auto sharedRoomPtr = std::make_shared<Room>(*roomRawPtr); // Create a shared_ptr from the raw pointer
    Booking booking("B1", "R101", 9.0f, 10.0f, &lecturer, &subject, sharedRoomPtr);

    std::cout << "Booking created for room: " << sharedRoomPtr->getRoomNumber() << std::endl;

    // Admin for managing rooms and buildings
    Admin admin("Admin1");

    // Admin adds another room
    auto anotherRoomPtr = std::make_unique<Room>(buildingPtr.get(), "R102", 40);
    buildingPtr->addRoom(std::move(anotherRoomPtr));

    // Admin tries to delete a room
    admin.deleteRoom("B1", "R102");

    // Check if the room is deleted
    if (buildingPtr->findRoom("R102")) {
        std::cout << "Room R102 still exists." << std::endl;
    } else {
        std::cout << "Room R102 has been deleted." << std::endl;
    }

    // Delete building
    buildingPtr.reset();

    // Attempt to access room and booking after building deletion
    std::cout << "Room number after building deletion: " << (roomRawPtr ? roomRawPtr->getRoomNumber() : "Room not accessible") << std::endl;
    std::cout << "Booking details after building deletion: " << booking.getDetails() << std::endl;

    return 0;
}
