//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>
#include "Room.h"

class RoomTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(RoomTest);
        CPPUNIT_TEST(testIsAvailable);
        CPPUNIT_TEST(testAddRemoveBooking);
    CPPUNIT_TEST_SUITE_END();

public:
    void testIsAvailable() {
        // Implement test for isAvailable method
    }

    void testAddRemoveBooking() {
        // Implement test for addBooking and removeBooking methods
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(RoomTest);
