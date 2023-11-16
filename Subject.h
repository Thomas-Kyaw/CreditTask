//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <string> // Include standard string library

// Subject class definition
class Subject {
private:
    std::string subjectCode; // Unique code identifying the subject
    std::string name; // Name of the subject

public:
    // Constructor for Subject
    Subject(const std::string &code, const std::string &name);
    // Method to get details of the subject
    std::string getDetails() const; // Returns the details of the subject
};

#endif // SUBJECT_H
