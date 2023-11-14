#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include "Admin.h"
#include <iostream>
#include <memory>

int main() {
    Admin admin("Admin1");

    // Admin creates a building
    auto buildingPtr = admin.getBuilding("B1");

    // Admin adds rooms to the building
    admin.addRoom("B1", "R101", 30);
    admin.addRoom("B1", "R102", 40);

    // Retrieve the room pointer for further use
    auto roomPtr = buildingPtr->findRoom("R101");

    // Create lecturer and subject
    Lecturer lecturer("Dr. Smith", "Lec1", roomPtr);
    Subject subject("CS101", "Computer Science");

    // Lecturer books a room
    if (lecturer.bookRoom(roomPtr, &subject, 9.0f, 10.0f)) {
        std::cout << "Booking created for room: " << roomPtr->getRoomNumber() << std::endl;
    } else {
        std::cout << "Failed to create booking." << std::endl;
    }

    // Retrieve the booking ID (assuming the first booking is the one we're interested in)
    auto bookings = lecturer.getBookings();
    std::string bookingID = bookings.empty() ? "" : bookings.front()->getBookingID();

    // Cancel the booking
    if (lecturer.cancelBooking(bookingID)) {
        std::cout << "Booking cancelled successfully." << std::endl;
    } else {
        std::cout << "Failed to cancel booking." << std::endl;
    }

    // Attempt to display booking details after cancellation
    if (!bookings.empty()) {
        std::cout << "Booking details after cancellation: " << bookings.front()->getDetails() << std::endl;
    } else {
        std::cout << "No bookings to display." << std::endl;
    }

    // Delete building
    admin.deleteBuilding("B1");

    // Attempt to access room and booking after building deletion
    std::cout << "Room number after building deletion: " << (roomPtr ? roomPtr->getRoomNumber() : "Room not accessible") << std::endl;
    if (!bookings.empty()) {
        std::cout << "Booking details after building deletion: " << bookings.front()->getDetails() << std::endl;
    } else {
        std::cout << "No bookings to display." << std::endl;
    }

    return 0;
}
