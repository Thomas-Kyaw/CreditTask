//
// Created by Aung Khant Kyaw on 2023/11/12.
//

#ifndef ROOMTEST_H
#define ROOMTEST_H

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
    void testIsAvailable();
    void testAddRemoveBooking();
};

#endif // ROOMTEST_H
