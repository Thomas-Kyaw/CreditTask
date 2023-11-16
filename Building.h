#ifndef BUILDING_H
#define BUILDING_H

#include "Room.h" // Include the Room class definition
#include <string> // Include the standard string library
#include <vector> // Include the standard vector library
#include <memory> // Include the standard memory library for smart pointers

// Building class inheriting from enable_shared_from_this to allow shared pointers of itself
class Building : public std::enable_shared_from_this<Building>{
private:
    std::string buildingCode; // Stores the unique code of the building
    //std::vector<std::unique_ptr<Room>> rooms; // Stores rooms as unique pointers, ensuring unique ownership
    std::vector<std::shared_ptr<Room>> rooms;

public:
    // Constructor
    Building(const std::string& code); // Initializes a building with a given code

    // Room management methods
    void addRoom(const std::string& roomNumber, int capacity); // Adds a room with specified number and capacity
    void editRoom(const std::string& roomNumber, int newCapacity); // Edits the capacity of a specified room
    Room* findRoom(const std::string& roomNumber); // Finds and returns a raw pointer to the room with the specified number
    void deleteRoom(const std::string& roomNumber); // Deletes the room with the specified number
    std::shared_ptr<Room> getRoomSharedPtr(const std::string& roomNumber); // Returns a shared pointer to the specified room
    size_t getRoomCount() const; // Returns the count of rooms in the building

    // ... Other methods
};

#endif // BUILDING_H
