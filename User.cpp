//
// Created by Aung Khant Kyaw on 2023/11/04.
//

#include "User.h"

User::User(const std::string &nameVal) : name(nameVal) {}

User::~User() {}

std::string User::GetDetails() const {
    return "Username - " + name;
}