//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Lecturer.h"

Lecturer::Lecturer(const std::string &nameVal, const std::string &id, Room* officeRoom)
        : User(nameVal), lecturerID(id), office(officeRoom) {}

Lecturer::~Lecturer() {

}

bool Lecturer::bookRoom(Room* room, Subject* subject, int duration) {

    return true;
}

bool Lecturer::cancelBooking(Room* room) {

    return true;
}

