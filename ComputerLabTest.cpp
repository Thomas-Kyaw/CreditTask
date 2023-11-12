//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>
#include "ComputerLab.h"

class ComputerLabTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(ComputerLabTest);
        CPPUNIT_TEST(TestGetDetails);
    CPPUNIT_TEST_SUITE_END();

public:
    void TestGetDetails()
    {

    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(ComputerLabTest);