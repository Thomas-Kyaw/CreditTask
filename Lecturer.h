//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef LECTURER_H
#define LECTURER_H

#include "User.h"
#include "Room.h"
#include "Subject.h"
#include "Booking.h"

#include <vector>
#include <string>

class Lecturer : public User {
private:
    std::string lecturerID;
    Room* office;
    std::vector<Subject*> subjects;
    std::vector<Booking*> bookings; // Vector to track the lecturer's bookings

public:
    Lecturer(const std::string &name, const std::string &id, Room* officeRoom);
    ~Lecturer();

    std::string generateBookingID(); // Function to generate a unique booking ID
    bool bookRoom(Room* room, Subject* subject, float startTime, float endTime);
    bool cancelBooking(const std::string& bookingID); // Changed to take a booking ID
    std::vector<Room*> searchRoomsByCapacity(const std::vector<Room*>& allRooms, int requiredCapacity);
};

#endif // LECTURER_H


