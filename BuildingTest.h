//
// Created by Aung Khant Kyaw on 2023/11/12.
//

#ifndef BUILDINGTEST_H
#define BUILDINGTEST_H

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
    void testAddRoom();
    void testEditRoom();
    void testFindRoom();
};

#endif // BUILDINGTEST_H

