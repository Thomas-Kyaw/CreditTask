//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Admin.h"

Admin::Admin(const std::string &nameVal) : User(nameVal) {}

Admin::~Admin() {
    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();
}

void Admin::addRoom(Room* room) {
    rooms.push_back(room);
}

void Admin::editRoom(Room* room) {

}

void Admin::deleteRoom(Room* room) {

}

