#define _CRT_SECURE_NO_WARNINGS
#include "MyString.hpp"

MyString::MyString()
{
	str = nullptr;
	len = 0;
}

MyString::MyString(const char* ptr) : len(strlen(ptr)), str(new char[len + 1])
{
	strcpy(str, ptr);
}

MyString::MyString(const MyString& t) : len(strlen(t.str)), str(new char[len + 1])
{
	strcpy(str, t.str);
}

MyString& MyString::operator = (const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return (*this);
}

MyString& MyString::operator = (MyString& t)
{
	len = std::move(t.len);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, t.str);
	return (*this);
}

MyString& MyString::operator += (const MyString& t)
{
	size_t newLen = len + t.len;
	char* newStr = new char[newLen + 1];
	strcpy(newStr, str);
	strcat(newStr, t.str);
	delete[] str;
	str = newStr;
	len = newLen;
	return *this;
}

MyString& MyString::operator += (const char t)
{
	size_t newLen = len + 1;
	char* newStr = new char[newLen + 1];
	strcpy(newStr, str);
	newStr[newLen - 1] = t;
	delete[] str;
	str = newStr;
	len = newLen;
	return *this;
}

bool MyString::operator == (const MyString& t) 
{
	return !strcmp(str, t.str);
}

bool MyString::operator != (const MyString& t) 
{
	return !(operator == (t));
}

std::ostream& operator << (std::ostream& os, const MyString& s)
{
	os << s.str;
	return os;
}

std::istream& operator >> (std::istream& is, MyString& s)
{
	const size_t limit = 254;
	char temp[limit + 1];
	is.get(temp, limit);
	if (is)
	{
		s = temp;
	}
}

bool operator < (const MyString& st1, const MyString& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator > (const MyString& st1, const MyString& st2)
{
    return (std::strcmp(st1.str, st2.str) > 0);
}

bool MyString::isEmpty() 
{
	return str == nullptr || str[0] == '\0';
}

const char* MyString::getStr() 
{
	MyString tmp = (*this);
	return tmp.str;
}

size_t MyString::getLength()
{
	return len;
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
        if (str[j] == ch)
            ++counter;

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
    return str[i];
}

MyString& operator+(const MyString& st1, const MyString& st2)
{
    MyString tmp;                         
    tmp.len = st1.len + st2.len;        
    tmp.str = new char[tmp.len + 1];  

    delete[] tmp.str;                   
    std::strcpy(tmp.str, st1.str);
    std::strcpy(tmp.str + st1.len, st2.str);
    return tmp;
}

MyString::~MyString()
{
	len = 0;
	delete[] str;
	str = 0;
}
