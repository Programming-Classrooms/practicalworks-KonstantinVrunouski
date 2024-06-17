#ifndef BOOK_HPP
#define BOOK_HPP


#include <iostream>
#include "../AuthorsList/authorsList.hpp"


class Book
{
private:
    size_t UDC;
    std::string title;
    AuthorsList authors;
    size_t releaseYear;

public:
    Book();
    Book(const size_t, const std::string&, const AuthorsList&, const size_t);
    Book(const Book&);

    ~Book() = default;

    Book& operator=(const Book&);

    size_t getUDC() const;
    std::string getTitle() const;
    AuthorsList getAuthors() const;
    size_t getReleaseYear() const;

    void setUDC(const size_t);
    void setTitle(const std::string&);
    void setAuthors(const AuthorsList&);
    void setReleaseYear(const size_t);

    bool operator==(const Book&) const;
    bool operator<(const Book&) const;

    friend std::ostream& operator<<(std::ostream&, const Book&);

};


#endif