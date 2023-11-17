//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef USER_H
#define USER_H

#include <string> // Include standard string library

// User base class definition
class User {
protected:
    std::string name; // Name of the user

public:
    // Constructor for User
    User(const std::string &name);
    virtual ~User() = 0;
    // Virtual method to get user details
    virtual std::string GetDetails() const;
};

#endif // USER_H
