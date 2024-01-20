#ifndef COURSE_H
#define COURSE_H

#include <string>

// TODO: Remove CourseType from everywhere after implementing concrete types
enum class CourseType { Lecture, Seminar, Practical };

class Course {
protected:
  std::string _id;
  CourseType _type;

public:
  Course(std::string, CourseType);

  std::string id() const;

  std::string type() const;

  // TODO: Add describe()

  // TODO: Declare the destructor as virtual (why?)
  ~Course() = default;
};

#endif // COURSE_Η
