//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "MeetingRoom.h"
#include "Building.h"

/*class MeetingRoomTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(MeetingRoomTest);
        CPPUNIT_TEST(TestGetDetails);
    CPPUNIT_TEST_SUITE_END();

public:
    void TestGetDetails()
    {
        Building building("B1");
        MeetingRoom meetingRoom(&building, "MR1", 40, true, true);

        std::string expectedDetails = "Room Number: MR1\nCapacity: 40\nType: Meeting Room\nConference Call Equipment: Yes\nWhiteboard: Yes\nSeating Arrangement: \n";
        CPPUNIT_ASSERT_EQUAL(expectedDetails, meetingRoom.GetDetails());
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MeetingRoomTest);
*/