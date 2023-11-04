//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Room.h"
#include <vector>

class Admin : public User {
private:
    std::vector<Room*> rooms;

public:
    Admin(const std::string &name);
    ~Admin();

    void addRoom(Room* room);
    void editRoom(Room* room);
    void deleteRoom(Room* room);
};

#endif // ADMIN_H

