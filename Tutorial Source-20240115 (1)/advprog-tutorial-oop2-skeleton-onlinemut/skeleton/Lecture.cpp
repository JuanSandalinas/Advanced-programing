#include <iostream>
#include <string>

#include "Lecture.h"

Lecture::Lecture(std::string id, std::string exam_date)
    : Course(id), _exam_date(exam_date)
{
  std::cout << "Constructing the lecture " << _id << std::endl;
}

void Lecture::describe() override
{
  std::cout << "This is a Lecture course with a final exam" << std::endl;
}

std::string Lecture::type() override
{
  return "Lecture";
}
