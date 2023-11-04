//
// Created by Aung Khant Kyaw on 2023/11/05.
//

#include "Booking.h"

Booking::Booking(const std::string& id, Room* rm, Lecturer* lec, float start, float end)
        : bookingID(id), room(rm), lecturer(lec), status(BookingStatus::PENDING), startTime(start), endTime(end) {}

Booking::~Booking() {

}

bool Booking::checkAvailability(float start, float end) const {
    return !(start < this->endTime && end > this->startTime); // no overlap if true
}

std::string Booking::getBookingID() const { return bookingID; }
void Booking::setBookingID(const std::string& id) { bookingID = id; }

Room* Booking::getRoom() const { return room; }
void Booking::setRoom(Room* rm) { room = rm; }

Lecturer* Booking::getLecturer() const { return lecturer; }
void Booking::setLecturer(Lecturer* lec) { lecturer = lec; }

BookingStatus Booking::getStatus() const { return status; }
void Booking::setStatus(BookingStatus sts) { status = sts; }

float Booking::getStartTime() const { return startTime; }
void Booking::setStartTime(float start) { startTime = start; }

float Booking::getEndTime() const { return endTime; }
void Booking::setEndTime(float end) { endTime = end; }

std::string Booking::getStatusString() const {
    switch (status) {
        case BookingStatus::APPROVED:
            return "Approved";
        case BookingStatus::REJECTED:
            return "Rejected";
        case BookingStatus::PENDING:
            return "Pending";
        default:
            return "Unknown";
    }
}

