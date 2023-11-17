#ifndef CREDITTASK_GLOBALS_H
#define CREDITTASK_GLOBALS_H

#include "Admin.h"
#include "set"

extern Admin globalAdmin;

extern unsigned int nextRoomID;

extern std::set<unsigned int> deletedRooms;

unsigned int generateRoomID();

extern std::vector<std::shared_ptr<Booking>> CancelledBookings;

#endif // CREDITTASK_GLOBALS_H
