#include "Building.h"
#include "Room.h"
#include "Booking.h"
#include "Lecturer.h"
#include "Subject.h"
#include <iostream>

int main() {
    Building building("B1");
    Room room(&building, "R101", 30);
    Lecturer lecturer("Dr. Smith", "Lec1", nullptr);
    Subject subject("CS101", "Computer Science");
    Booking booking("B1", "R101", 9.0f, 10.0f, &lecturer, &subject, &room);
    std::cout << "Booking created for room: " << room.getRoomNumber() << std::endl;
    return 0;
}
