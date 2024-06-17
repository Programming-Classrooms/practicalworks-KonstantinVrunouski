#ifndef LIBRARY_HPP
#define LIBRARY_HPP


#include <algorithm>
#include "../Book/book.hpp"


class Library
{
private:
    std::vector<Book> bookList;

public:
    Library();
    Library(const std::vector<Book>&);
    Library(const Library&);

    ~Library() = default;

    Library& operator=(const Library&);

    std::vector<Book> getBookList();

    void setBookList(const std::vector<Book>&);

    void addBook(const Book&);

    size_t findBook(const std::string&);

    void removeBook(const std::string&);

    void browse();

    void addAuthor(const std::string&, const std::string&);

    void removeAuthor(const std::string&);

    void sortByISBN();

    void sortByTitle();
};


#endif