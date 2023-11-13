// TestRunner.cpp
// Created by Aung Khant Kyaw on 2023/11/12.

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

//#include "BuildingTest.h"
// Comment out other test suite headers
// #include "RoomTest.h"
//#include "ClassroomTest.h"
//#include "ComputerLabTest.h"
#include "MeetingRoomTest.h"


int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(MeetingRoomTest::suite());
    bool wasSuccessful = runner.run("", false);
    return wasSuccessful ? 0 : 1;
}

