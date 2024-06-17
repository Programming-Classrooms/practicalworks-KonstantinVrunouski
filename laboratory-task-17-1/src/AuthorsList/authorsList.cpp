#include "authorsList.hpp"

AuthorsList::AuthorsList() : authors(std::set<Author>()), size(0)
{}

AuthorsList::AuthorsList(const std::set<Author>& newAuthors) : authors(newAuthors), size(newAuthors.size())
{}

AuthorsList::AuthorsList(const AuthorsList& origin) : authors(origin.authors), size(origin.size)
{}

AuthorsList &AuthorsList::operator=(const AuthorsList& rhs)
{
    if (this != &rhs)
    {
        authors = rhs.authors;
        size = rhs.size;
    }

    return *this;
}

std::set<Author> AuthorsList::getAuthors()
{
    return authors;
}

size_t AuthorsList::getSize()
{
    return size;
}

void AuthorsList::setAuthors(const std::set<Author>& newAuthors)
{
    authors = newAuthors;
    size = newAuthors.size();
}

bool AuthorsList::operator==(const AuthorsList& rhs) const
{
    return authors == rhs.authors;
}

void AuthorsList::addAuthor(const Author& newAuthor)
{
    authors.insert(newAuthor);
}

void AuthorsList::deleteAuthor()
{
    authors.clear();
}

std::ostream &operator<<(std::ostream& out, const AuthorsList& rhs)
{
    for (const Author& i : rhs.authors)
    {
        out << i << '\n';
    }
    return out;
}
