#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
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

    // Delete building
    buildingPtr.reset();

    // Attempt to access room and booking after building deletion
    // WARNING: This is dangerous and typically results in undefined behavior
    // Uncomment the following lines to test, but expect crashes or erroneous behavior
     std::cout << "Room number after building deletion: " << roomRawPtr->getRoomNumber() << std::endl;
    std::cout << "Booking details after building deletion: " << booking.getDetails() << std::endl;

    return 0;
}
