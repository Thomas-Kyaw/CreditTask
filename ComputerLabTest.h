//
// Created by Aung Khant Kyaw on 2023/11/12.
//

#ifndef COMPUTERLABTEST_H
#define COMPUTERLABTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "ComputerLab.h"
#include "Building.h"

class ComputerLabTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(ComputerLabTest);
        CPPUNIT_TEST(TestGetDetails);
    CPPUNIT_TEST_SUITE_END();

public:
    void TestGetDetails();
};

#endif // COMPUTERLABTEST_H

