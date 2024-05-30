#include "author.hpp"

Author::Author() : name(std::string()), surname(std::string()), patronymic(std::string())
{}

Author::Author(
    const std::string& newName, 
    const std::string& newSurname, 
    const std::string& newPatronymic)
{
    if (newName.empty() || newSurname.empty() || newPatronymic.empty())
    {
        throw std::invalid_argument("Invalid author.");
    }

    name = newName;
    surname = newSurname;
    patronymic = newPatronymic;
}

Author::Author(const Author& rhs) : name(rhs.name), surname(rhs.surname), patronymic(rhs.patronymic)
{}

Author &Author::operator=(const Author & rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        surname = rhs.surname;
        patronymic = rhs.patronymic;
    }

    return *this;
}

std::string Author::getName()
{
    return name;
}

std::string Author::getSurname()
{
    return surname;
}

std::string Author::getPatronymic()
{
    return patronymic;
}

void Author::setName(const std::string& newName)
{
    if (newName.empty())
    {
        throw std::invalid_argument("Empty name.");
    }

    name = newName;
}

void Author::setSurname(const std::string& newSurname)
{
    if (newSurname.empty())
    {
        throw std::invalid_argument("Empty surname.");
    }

    surname = newSurname;
}

void Author::setPatronymic(const std::string& newPatronymic)
{
        if (newPatronymic.empty())
    {
        throw std::invalid_argument("Empty patronymic.");
    }

    patronymic = newPatronymic;
}

bool Author::operator==(const Author & rhs) const
{
    return (name == rhs.name && surname == rhs.surname && patronymic == rhs.patronymic);
}

bool Author::operator<(const Author& rhs) const
{
    return name < rhs.name;
}

std::ostream& operator<<(std::ostream& out, const Author& rhs)
{
    out << "Name: " << rhs.name;
    out << "\nSurname: " << rhs.surname;
    out << "\nPatronymic: " << rhs.patronymic;
    return out;
}
