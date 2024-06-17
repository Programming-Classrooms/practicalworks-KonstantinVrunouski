#include "Professor.hpp"

Professor::Professor() : Person(), department(new char[1])
{}

Professor::Professor(const char* newName, const char* newDepartment) : Person(newName)
{
    if (newDepartment == nullptr)
    {
        throw std::invalid_argument("Pointer is NULL.");
    }
    department = new char[strlen(newDepartment)];
    strcpy(department, newDepartment);
}

Professor::Professor(const Professor& rhs) : Person(rhs)
{
    department = new char[strlen(rhs.department)];
    strcpy(department, rhs.department);
}

Professor::Professor(Professor&& rhs) : Person(rhs)
{
    std::swap(department, rhs.department);
}

Professor::~Professor()
{
    delete[] department;
}

void Professor::setDepartment(const char* rhs)
{
    if (rhs == nullptr)
    {
        throw std::invalid_argument("Pointer is NULL.");
    }
    delete[] department;
    department = new char[strlen(rhs)];
    strcpy(department, rhs);
}

char* Professor::getDepartment()
{
    char* temp;
    temp = new char[strlen(department)];
    strcpy(temp, department);
    return temp;
}

void Professor::print(std::ostream& out)
{
    Person::print(out);
    out << "Department:\n" << department << '\n';
}