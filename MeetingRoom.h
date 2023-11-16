//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef MEETINGROOM_H
#define MEETINGROOM_H

#include "Room.h" // Include the Room class definition

// MeetingRoom class, inheriting from Room
class MeetingRoom : public Room {
    bool hasConferenceCallEquipment; // Indicates if the room has conference call equipment
    bool hasWhiteboard; // Indicates if the room has a whiteboard
    std::string seatingArrangement; // Describes the seating arrangement in the room

public:
    // Constructor
    MeetingRoom(std::shared_ptr<Building> bld, const std::string& number, int cap, bool conferenceCall, bool whiteboard);
    // Override of GetDetails method to provide detailed information about the meeting room
    virtual std::string GetDetails() const override;
};

#endif // MEETINGROOM_H
