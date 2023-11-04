//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;

public:
    User(const std::string &name);
    virtual ~User() = 0;
};

#endif // USER_H

