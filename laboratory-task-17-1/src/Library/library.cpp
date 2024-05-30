#include "library.hpp"

Library::Library() : books(std::set<Book>())
{}

Library::Library(const std::set<Book>& newBooks) : books(newBooks)
{}

Library::Library(const Library& origin) : books(origin.books)
{}

Library& Library::operator=(const Library& rhs)
{
    if (this != &rhs)
    {
        books = rhs.books;
    }

    return *this;
}

std::set<Book> Library::getBooks()
{
    return books;
}

void Library::setBooks(const std::set<Book>& newBooks)
{
    books = newBooks;
}

void Library::addBook(const Book& newBook)
{
    books.insert(newBook);
}

void Library::deleteBook(const Book& newBook)
{
    books.erase(books.find(newBook));
}

Book Library::findByTitle(const std::string& newTitle) const
{
    for (const Book& i : books)
    {
        if (i.getTitle() == newTitle)
        {
            return i;
        }
    }

    throw std::invalid_argument("No such book.");
}

void Library::findByAuthor(const Author& newAuthor) const
{
    for (const Book& i : books)
    {
        if (i.getAuthors().getAuthors().find(newAuthor) != i.getAuthors().getAuthors().end())
        {
            std::cout << i << '\n';
        }
    }
}

void Library::addAuthor(const Book& newBook, const Author& newAuthor)
{
    findByTitle(newBook.getTitle()).getAuthors().addAuthor(newAuthor);
}

void Library::deleteAuthor(const Book& newBook)
{
    findByTitle(newBook.getTitle()).getAuthors().deleteAuthor();    
}
