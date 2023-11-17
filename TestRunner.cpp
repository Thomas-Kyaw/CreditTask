// TestRunner.cpp
// Created by Aung Khant Kyaw on 2023/11/12.

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "BuildingTest.h"
#include "RoomTest.h"
#include "ClassroomTest.h"
#include "ComputerLabTest.h"
#include "MeetingRoomTest.h"

//comment out the main inside main.cpp before running
int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(ClassroomTest::suite()); // change "ClassroomTest" to the name beside the header extension
    bool wasSuccessful = runner.run("", false);
    return wasSuccessful ? 0 : 1;
}

