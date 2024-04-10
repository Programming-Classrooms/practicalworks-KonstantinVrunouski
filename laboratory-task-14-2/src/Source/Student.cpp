#include "Student.hpp"

int32_t Student::counter = 0;

Student::Student(const std::string newName,
                 const int32_t newCourse, 
                 const int32_t newGroup, 
                 const size_t newStudentBookNum) : IDnum(++counter),
                                                    name(newName), 
                                                    course(newCourse),
                                                    group(newGroup),
                                                    studentBookNum(newStudentBookNum)
{}

Student::Student(const Student& rhs) : IDnum(++counter), studentBookNum(rhs.studentBookNum)
{
    name = rhs.name;
    course = rhs.course;
    group = rhs.group;
}


void Student::setName(const std::string rhs)
{
    name = rhs;
}

void Student::setCourse(const int32_t rhs)
{
    if (rhs > 0)
    {
        course = rhs;
        return;
    }
    throw std::invalid_argument("Invalid course.");
}

void Student::setGroup(const int32_t rhs)
{
    if (group > 0)
    {
        group = rhs;
    }
    throw std::invalid_argument("Invalid group.");
}

int32_t Student::getID()
{
    return IDnum;
}

std::string Student::getName()
{
    return name;
}

int32_t Student::getCourse()
{
    return course;
}

int32_t Student::getGroup()
{
    return group;
}

size_t Student::getStudentBookNum()
{
    return studentBookNum;
}

std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
    out << "ID: " << rhs.IDnum << '\n';
    out << "Name: " << rhs.name << '\n';
    out << "Course: " << rhs.course << '\n';
    out << "Group " << rhs.group << '\n';
    out << "Student book number: " << rhs.studentBookNum << '\n';
    return out;
}