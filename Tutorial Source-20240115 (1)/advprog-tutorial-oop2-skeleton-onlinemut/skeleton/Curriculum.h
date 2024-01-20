#ifndef CURRICULUM_H
#define CURRICULUM_H

#include "Course.h"
#include <memory>
#include <vector>

class Curriculum {
private:
  std::vector<std::shared_ptr<Course>> _available_courses;

public:
  Curriculum();

  void print_courses() const;

  // We return a pointer to const Course (shared_ptr, as many users may need it, and to simplify copying)
  // to make clear that the object should not be modifed by the caller
  std::shared_ptr<const Course> request(std::string id) const;
};

#endif // CURRICULUM_H
