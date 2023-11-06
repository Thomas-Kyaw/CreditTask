cmake_minimum_required(VERSION 3.26)
project(CreditTask)

set(CMAKE_CXX_STANDARD 17)

# Include the directories where the CppUnit headers are located.
include_directories(/opt/homebrew/Cellar/cppunit/1.15.1/include)

# Specify the executable and the source files.
add_executable(CreditTask main.cpp
        Room.cpp
        Room.h
        MeetingRoom.cpp
        MeetingRoom.h
        ComputerLab.cpp
        ComputerLab.h
        User.cpp
        User.h
        Admin.cpp
        Admin.h
        Lecturer.cpp
        Lecturer.h
        Subject.cpp
        Subject.h
        Booking.cpp
        Booking.h
        Building.cpp
        Building.h)

# Link against the CppUnit library located in the given directory.
target_link_directories(CreditTask PRIVATE /opt/homebrew/Cellar/cppunit/1.15.1/lib)
target_link_libraries(CreditTask cppunit)