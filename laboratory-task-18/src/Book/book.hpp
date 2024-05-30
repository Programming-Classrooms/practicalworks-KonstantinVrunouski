#ifndef BOOK_HPP
#define BOOK_HPP


#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>


class Book
{
private:
    std::string ISBN;
    std::string title;
    std::vector<std::string> authors;
    double price;
    size_t count;

    static std::string uniqueStr;

    std::string uniqueStrIncr();

    Book();

public:
    Book( 
        const std::string&, 
        const std::vector<std::string>&, 
        const double, 
        const size_t
        );
    Book(const Book&);
    
    ~Book() = default;

    Book& operator=(const Book&);

    std::string getISBN() const;
    std::string getTitle() const;
    std::vector<std::string> getAuthors() const;
    double getPrice() const;
    size_t getCount() const ;

    void setTitle(const std::string&);
    void setAuthors(const std::vector<std::string>&);
    void setPrice(const double);
    void setCount(const size_t);

    bool operator==(const Book&);

    friend std::ostream& operator<<(std::ostream&, const Book&);

    void addAuthor(const std::string&);

    void removeAuthor();
};


#endif