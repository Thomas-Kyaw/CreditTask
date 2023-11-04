//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Room.h"

Room::Room(const std::string& num, int cap) : roomNumber(num), capacity(cap), isAvailable(true) {}

bool Room::checkIfBooked() const {
    return !isAvailable;
}

void Room::setAvailability(bool availability) {
    isAvailable = availability;
}

