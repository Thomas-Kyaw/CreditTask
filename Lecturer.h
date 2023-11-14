#ifndef LECTURER_H
#define LECTURER_H

#include "User.h"
#include "Room.h"
#include "Subject.h"
#include "Booking.h"
#include "Building.h"
#include <vector>
#include <string>
#include <memory>

class Lecturer : public User {
private:
    std::string lecturerID;
    Room* office;
    std::vector<Subject*> subjects;
    std::vector<std::shared_ptr<Booking>> bookings; // Use shared_ptr for bookings

public:
    Lecturer(const std::string &name, const std::string &id, Room* officeRoom);
    ~Lecturer();

    std::string generateBookingID();
    bool bookRoom(Room* room, Subject* subject, float startTime, float endTime);
    bool cancelBooking(const std::string& bookingID);
    std::vector<Room*> searchRoomsByCapacity(const std::vector<Room*>& allRooms, int requiredCapacity);
    std::string getName() const;

    // Method to get bookings
    const std::vector<std::shared_ptr<Booking>>& getBookings() const {
        return bookings;
    }
};

#endif // LECTURER_H
