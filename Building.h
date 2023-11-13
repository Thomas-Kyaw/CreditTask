#ifndef BUILDING_H
#define BUILDING_H

#include "Room.h"
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

class Building : public std::enable_shared_from_this<Building>{
private:
    std::string buildingCode;
    std::vector<std::unique_ptr<Room>> rooms; // Using unique_ptr for Room objects

public:
    Building(const std::string& code);
    //~Building(); // Destructor is not needed as unique_ptr handles deletion
    void addRoom(const std::string& roomNumber, int capacity); // Changed to take unique_ptr
    void editRoom(const std::string& roomNumber, int newCapacity);
    Room* findRoom(const std::string& roomNumber); // Returns raw pointer
    void deleteRoom(const std::string& roomNumber);
    std::shared_ptr<Room> getRoomSharedPtr(const std::string& roomNumber);
    // ... Other methods
};

#endif // BUILDING_H
