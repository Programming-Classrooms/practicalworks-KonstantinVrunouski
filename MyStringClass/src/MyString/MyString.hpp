#ifndef MYSTRING.HPP
#define MYSTRING.HPP
#include <iostream>
#include <cstring>

class MyString
{
private:
	size_t len;
	char* str;
public:
	MyString();	
	MyString(const char*); 
	MyString(const MyString&); 
	MyString& operator = (MyString&); 
	MyString& operator=(const char*);
	friend MyString& operator+(const MyString&, const MyString&);
	MyString& operator += (const MyString&);
	MyString& operator += (const char);
	bool operator == (const MyString&); 
	bool operator != (const MyString&); 
	friend bool operator<(const MyString&, const MyString&);
	friend bool operator>(const MyString&, const MyString&);
	friend std::ostream& operator << (std::ostream&, const MyString&);
	friend std::istream& operator >> (std::istream&, MyString&);
	bool isEmpty(); 
	const char* getStr(); 
	size_t getLength(); 
	char operator [] (size_t);
	int64_t findFirst(const char); 
	int64_t findLast(const char); 
	void stringToLow();
	void stringToUp();
	size_t count(char) const;
	~MyString(); 
};
#endif
