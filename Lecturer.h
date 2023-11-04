//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef LECTURER_H
#define LECTURER_H

#include "User.h"
#include "Room.h"
#include "Subject.h"

#include <vector>

class Lecturer : public User {
private:
    std::string lecturerID;
    Room* office;
    std::vector<Subject*> subjects;

public:
    Lecturer(const std::string &name, const std::string &id, Room* officeRoom);
    ~Lecturer();

    bool bookRoom(Room* room, Subject* subject, int duration);
    bool cancelBooking(Room* room);
};

#endif // LECTURER_H

