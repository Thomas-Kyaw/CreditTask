//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Room.h"
#include "Building.h"
#include "Booking.h"
#include "Lecturer.h"


class RoomTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(RoomTest);
        CPPUNIT_TEST(testIsAvailable);
        CPPUNIT_TEST(testAddRemoveBooking);
    CPPUNIT_TEST_SUITE_END();

public:
    void testIsAvailable() {
        Building building("B1");
        Room room(&building, "R101", 30);
        Lecturer lecturer("Dr. Smith", "Lec1", nullptr); // Assuming officeRoom is optional
        Subject subject("CS101", "Computer Science");

        // Initially, the room should be available
        CPPUNIT_ASSERT(room.isAvailable(9.0f, 10.0f));

        // Create a booking and add it to the room
        Booking booking("B1", "R101", 9.0f, 11.0f, &lecturer, &subject, &room);

        // Now the room should not be available during the booking time
        CPPUNIT_ASSERT(!room.isAvailable(9.0f, 10.0f));
        CPPUNIT_ASSERT(room.isAvailable(11.0f, 12.0f));
    }

    void testAddRemoveBooking() {
        Building building("B1");
        Room room(&building, "R101", 30);
        Lecturer lecturer("Dr. Smith", "Lec1", nullptr);
        Subject subject("CS101", "Computer Science");

        Booking booking1("B1", "R101", 9.0f, 10.0f, &lecturer, &subject, &room);
        // Check if the room is not available during the booking time
        CPPUNIT_ASSERT(!room.isAvailable(9.0f, 10.0f));

        room.removeBooking(&booking1);
        // Check if the room is available again after removing the booking
        CPPUNIT_ASSERT(room.isAvailable(9.0f, 10.0f));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(RoomTest);
