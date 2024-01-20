#include "StudentCard.h"

StudentCard::StudentCard(Student student)
    : _student_name(student._name) {
  std::cout << "Issued a card for " << _student_name << "." << std::endl;
}

void StudentCard::print() const {
  std::cout << "This card belongs to " << _student_name << "." << std::endl;
}
