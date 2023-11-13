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
        auto building = std::make_shared<Building>("B1");
        auto room = std::make_shared<Room>(building, "R101", 30);
        Lecturer lecturer("Dr. Smith", "Lec1", nullptr);
        Subject subject("CS101", "Computer Science");

        CPPUNIT_ASSERT(room->isAvailable(9.0f, 10.0f));

        Booking booking("B1-R101-9-10", "R101", 9.0f, 11.0f, &lecturer, &subject, room);

        CPPUNIT_ASSERT(!room->isAvailable(9.0f, 10.0f));
        CPPUNIT_ASSERT(room->isAvailable(11.0f, 12.0f));
    }

    void testAddRemoveBooking() {
        auto building = std::make_shared<Building>("B1");
        auto room = std::make_shared<Room>(building, "R101", 30);
        Lecturer lecturer("Dr. Smith", "Lec1", nullptr);
        Subject subject("CS101", "Computer Science");

        Booking booking1("B1-R101-9-10", "R101", 9.0f, 10.0f, &lecturer, &subject, room);

        CPPUNIT_ASSERT(!room->isAvailable(9.0f, 10.0f));

        room->removeBooking(&booking1);
        CPPUNIT_ASSERT(room->isAvailable(9.0f, 10.0f));
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(RoomTest);
