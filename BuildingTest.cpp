//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>
#include "Building.h"

class BuildingTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(BuildingTest);
        CPPUNIT_TEST(testAddRoom);
        CPPUNIT_TEST(testEditRoom);
        CPPUNIT_TEST(testFindRoom);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAddRoom() {
        // Implement test for addRoom method
    }

    void testEditRoom() {
        // Implement test for editRoom method
    }

    void testFindRoom() {
        // Implement test for findRoom method
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(BuildingTest);
