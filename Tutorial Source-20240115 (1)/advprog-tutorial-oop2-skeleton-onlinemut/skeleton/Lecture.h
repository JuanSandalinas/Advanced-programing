#ifndef LECTURE_H
#define LECTURE_H

#include "Course.h"

class Lecture : public Course
{
private:
  std::string _exam_date;

public:
  Lecture(std::string id, std::string exam_date);
  void describe() const override;
  void type() const override;
};

#endif // LECTURE_H