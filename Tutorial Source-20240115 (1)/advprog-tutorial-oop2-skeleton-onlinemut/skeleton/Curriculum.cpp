#include "Curriculum.h"
#include "Course.h"
#include "Lecture.h"
#include "Practical.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

Curriculum::Curriculum()
{
    _available_courses.push_back(std::make_shared<Lecture>("1234E", "15/10/24"));
    _available_courses.push_back(std::make_shared<Practical>("3456F", "5"));
    print_courses()
}

Curriculum::print_courses()
{
    for (const auto &course : _available_courses)
    {
        std::cout << course->id() << std::endl
    }
}
Curriculum::std::shared_ptr<const Course> request(std::string id) const
{
    for (auto const &course : _available_courses)
    {
        if (course->id() == id)
            return course;
    }
    throw(std::runtime_error("Course with id " + id + " not found in available courses."));
}
