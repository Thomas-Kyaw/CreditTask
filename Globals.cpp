        //
        // Created by Aung Khant Kyaw on 2023/11/16.
        //
        #include "Globals.h"

        Admin globalAdmin("Admin1"); // Definition of globalAdmin

        unsigned int nextRoomID = 1;

        unsigned int generateRoomID() {
            return nextRoomID++; // Generate a new ID and increment the counter.
        }

        std::set<unsigned int> deletedRooms;

        //std::vector<std::shared_ptr<Booking>> CancelledBookings;