#ifndef STUDENT_HPP
#define STUDENT_HPP


#include <iostream>
#include <string.h>


class Student
{
public:
	std::string name;
	size_t course;
	size_t group;

	Student();
	Student(const std::string& newName, size_t newCourse, size_t newGroup);
	~Student() {}

	Student& operator=(const Student& rhs);

	friend std::ostream& operator<<(std::ostream&, const Student& student);
	friend std::istream& operator>>(std::istream&, Student&);

};

#endif