// TestRunner.cpp
// Created by Aung Khant Kyaw on 2023/11/12.

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

// Include your test suite headers
#include "RoomTest.h"
#include "BuildingTest.h"
#include "ClassroomTest.h"
#include "ComputerLabTest.h"
#include "MeetingRoomTest.h"

int main(int argc, char* argv[]) {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    bool wasSuccessful = runner.run("", false);
    return wasSuccessful ? 0 : 1;
}
