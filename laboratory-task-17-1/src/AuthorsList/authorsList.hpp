#ifndef AUTHORSLIST_HPP
#define AUTHORSLIST_HPP


#include "../Author/author.hpp"
#include <set>


class AuthorsList
{
protected:
    std::set<Author> authors;
    size_t size;

public:
    AuthorsList();
    AuthorsList(const std::set<Author>&);
    AuthorsList(const AuthorsList&);

    ~AuthorsList() = default;

    AuthorsList& operator=(const AuthorsList&);

    std::set<Author> getAuthors();
    size_t getSize();

    void setAuthors(const std::set<Author>&);

    bool operator==(const AuthorsList&) const;

    void addAuthor(const Author&);

    void deleteAuthor();

    friend std::ostream& operator<<(std::ostream&, const AuthorsList&);
};

#endif