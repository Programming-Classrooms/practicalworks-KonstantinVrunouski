#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

class Student
{
protected:
    int32_t IDnum;
    std::string name;
    int32_t course;
    int32_t group;
    const size_t studentBookNum;
    static int32_t counter;

public:
    Student() = delete;
    Student(const std::string, const int32_t, const int32_t, const size_t);
    Student(const Student&);

    virtual ~Student(){}

    void setName(const std::string);
    void setCourse(const int32_t);
    void setGroup(const int32_t);

    int32_t getID();
    std::string getName();
    int32_t getCourse();
    int32_t getGroup();
    size_t getStudentBookNum();

    friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif