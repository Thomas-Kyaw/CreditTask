#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Room.h"

enum class ClassroomType { LectureRoom, TutorialRoom };

class Classroom : public Room {
private:
    ClassroomType roomType;

public:
    Classroom(std::shared_ptr<Building> bld, const std::string& number, int cap, ClassroomType type);
    virtual std::string GetDetails() const override;
};

#endif // CLASSROOM_H
