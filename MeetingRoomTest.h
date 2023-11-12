//
// Created by Aung Khant Kyaw on 2023/11/12.
//

#ifndef MEETINGROOMTEST_H
#define MEETINGROOMTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "MeetingRoom.h"
#include "Building.h"

class MeetingRoomTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(MeetingRoomTest);
        CPPUNIT_TEST(TestGetDetails);
    CPPUNIT_TEST_SUITE_END();

public:
    void TestGetDetails();
};

#endif // MEETINGROOMTEST_H

