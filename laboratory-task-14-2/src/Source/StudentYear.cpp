#include "StudentYear.hpp"

StudentYear::StudentYear(const std::string newName, 
                                         const int32_t newCourse, 
                                         const int32_t newGroup, 
                                         const int32_t newStudentBookNum, 
                                         int32_t* arrFirstSession,
                                         int32_t* arrYear) : StudentFirstSession(newName,
                                                                                   newCourse,
                                                                                   newGroup,
                                                                                   newStudentBookNum,
                                                                                   arrFirstSession)           
{
    if (arrYear == nullptr)
    {
        throw std::invalid_argument("Invalid pointer.");
    }
    for (size_t i = 0; i < 5; ++i)
    {
        marksYear[i] = arrYear[i];
    }
}

StudentYear::StudentYear(const StudentYear& rhs) : StudentFirstSession(rhs)
{
    for (size_t i = 0; i < 5; ++i)
    {
        marksYear[i] = rhs.marksYear[i];
    }
}

void StudentYear::setMarks(int32_t* arr)
{
    if (arr == nullptr)
    {
        throw std::invalid_argument("Invalid pointer.");
    }
    for (size_t i = 0; i < 4; ++i)
    {
        marksYear[i] = arr[i];
    }
}

int32_t* StudentYear::getMarks()
{
    int32_t* temp = new int32_t[5];
    for (size_t i = 0; i < 5; ++i)
    {
        temp[i] = marksYear[i];
    }
    return temp;
}

std::ostream& operator<<(std::ostream& out, const StudentYear& rhs)
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
    out << "Marks year:\n";
    for (size_t i = 0; i < 5; ++i)
    {
        out << rhs.marksYear[i] << ' ';
    }
    out << '\n';
    return out;
}

double StudentYear::mediumMark()
{
    double temp = 0;
    temp = StudentFirstSession::mediumMark();
    temp *= 4;
    for (size_t i = 0; i < 5; ++i)
    {
        temp += marksYear[i];
    }
    return (temp / 9);
}