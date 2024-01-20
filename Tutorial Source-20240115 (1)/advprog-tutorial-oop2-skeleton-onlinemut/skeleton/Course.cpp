#include "Course.h"
#include <iostream>

Course::Course(std::string id, CourseType type)
    : _id(id), _type(type) {
  std::cout << "Constructing the course " << _id << std::endl;
}

std::string Course::id() const {
  return _id;
}

std::string Course::type() const {
  std::string type;

  if (_type == CourseType::Lecture) {
    type = "Lecture";
  } else if (_type == CourseType::Seminar) {
    type = "Seminar";
  } else if (_type == CourseType::Practical) {
    type = "Practical";
  }

  return type;
}