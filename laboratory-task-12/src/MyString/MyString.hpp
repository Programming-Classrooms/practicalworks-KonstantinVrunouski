#ifndef MYSTRING_HPP
#define MYSTRING_HPP
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
	MyString(MyString&&);
	
	~MyString(); 

	size_t getLength(); 
	const char* getStr();

	void setStr(const char*);

	MyString& operator=(const MyString&); 

	MyString operator+(const MyString&);
	MyString& operator+=(const MyString&);
	
	bool operator == (const MyString&); 
	bool operator != (const MyString&); 
	bool operator<(const MyString&);
	bool operator>(const MyString&);
	bool operator<=(const MyString&);
	bool operator>=(const MyString&);
	
	bool isEmpty(); 
	char operator [] (size_t);
	
	int64_t findFirst(const char); 
	int64_t findLast(const char); 
	
	void stringToLow();
	void stringToUp();
	
	size_t count(char) const;
	
	friend std::ostream& operator << (std::ostream&, const MyString&);
	friend std::istream& operator >> (std::istream&, MyString&);
};
#endif
