//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "Subject.h"

Subject::Subject(const std::string &code, const std::string &nameVal)
        : subjectCode(code), name(nameVal) {}

std::string Subject::getDetails() const {
    return "Subject Code: " + subjectCode + ", Name: " + name;
}

