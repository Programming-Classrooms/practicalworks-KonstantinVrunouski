#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Person.hpp"
#include <cstring>

class Professor : public Person
{
private:
    char* department;

public:
    Professor();
    Professor(const char*, const char*);
    Professor(const Professor&);
    Professor(Professor&&);

    ~Professor();

    void setDepartment(const char*);

    char* getDepartment();

    void print(std::ostream&);
};
#endif