#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "Building.h"

class BuildingTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(BuildingTest);
        CPPUNIT_TEST(testAddRoom);
        CPPUNIT_TEST(testEditRoom);
        CPPUNIT_TEST(testFindRoom);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAddRoom() {
        auto building = std::make_shared<Building>("B1");
        auto room1 = std::make_shared<Room>(building, "R101", 30);

        building->addRoom("R101", 30); // Adjusted to match the expected signature
        CPPUNIT_ASSERT(building->findRoom("R101") != nullptr);
    }

    void testEditRoom() {
        auto building = std::make_shared<Building>("B1");

        // Add room to building
        building->addRoom("R101", 30);

        // Edit room capacity
        building->editRoom("R101", 50);

        // Retrieve room from building and check its capacity
        auto room = building->findRoom("R101");
        CPPUNIT_ASSERT(room != nullptr);
        CPPUNIT_ASSERT_EQUAL(50, room->getCapacity());
    }


    void testFindRoom() {
        auto building = std::make_shared<Building>("B1");
        auto room1 = std::make_shared<Room>(building, "R101", 30);
        auto room2 = std::make_shared<Room>(building, "R102", 40);

        building->addRoom( "R101", 30);
        building->addRoom("R102", 40);

        CPPUNIT_ASSERT(building->findRoom("R101") != nullptr);
        CPPUNIT_ASSERT(building->findRoom("R102") != nullptr);
        CPPUNIT_ASSERT(building->findRoom("R103") == nullptr);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(BuildingTest);
