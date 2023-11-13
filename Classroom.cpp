#include "Classroom.h"

Classroom::Classroom(std::shared_ptr<Building> bld, const std::string& number, int cap, ClassroomType type)
        : Room(bld, number, cap), roomType(type) {
    // Additional initialization for Classroom if needed
}

std::string Classroom::GetDetails() const {
    std::string details = Room::GetDetails();
    std::string typeStr = (roomType == ClassroomType::LectureRoom) ? "Lecture Room" : "Tutorial Room";
    details += "Classroom Type: " + typeStr + "\n";
    return details;
}
