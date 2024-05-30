#include "Time.hpp"


Time::Time() : hours(0), minutes(0)
{}

Time::Time(const size_t newHours, const size_t newMinutes)
{
	hours = (newHours + newMinutes / 60) % 24;
	minutes = newMinutes % 60;
}

bool Time::operator<(const Time& rhs) const
{
	return this->timeCalc() < rhs.timeCalc();
}

bool Time::operator!=(const Time& rhs) const
{
	return this->timeCalc() != rhs.timeCalc();
}

Time& Time::operator=(const Time& rhs)
{
	hours = rhs.hours;
	minutes = rhs.minutes;
	return *this;
}

std::istream& operator>>(std::istream& in, Time& rhs)
{
	std::string tempIn;
	in >> tempIn;
	if (!in.fail())
	{
		if (!std::isdigit(tempIn[0]) || !std::isdigit(tempIn[1]) || tempIn[2] != ':' || !std::isdigit(tempIn[3]) || !std::isdigit(tempIn[4]))
		{
			throw std::invalid_argument("Invalid time.");
		}
		rhs.hours = (tempIn[0] - '0') * 10 + tempIn[1] - '0';
		rhs.minutes = (tempIn[3] - '0') * 10 + tempIn[4] - '0';
		rhs.hours = (rhs.hours + rhs.minutes / 60) % 24;
		rhs.minutes %= 60;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Time& rhs)
{
	if (rhs.hours < 10)
	{
		out << '0';
	}
	out << rhs.hours << ':';
	if (rhs.minutes < 10)
	{
		out << '0';
	}
	out << rhs.minutes;
	return out;
}

size_t Time::timeCalc() const
{
	return hours * 100 + minutes;
}