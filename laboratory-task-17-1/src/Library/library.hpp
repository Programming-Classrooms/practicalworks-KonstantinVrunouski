#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "../Book/book.hpp"

class Library
{
private:
    std::set<Book> books;

public:
    Library();
    Library(const std::set<Book>&);
    Library(const Library&);

    ~Library() = default;

    Library& operator=(const Library&);

    std::set<Book> getBooks();

    void setBooks(const std::set<Book>&);

    void addBook(const Book&);

    void deleteBook(const Book&);

    Book findByTitle(const std::string&) const;
    
    void findByAuthor(const Author&) const;

    void addAuthor(const Book&, const Author&);

    void deleteAuthor(const Book&);

};


#endif