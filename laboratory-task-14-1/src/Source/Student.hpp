#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "Person.hpp"

class Student : public Person
{
private:
    int32_t course;
    int32_t group;
public:
    Student();
    Student(const char*, const int32_t, const int32_t);
    Student(const Student&);
    Student(Student&&);

    ~Student(){}

    void setCourse(const int32_t);
    void setGroup(const int32_t);

    int32_t getCourse();
    int32_t getGroup();

    void print(std::ostream&);
};

#endif