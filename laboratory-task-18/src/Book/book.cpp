#include "../Book/book.hpp"
#include "book.hpp"

std::string Book::uniqueStr = "@AAAAAAAAAAAA"; // size = 13

std::string Book::uniqueStrIncr()
{
    if (uniqueStr[12] == 'Z')
    {
        throw std::out_of_range("Too much books.");
    }

    if (uniqueStr[0] != 'Z')
    {
        ++uniqueStr[0];
        return uniqueStr;
    }

    size_t temp = 0;

    while (uniqueStr[temp] == 'Z')
    {
        uniqueStr[temp] = 'A';
        ++temp;
    }

    ++uniqueStr[temp];

    return uniqueStr;
}

Book::Book() : ISBN(std::string()),
               title(std::string()),
               authors(std::vector<std::string>()),
               price(0.0),
               count(0)
{}

Book::Book( 
    const std::string& newTitle, 
    const std::vector<std::string>& newAuthors, 
    const double newPrice, 
    const size_t newCount)
{
    if (newTitle.empty())
    {
        throw std::invalid_argument("Empty title.");
    }

    if (newAuthors.empty())
    {
        throw std::invalid_argument("No authors.");
    }

    if (newPrice <= 0)
    {
        throw std::invalid_argument("Invalid price.");
    }

    if (newCount <= 0)
    {
        throw std::invalid_argument("Invalid count.");
    }

    ISBN = uniqueStrIncr();
    title = newTitle;
    authors = newAuthors;
    price = newPrice;
    count = newCount;
}

Book::Book(const Book& origin) :
                    ISBN(origin.ISBN),
                    title(origin.title),
                    authors(origin.authors),
                    price(origin.price),
                    count(origin.count)
{}

Book& Book::operator=(const Book& rhs)
{
    if (this != &rhs)
    {
        ISBN = rhs.ISBN;
        title = rhs.title;
        authors = rhs.authors;
        price = rhs.price;
        count = rhs.count;
    }
    
    return *this;
}

std::string Book::getISBN() const
{
    return ISBN;
}

std::string Book::getTitle() const
{
    return title;
}

std::vector<std::string> Book::getAuthors() const
{
    return authors;
}

double Book::getPrice() const
{
    return price;
}

size_t Book::getCount() const
{
    return count;
}

void Book::setTitle(const std::string& rhs)
{
    if (rhs.empty())
    {
        throw std::invalid_argument("Empty title.");
    }

    title = rhs;
}

void Book::setAuthors(const std::vector<std::string>& rhs)
{
    if (rhs.empty())
    {
        throw std::invalid_argument("No authors.");
    }

    authors = rhs;
}

void Book::setPrice(const double rhs)
{
    if (rhs <= 0)
    {
        throw std::invalid_argument("Invalid price.");
    }

    price = rhs;
}

void Book::setCount(const size_t rhs)
{
    if (rhs <= 0)
    {
        throw std::invalid_argument("Invalid count");
    }

    count = rhs;
}

bool Book::operator==(const Book& rhs)
{
    return (title == rhs.title && authors == rhs.authors && price == rhs.price);
}

void Book::addAuthor(const std::string& newAuthor)
{
    for (std::string& i : authors)
    {
        if (i == newAuthor)
        {
            return;
        }
    }

    authors.push_back(newAuthor);
}

void Book::removeAuthor()
{
    authors = std::vector<std::string>{"NaN"};
}

std::ostream& operator<<(std::ostream& out, const Book& rhs)
{
    out << "ISBN: " << rhs.ISBN;
    out << "\nTitle: " << rhs.title;
    out << "\nAuthors:\n";
    for (size_t i = 0; i < rhs.authors.size(); ++i)
    {
        out << '"' << rhs.authors[i] << "\" ";
    }
    out << "\nPrice: " << rhs.price;
    out << "\nCount: " << rhs.count << '\n';
    return out;
}
