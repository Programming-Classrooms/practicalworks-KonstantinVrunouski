#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <cstring>
#include <iostream>


class Author
{
protected:
    std::string name;
    std::string surname;
    std::string patronymic;

public:
    Author();
    Author(const std::string&, const std::string&, const std::string&);
    Author(const Author&);

    ~Author() = default;

    Author& operator=(const Author&);

    std::string getName();
    std::string getSurname();
    std::string getPatronymic();

    void setName(const std::string&);
    void setSurname(const std::string&);
    void setPatronymic(const std::string&);

    bool operator==(const Author&) const;

    bool operator<(const Author&) const;
    
    friend std::ostream& operator<<(std::ostream&, const Author&);
};


#endif
