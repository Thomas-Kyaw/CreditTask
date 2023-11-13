#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include <iostream>
#include <memory>

int main() {
    Building building("B1");

    // Create Room as a unique_ptr and add it to the building
    auto roomPtr = std::make_unique<Room>(&building, "R101", 30);
    Room* roomRawPtr = roomPtr.get(); // Get raw pointer for other uses
    building.addRoom(std::move(roomPtr)); // Transfer ownership to Building

    Lecturer lecturer("Dr. Smith", "Lec1", roomRawPtr);
    Subject subject("CS101", "Computer Science");

    // Create Booking with shared_ptr to Room
    auto sharedRoomPtr = std::make_shared<Room>(*roomRawPtr); // Create a shared_ptr from the raw pointer
    Booking booking("B1", "R101", 9.0f, 10.0f, &lecturer, &subject, sharedRoomPtr);

    std::cout << "Booking created for room: " << sharedRoomPtr->getRoomNumber() << std::endl;

    return 0;
}
