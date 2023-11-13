//
// Created by Aung Khant Kyaw on 2023/11/04.
//

// MeetingRoom.cpp
#include "MeetingRoom.h"

MeetingRoom::MeetingRoom(std::shared_ptr<Building> bld, const std::string& number, int cap, bool conferenceCall, bool whiteboard)
        : Room(bld, number, cap), hasConferenceCallEquipment(conferenceCall), hasWhiteboard(whiteboard){
    // Additional initialization for MeetingRoom if needed
}

std::string MeetingRoom::GetDetails() const {
    std::string details = Room::GetDetails();
    details += "Type: Meeting Room\n";
    details += "Conference Call Equipment: " + std::string(hasConferenceCallEquipment ? "Yes" : "No") + "\n";
    details += "Whiteboard: " + std::string(hasWhiteboard ? "Yes" : "No") + "\n";
    details += "Seating Arrangement: " + seatingArrangement + "\n";
    return details;
}

