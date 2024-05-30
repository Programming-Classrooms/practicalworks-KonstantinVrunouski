#ifndef TIME_HPP
#define TIME_HPP


#include <iostream>


class Time
{
private:
	size_t hours;
	size_t minutes;

	size_t timeCalc() const;

public:
	Time();
	Time(const size_t, const size_t);
	~Time() {}
	
	bool operator<(const Time&) const;
	bool operator!=(const Time&) const;

	Time& operator=(const Time&);

	friend std::istream& operator>>(std::istream&, Time&);
	friend std::ostream& operator<<(std::ostream&, const Time&);
};


#endif