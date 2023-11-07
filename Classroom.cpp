//
// Created by Aung Khant Kyaw on 2023/11/07.
//

#include "Classroom.h"

Classroom::Classroom(Building* bld, const std::string& number, int cap, ClassroomType type)
        : Room(bld, number, cap), roomType(type) {
    // Additional initialization for Classroom if needed
}

std::string Classroom::GetDetails() const {
    std::string details = Room::GetDetails();
    std::string typeStr = (roomType == ClassroomType::LectureRoom) ? "Lecture Room" : "Tutorial Room";
    details += "Classroom Type: " + typeStr + "\n";
    return details;
}

