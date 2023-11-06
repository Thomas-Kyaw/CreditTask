//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "MeetingRoom.h"

MeetingRoom::MeetingRoom(const std::string& num, int cap, bool conferenceEquip, bool whiteboard, const std::string& seating)
        : Room(num, cap), hasConferenceCallEquipment(conferenceEquip), hasWhiteboard(whiteboard), seatingArrangement(seating) {}


std::string MeetingRoom::GetDetails() const {
    std::string details = Room::GetDetails();
    details += "Type: Meeting Room\n";
    // Add more details specific to MeetingRoom if necessary
    return details;
}

