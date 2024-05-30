#include "../LibClass/library.hpp"
#include "library.hpp"


Library::Library() : bookList(std::vector<Book>())
{}

Library::Library(const std::vector<Book>& newBookList) : bookList(newBookList)
{}

Library::Library(const Library& origin) : bookList(origin.bookList)
{}

Library& Library::operator=(const Library& rhs)
{
    if (this != &rhs)
    {
        bookList = rhs.bookList;
    }

    return *this;
}

std::vector<Book> Library::getBookList()
{
    return bookList;
}

void Library::setBookList(const std::vector<Book>& newBookList)
{
    bookList = newBookList;
}

void Library::addBook(const Book& newBook)
{
    for (size_t i = 0; i < bookList.size(); ++i)
    {
        if (bookList[i] == newBook)
        {
            bookList[i].setCount(bookList[i].getCount() + 1);
            return;
        }
    }

    bookList.push_back(newBook);
}

size_t Library::findBook(const std::string& ISBNtoFind)
{
    for (size_t i = 0; i < bookList.size(); ++i)
    {
        if (bookList[i].getISBN() == ISBNtoFind)
        {
            return i;
        }
    }

    throw std::invalid_argument("There is no such book.");
}

void Library::removeBook(const std::string& ISBNtoFind)
{
    size_t i = findBook(ISBNtoFind);

    if (bookList[i].getCount() == 1)
    {
        bookList.erase(bookList.begin() + i);
        return;
    }

    bookList[i].setCount(bookList[i].getCount() - 1);
}

void Library::browse()
{
    std::cout << "Books in library:\n";
    for (Book& i : bookList)
    {
        std::cout << i << '\n';
    }
}

void Library::addAuthor(const std::string& IBSNtoFind, const std::string& newAuthor)
{
    bookList[findBook(IBSNtoFind)].addAuthor(newAuthor);
}

void Library::removeAuthor(const std::string& ISBNtoFind)
{
    bookList[findBook(ISBNtoFind)].removeAuthor();
}

void Library::sortByISBN()
{
    std::sort(bookList.begin(), bookList.end(), [](Book& a, Book& b) {return (a.getISBN() < b.getISBN());});
}

void Library::sortByTitle()
{
    std::sort(bookList.begin(), bookList.end(), [](Book& a, Book& b) {return (a.getTitle() < b.getTitle());});
}
