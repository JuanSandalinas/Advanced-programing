#ifndef PRACTICAL_H
#define PRACTICAL_H

#include "Course.h"

class Practical : public Course
{
private:
  const std::size_t _num_worksheets;

public:
  Practical(std::string id, std::string exam_date) void describe() override;
  void describe() const override;
  std::string type() const override;
}
#endif // PRACTICAL_H