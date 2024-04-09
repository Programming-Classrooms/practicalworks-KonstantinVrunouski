#include "Person.hpp"
#include <iostream>
#include <cstring>

Person::Person() : fullName(new char[1])
{}

Person::Person(const char* rhs)
{
    if (rhs == nullptr)
    {
        throw std::invalid_argument("Pointer is NULL.");
    }
    fullName = new char[strlen(rhs)];
    strcpy(fullName, rhs);
}

Person::Person(const Person& rhs)
{
    delete[] fullName;
    fullName = new char[strlen(rhs.fullName)];
    strcpy(fullName, rhs.fullName);
}

Person::Person(Person&& rhs)
{
    std::swap(fullName, rhs.fullName);
}

Person::~Person()
{
    delete[] fullName;
}

char* Person::getName()
{
    char* temp;
    temp = new char[strlen(fullName)];
    strcpy(temp, fullName);
    return temp;
}

void Person::setName(const char* rhs)
{
    if (rhs == nullptr)
    {
        throw std::invalid_argument("Pointer is NULL.");
    }
    delete[] fullName;
    fullName = new char[strlen(rhs)];
    strcpy(fullName, rhs);
}

void Person::print(std::ostream& out)
{
    out << "Full name:\n" << fullName << '\n';
}