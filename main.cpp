#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include "Globals.h"
#include <iostream>
#include <memory>

int main() {
    // Create a building and rooms
    auto buildingPtr = std::make_shared<Building>("B1");
    buildingPtr->addRoom("R101", 30);
    buildingPtr->addRoom("R102", 40);
    buildingPtr->addRoom("R103", 50);

    // Create a lecturer
    Lecturer lecturer("Dr. Smith", "Lec1", nullptr);
    Subject subject("CS101", "Computer Science");

    // Lecturer makes three bookings
    auto room101 = buildingPtr->getRoomSharedPtr("R101");
    auto room102 = buildingPtr->getRoomSharedPtr("R102");
    auto room103 = buildingPtr->getRoomSharedPtr("R103");

    lecturer.bookRoom(room101.get(), &subject, 9.0f, 10.0f);
    lecturer.bookRoom(room102.get(), &subject, 10.0f, 11.0f);
    lecturer.bookRoom(room103.get(), &subject, 11.0f, 12.0f);

    // Attempt to book room101 again for the same time slot
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
    lecturer.cancelBooking("BKG2"); // Assuming booking IDs are "BKG1", "BKG2", etc.

    // Admin reviews and manages bookings using globalAdmin
    globalAdmin.approveBooking("BKG1"); // Approve the first booking
    globalAdmin.rejectBooking("BKG3"); // Reject the third booking

    // Display updated booking details
    std::cout << "\nBooking Details After Admin Actions:\n";
    for (const auto& booking : lecturer.getBookings()) {
        std::cout << booking->getDetails() << std::endl;
    }

    globalAdmin.deleteRoom("B1", "R102");

    // Lecturer attempts to book the deleted room
    bool bookingSuccess = lecturer.bookRoom(room102.get(), &subject, 13.0f, 14.0f);
    if (bookingSuccess) {
        std::cout << "Successfully booked the deleted room. This should not happen." << std::endl;
    } else {
        std::cout << "Failed to book the deleted room. This is expected." << std::endl;
    }

    // Display updated booking details
    std::cout << "\nBooking Details After Attempting to Book Deleted Room:\n";
    for (const auto& booking : lecturer.getBookings()) {
        std::cout << booking->getDetails() << std::endl;
    }

    return 0;
}
