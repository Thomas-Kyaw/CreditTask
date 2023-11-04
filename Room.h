//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
protected:
    std::string roomNumber;
    int capacity;
    bool isAvailable;

public:
    Room(const std::string& num, int cap);
    virtual ~Room() = default;

    virtual bool bookRoom() = 0;
    virtual std::string getDetails() const = 0;
    bool checkIfBooked() const;
    void setAvailability(bool availability);
};

#endif // ROOM_H

