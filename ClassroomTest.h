//
// Created by Aung Khant Kyaw on 2023/11/12.
//

#ifndef CLASSROOMTEST_H
#define CLASSROOMTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Classroom.h"
#include "Building.h"

class ClassroomTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(ClassroomTest);
        CPPUNIT_TEST(TestGetDetails);
    CPPUNIT_TEST_SUITE_END();

public:
    void TestGetDetails();
};

#endif // CLASSROOMTEST_H

