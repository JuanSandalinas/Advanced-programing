#include <iostream>
#include <string>

#include "Lecture.h"

Lecture::Lecture(std::string id, std::string exam_date)
    : Course(id, CourseType::Lecture), _exam_date(exam_date) {
  std::cout << "Constructing the lecture " << _id << std::endl;
}

// TODO: Add describe()