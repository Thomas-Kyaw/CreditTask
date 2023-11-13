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
    void TestGetDetails() {
        auto building = std::make_shared<Building>("B2");
        std::list<std::string> software = {"Software1", "Software2"};
        ComputerLab lab(building, "Lab1", 30, "Windows", software, true);

        std::string expectedDetails = "Room Number: Lab1\nCapacity: 30\nType: Computer Lab\nOperating System: Windows\nPrinting Facility: Yes\nSoftware Installed: Software1, Software2\n";
        CPPUNIT_ASSERT_EQUAL(expectedDetails, lab.GetDetails());
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(ComputerLabTest);
