//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef MEETINGROOM_H
#define MEETINGROOM_H

#include "Room.h"

class MeetingRoom : public Room {
    bool hasConferenceCallEquipment;
    bool hasWhiteboard;
    std::string seatingArrangement;

public:
    MeetingRoom(const std::string& num, int cap, bool conferenceEquip, bool whiteboard, const std::string& seating);
    virtual std::string GetDetails() const override;
};

#endif // MEETINGROOM_H

