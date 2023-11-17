#include "Booking.h"
#include "Lecturer.h"
#include "Room.h"
#include <iostream>
#include <algorithm>
#include <memory>

Booking::Booking(const std::string& id, const std::string& roomNum, const std::string& date, float start, float end, Lecturer* lec, Subject* subj, std::shared_ptr<Room> rm)
        : bookingID(id), roomNumber(roomNum), bookingDate(date), status(BookingStatus::PENDING), startTime(start), endTime(end), lecturer(lec), subject(subj), room(rm), isValid(true) {

}

void Booking::updateOnRoomDeletion() {
    room.reset();
    // Additional stuff goes here
    markInvalid();
}

std::string Booking::getDetails() const {
    if (!isValid) {
        return "Booking is no longer valid.";
    }

    std::string details = "Booking Details:\n";
    details += "Booking ID: " + bookingID + "\n";
    details += "Room: " + roomNumber + "\n";
    details += "Date: " + bookingDate + "\n";
    details += "Time: " + std::to_string(startTime) + " - " + std::to_string(endTime) + "\n";
    details += "Lecturer: " + (lecturer ? lecturer->getName() : "No Lecturer") + "\n";
    details += "Subject: " + (subject ? subject->getDetails() : "No Subject") + "\n";
    details += "Status: " + bookingStatusToString(status) + "\n";
    return details;
}

std::string Booking::bookingStatusToString(BookingStatus status) const {
    switch (status) {
        case BookingStatus::PENDING:
            return "Pending";
        case BookingStatus::APPROVED:
            return "Approved";
        case BookingStatus::REJECTED:
            return "Rejected";
        default:
            return "Unknown";
    }
}
