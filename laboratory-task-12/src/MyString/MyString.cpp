#define _CRT_SECURE_NO_WARNINGS
#include "MyString.hpp"

MyString::MyString() : len(0), str(new char[1])
{}

MyString::MyString(const char* ptr) : len(strlen(ptr)), str(new char[len + 1])
{
	strcpy(str, ptr);
}

MyString::MyString(const MyString& origin) : len(strlen(origin.str)), str(new char[len + 1])
{
	strcpy(str, origin.str);
}

MyString::MyString(MyString&& origin)
{
	std::swap(this->len, origin.len);
	std::swap(this->str, origin.str);
}

MyString::~MyString()
{
	delete[] str;
	len = 0;
	str = nullptr;
}


const char* MyString::getStr() 
{
	char* tmpStr = new char[this->len + 1];
	std::strcpy(tmpStr, this->str);
	return tmpStr;
}

size_t MyString::getLength()
{
	return len;
}


void MyString::setStr(const char* rhs)
{
	delete[] this->str;

	this->len = std::strlen(rhs);
	this->str = new char[this->len + 1];

	std::strcpy(this->str, rhs);
}


MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs)
	{
		delete[] this->str;

		this->len = rhs.len;
		this->str = new char[this->len + 1];
		std::strcpy(this->str, rhs.str);
		
		return (*this);
	}
}

MyString MyString::operator+(const MyString& rhs)
{
    MyString tmp;                         
    tmp.len = this->len + rhs.len;        
    tmp.str = new char[tmp.len + 1];  

    std::strcpy(tmp.str, this->str);
    std::strcat(tmp.str, rhs.str);

    return tmp;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	return *this = *this + rhs;
}


bool MyString::operator==(const MyString& rhs) 
{
	return !std::strcmp(str, rhs.str);
}

bool MyString::operator!=(const MyString& rhs) 
{
	return !(*this == rhs);
}

bool MyString::operator<(const MyString& rhs)
{
    return (std::strcmp(this->str, rhs.str) < 0);
}

bool MyString::operator>(const MyString& rhs)
{
    return (*this != rhs && !(*this < rhs));
}

bool MyString::operator<=(const MyString& rhs)
{
    return !(*this > rhs);
}

bool MyString::operator>=(const MyString& rhs)
{
    return !(*this < rhs);
}


bool MyString::isEmpty() 
{
	return (this->str == nullptr || this->str[0] == '\0');
}

void MyString::stringToLow()
{
    for (size_t i = 0; i < len; ++i)
        str[i] = (char)tolower(str[i]);
}


void MyString::stringToUp()
{
    for (size_t i = 0; i < len; ++i)
        str[i] = (char)toupper(str[i]);
}

size_t MyString::count(char ch) const
{
    size_t counter = 0;
    
	for (size_t j = 0; j < len; ++j)
	{
        if (str[j] == ch)
        {
		    ++counter;
		}
	}

    return counter;
}

int64_t MyString::findFirst(const char ch)
{
	for (size_t i = 0; i < len; ++i)
	{
		if (str[i] == ch)
		{
			return i;
		}
	}

	return -1;
}

int64_t MyString::findLast(const char ch)
{
	for (int64_t i = len - 1; i >= 0; --i)
	{
		if (str[i] == ch)
		{
			return i;
		}
	}

	return -1;
}

char MyString::operator[](size_t i)
{
	if (i >= len)
	{
		throw std::invalid_argument("Index out of range.");
	}

    return this->str[i];
}


std::ostream& operator << (std::ostream& os, const MyString& rhs)
{
	os << rhs.str;
	return os;
}

std::istream& operator >> (std::istream& is, MyString& rhs)
{
	const size_t limit = 254;
	char temp[limit + 1];
	is.get(temp, limit);
	
	if (is)
	{
		rhs = temp;
	}

	return is;
}
