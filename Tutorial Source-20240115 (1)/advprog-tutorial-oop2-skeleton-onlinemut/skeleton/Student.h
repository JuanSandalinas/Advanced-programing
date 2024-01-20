#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include "Curriculum.h"
#include <memory>
#include <string>
#include <vector>

class Student {
private:
  std::string _name;
  const std::string _registration_num;

  // Every student has study program, but these exist already.
  // It is not the student that decides when they are
  // constructed and destructed.
  // (alternative: std::experimental::observer_ptr)
  const Curriculum* _study_program;

  // TODO: Convert to vector of pointers
  std::vector<Course> _courses;

  friend class StudentCard;

public:
  Student(std::string, std::string, const std::unique_ptr<Curriculum>&);

  void register_for(std::string id);

  void list_courses() const;
};

#endif // STUDENT_H
