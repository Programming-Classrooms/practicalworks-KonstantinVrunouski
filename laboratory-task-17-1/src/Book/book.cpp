#include "book.hpp"

Book::Book() : UDC(0), title(std::string()), authors(AuthorsList()), releaseYear(0)
{}

Book::Book(
    const size_t newUDC, 
    const std::string& newTitle, 
    const AuthorsList& newAuthors, 
    const size_t newReleaseYear)
{
    if (newUDC < 0 || newReleaseYear < 0)
    {
        throw std::invalid_argument("Invalid book.");
    }

    UDC = newUDC;
    title = newTitle;
    authors = newAuthors;
    releaseYear = newReleaseYear;
}

Book::Book(const Book& origin) : 
    UDC(origin.UDC), 
    title(origin.title), 
    authors(origin.authors),
    releaseYear(origin.releaseYear)
{}

Book& Book::operator=(const Book& rhs)
{
    if (this != &rhs)
    {
        UDC = rhs.UDC;
        title = rhs.title;
        authors = rhs.authors;
        releaseYear = rhs.releaseYear;
    }

    return *this;
}

size_t Book::getUDC() const
{
    return UDC;
}

std::string Book::getTitle() const
{
    return title;
}

AuthorsList Book::getAuthors() const
{
    return authors;
}

size_t Book::getReleaseYear() const
{
    return releaseYear;
}

void Book::setUDC(const size_t newUDC)
{
    if (newUDC < 0)
    {
        throw std::invalid_argument("Invalid UDC.");
    }

    UDC = newUDC;
}

void Book::setTitle(const std::string& newTitle)
{
    title = newTitle;
}

void Book::setAuthors(const AuthorsList& newAuthors)
{
    authors = newAuthors;
}

void Book::setReleaseYear(const size_t newReleaseYear)
{
    releaseYear = newReleaseYear;
}

bool Book::operator==(const Book& rhs) const
{
    return (UDC == rhs.UDC && title == rhs.title && authors == rhs.authors && releaseYear && rhs.releaseYear);
}

bool Book::operator<(const Book& rhs) const
{
    return (UDC < rhs.UDC);
}

std::ostream& operator<<(std::ostream& out, const Book& rhs)
{
    out << "UDC: " << rhs.UDC;
    out << "\nTitle: " << rhs.title;
    out << "\nAuthors:\n" << rhs.authors;
    out << "\nRelease year: " << rhs.releaseYear << '\n';
    return out; 
}
