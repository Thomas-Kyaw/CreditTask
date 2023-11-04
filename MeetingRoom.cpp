//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "MeetingRoom.h"

MeetingRoom::MeetingRoom(const std::string& num, int cap, bool conferenceEquip, bool whiteboard, const std::string& seating)
        : Room(num, cap), hasConferenceCallEquipment(conferenceEquip), hasWhiteboard(whiteboard), seatingArrangement(seating) {}

bool MeetingRoom::bookRoom() {

    return false;
}

std::string MeetingRoom::getDetails() const {

    return "";
}

