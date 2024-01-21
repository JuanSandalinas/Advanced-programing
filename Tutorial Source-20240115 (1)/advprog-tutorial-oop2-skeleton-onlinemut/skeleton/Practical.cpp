#include <iostream>
#include <string>

#include "Practical.h"

Practical::Practical(std::string id, std::string num_worksheets) : Course(id), _num_worksheets(num_worksheets)
{
    std::cout << "Constructing the practical " << _id << std::endl;
}

void Practical::describe() override
{
    std::cout << "This is a Practical course which implies worksheets" << std::endl;
};

std::string Practical::type() override
{
    return "Practical";
}