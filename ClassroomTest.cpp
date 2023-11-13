//
// Created by Aung Khant Kyaw on 2023/11/12.
//
#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "Classroom.h"
#include "Building.h"

/*class ClassroomTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(ClassroomTest);
        CPPUNIT_TEST(TestGetDetails);
    CPPUNIT_TEST_SUITE_END();

public:
    void TestGetDetails()
    {
        Building building("B3");
        Classroom classroom(&building, "C101", 50, ClassroomType::LectureRoom);

        std::string expectedDetails = "Room Number: C101\nCapacity: 50\nClassroom Type: Lecture Room\n";
        CPPUNIT_ASSERT_EQUAL(expectedDetails, classroom.GetDetails());
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(ClassroomTest);
*/