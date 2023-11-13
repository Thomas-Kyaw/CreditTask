//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "Building.h"

/*class BuildingTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(BuildingTest);
        CPPUNIT_TEST(testAddRoom);
        CPPUNIT_TEST(testEditRoom);
        CPPUNIT_TEST(testFindRoom);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAddRoom() {
        // Implement test for addRoom method
        Building building("B1");
        Room room1(&building, "R101", 30);

        // Test adding a room
        building.addRoom(&room1);
        CPPUNIT_ASSERT(building.findRoom("R101") != nullptr); // Room should be found
    }

    void testEditRoom() {
        // Implement test for editRoom method
        Building building("B1");
        Room room1(&building, "R101", 30);

        building.addRoom(&room1);
        building.editRoom("R101", 50); // Changing capacity
        CPPUNIT_ASSERT_EQUAL(50, room1.getCapacity()); // Check if capacity is updated
    }

    void testFindRoom() {
        // Implement test for findRoom method
        Building building("B1");
        Room room1(&building, "R101", 30);
        Room room2(&building, "R102", 40);

        building.addRoom(&room1);
        building.addRoom(&room2);

        CPPUNIT_ASSERT(building.findRoom("R101") != nullptr); // Room1 should be found
        CPPUNIT_ASSERT(building.findRoom("R102") != nullptr); // Room2 should be found
        CPPUNIT_ASSERT(building.findRoom("R103") == nullptr); // Non-existent room should not be found
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(BuildingTest);
*/