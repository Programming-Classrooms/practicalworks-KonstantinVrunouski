#include "StudentFirstSession.hpp"

StudentFirstSession::StudentFirstSession(const std::string newName, 
                                         const int32_t newCourse, 
                                         const int32_t newGroup, 
                                         const int32_t newStudentBookNum, 
                                         int32_t* arr) : Student(newName, 
                                                                            newCourse, 
                                                                            newGroup, 
                                                                            newStudentBookNum)
{
    if (arr == nullptr)
    {
        throw std::invalid_argument("Invalid pointer.");
    }
    for (size_t i = 0; i < 4; ++i)
    {
        marks[i] = arr[i];
    }
}

StudentFirstSession::StudentFirstSession(const StudentFirstSession& rhs) : Student(rhs)
{
    for (size_t i = 0; i < 4; ++i)
    {
        marks[i] = rhs.marks[i];
    }
}

void StudentFirstSession::setMarks(int32_t* arr)
{
    if (arr == nullptr)
    {
        throw std::invalid_argument("Invalid pointer.");
    }
    for (size_t i = 0; i < 4; ++i)
    {
        marks[i] = arr[i];
    }
}

int32_t* StudentFirstSession::getMarks()
{
    int32_t* temp = new int32_t[4];
    for (size_t i = 0; i < 4; ++i)
    {
        temp[i] = marks[i];
    }
    return temp;
}

std::ostream& operator<<(std::ostream& out, const StudentFirstSession& rhs)
{
    out << "ID: " << rhs.IDnum << '\n';
    out << "Name: " << rhs.name << '\n';
    out << "Course: " << rhs.course << '\n';
    out << "Group " << rhs.group << '\n';
    out << "Student book number: " << rhs.studentBookNum << '\n';
    out << "Marks 1 semester:\n";
    for (size_t i = 0; i < 4; ++i)
    {
        out << rhs.marks[i] << ' ';
    }
    out << '\n';
    return out;
}

double StudentFirstSession::mediumMark()
{
    double temp = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        temp += marks[i];
    }
    return (temp / 4);
}