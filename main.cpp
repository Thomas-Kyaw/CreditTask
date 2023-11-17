#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include "Globals.h"
#include <iostream>
#include <memory>

/*int main() {
    // Create a building and register it with the Admin
    auto buildingPtr = std::make_shared<Building>("B1");
    globalAdmin.addBuilding(buildingPtr); // Ensure the building is added to the Admin

    // Add rooms to the building
    buildingPtr->addRoom("R101", 30);
    buildingPtr->addRoom("R102", 40);
    buildingPtr->addRoom("R103", 50);

    // Debug: Print unique room IDs
    std::cout << "Unique Room IDs:\n";
    std::cout << "R101 ID: " << buildingPtr->getRoomSharedPtr("R101")->getUniqueRoomID() << "\n";
    std::cout << "R102 ID: " << buildingPtr->getRoomSharedPtr("R102")->getUniqueRoomID() << "\n";
    std::cout << "R103 ID: " << buildingPtr->getRoomSharedPtr("R103")->getUniqueRoomID() << "\n";

    // Create a lecturer and subject
    Lecturer lecturer("Dr. Smith", "Lec1", nullptr);
    Subject subject("CS101", "Computer Science");

    // Lecturer makes bookings
    auto room101 = buildingPtr->getRoomSharedPtr("R101");
    auto room102 = buildingPtr->getRoomSharedPtr("R102");
    auto room103 = buildingPtr->getRoomSharedPtr("R103");

    // Attempt bookings
    std::cout << "Attempting to book Room 101...\n";
    lecturer.bookRoom(room101.get(), &subject, 9.0f, 10.0f);

    std::cout << "Attempting to book Room 102...\n";
    lecturer.bookRoom(room102.get(), &subject, 10.0f, 11.0f);

    std::cout << "Attempting to book Room 103...\n";
    lecturer.bookRoom(room103.get(), &subject, 11.0f, 12.0f);

    // Attempt to book room101 again for the same time slot
    std::cout << "Attempting to book Room 101 again...\n";
    bool bookingResult = lecturer.bookRoom(room101.get(), &subject, 9.0f, 10.0f);
    if (!bookingResult) {
        std::cout << "Failed to book room R101 for the same time slot. Room is not available.\n";
    }

    // Display booking details
    std::cout << "Booking Details After Making Bookings:\n";
    for (const auto& booking : lecturer.getBookings()) {
        std::cout << booking->getDetails() << std::endl;
    }

    // Lecturer cancels one booking
    std::cout << "Cancelling booking BKG2...\n";
    lecturer.cancelBooking("BKG2");

    // Admin actions
    std::cout << "Admin approving and rejecting bookings...\n";
    globalAdmin.approveBooking("BKG1");
    globalAdmin.rejectBooking("BKG3");

    // Display updated booking details
    std::cout << "\nBooking Details After Admin Actions:\n";
    for (const auto& booking : lecturer.getBookings()) {
        std::cout << booking->getDetails() << std::endl;
    }

    // Delete a room and attempt to book it
    std::cout << "Admin deleting Room 102...\n";
    globalAdmin.deleteRoom("B1", "R102");

    // Debug: Print deleted rooms set
    std::cout << "Deleted Rooms: ";
    for (auto id : deletedRooms) {
        std::cout << id << " ";
    }
    std::cout << "\n";

    // Lecturer attempts to book the deleted room
    std::cout << "Attempting to book deleted Room 102...\n";
    bool bookingSuccess = lecturer.bookRoom(room102.get(), &subject, 13.0f, 14.0f);
    if (bookingSuccess) {
        std::cout << "Successfully booked the deleted room. This should not happen.\n";
    } else {
        std::cout << "Failed to book the deleted room. \n";
    }

    // Display updated booking details
    std::cout << "\nBooking Details After Attempting to Book Deleted Room:\n";
    for (const auto& booking : lecturer.getBookings()) {
        std::cout << booking->getDetails() << std::endl;
    }

    return 0;
}*/
