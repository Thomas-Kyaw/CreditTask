//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject {
private:
    std::string subjectCode;
    std::string name;

public:
    Subject(const std::string &code, const std::string &name);
    std::string getDetails() const;
};

#endif // SUBJECT_H

