#include "Student.hpp"

Student::Student() : name(std::string("NaN")), course(0), group(0)
{}

Student::Student(const std::string& newName, const size_t newCourse, const size_t newGroup) : name(newName), course(newCourse), group(newGroup)
{}

Student& Student::operator=(const Student & rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		course = rhs.course;
		group = rhs.group;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.name << ' ' << student.course << ' ' << student.group << '\n';
	return out;
}


std::istream& operator>>(std::istream& in, Student& student)
{
	in >> student.name;
	in >> student.course;
	in >> student.group;
	return in;
}

