#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Room.h" // Include the Room class definition

// Enumeration for different types of classrooms
enum class ClassroomType { LectureRoom, TutorialRoom };

// Classroom class, inheriting from Room
class Classroom : public Room {
private:
    ClassroomType roomType; // Specifies the type of the classroom (Lecture or Tutorial)

public:
    // Constructor
    Classroom(std::shared_ptr<Building> bld, const std::string& number, int cap, ClassroomType type);
    // Override of GetDetails method to provide detailed information about the classroom
    virtual std::string GetDetails() const override;
};

#endif // CLASSROOM_H