#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

class Person {
protected:
    char* fullName;

public:
    Person();
    Person(const char* newName);
    Person(const Person&);
    Person(Person&&);

    virtual ~Person();

    void setName(const char*);
    char* getName();

    virtual void print(std::ostream&);
};

#endif
