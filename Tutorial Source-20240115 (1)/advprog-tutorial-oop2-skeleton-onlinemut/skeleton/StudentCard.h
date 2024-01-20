#ifndef STUDENTCARD_H
#define STUDENTCARD_H

#include <iostream>
#include <string>

#include "Student.h"

class StudentCard {

private:
  std::string _student_name;

public:
  StudentCard(Student);

  void print() const;
};

#endif
