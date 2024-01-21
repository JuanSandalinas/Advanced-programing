#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
protected:
  std::string _id;

public:
  Course(std::string);

  std::string id() const;

  virtual std::string type() const = 0;

  virtual void describe() const = 0;

  virtual ~Course() = default;
};

#endif // COURSE_Η
