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
    MeetingRoom(Building* bld, const std::string& number, int cap, bool conferenceCall, bool whiteboard);
    virtual std::string GetDetails() const override;
};

#endif // MEETINGROOM_H

