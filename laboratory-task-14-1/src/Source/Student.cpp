#include "Student.hpp"

Student::Student() : Person(), course(1), group(1)
{}

Student::Student(const char* newName, const int32_t newCourse, const int32_t newGroup) : Person(newName)
{
    if (newCourse <= 0)
    {
        throw std::invalid_argument("Wrong course");
    }

    if (newGroup <= 0)
    {
        throw std::invalid_argument("Wrong group");
    }

    course = newCourse;
    group = newGroup;
}

Student::Student(const Student& rhs) : Person(rhs), course(rhs.course), group(rhs.group)
{}

Student::Student(Student&& rhs) : Person(rhs)
{
    std::swap(course, rhs.course);
    std::swap(group, rhs.group);
}

void Student::setCourse(const int32_t rhs)
{
    if (rhs <= 0)
    {
        throw std::invalid_argument("Wrong course.");
    }
    course = rhs;
}

void Student::setGroup(const int32_t rhs)
{
    if (rhs <= 0)
    {
        throw std::invalid_argument("Wrong group.");
    }
    group = rhs;
}

int32_t Student::getCourse()
{
    return course;
}

int32_t Student::getGroup()
{
    return group;
}

void Student::print(std::ostream& out)
{
    Person::print(out);
    out << "Course: " << course << '\n';
    out << "Group: " << group << '\n';
}
