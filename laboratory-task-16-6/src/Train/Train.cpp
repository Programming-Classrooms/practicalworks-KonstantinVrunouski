#include "Train.hpp"


std::istream& operator>>(std::istream& in, TrainType& type)
{
	std::string temp;
	in >> temp;
	if (!in.fail())
	{
		if (temp == "Passenger")
		{
			type = TrainType::Passenger;
			return in;
		}
		if (temp == "Fast")
		{
			type = TrainType::Fast;
			return in;
		}
		throw std::invalid_argument("Invalid train type.");
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, TrainType type)
{
	switch (type)
	{
	case TrainType::Passenger:
		out << "Passenger";
		break;
	case TrainType::Fast:
		out << "Fast";
		break;
	}
	return out;
}

Train::Train() : number(0), 
				 destination(std::string("NaN")), 
				 type(TrainType::Passenger),
				 startTime(Time()),
				 onTheWayTime(Time())
{}

Train::Train(const size_t num, const std::string& dest, const TrainType& newType, const Time& stTime, const Time& newOnTheWayTime)
{
	number = num;
	
	if (dest.size() == 0)
	{
		throw std::invalid_argument("Invalid destination.");
	}
	destination = dest;

	type = newType;
	
	startTime = stTime;
	
	onTheWayTime = newOnTheWayTime;
}

Train::Train(const Train& origin)
{
	number = origin.number;
	destination = origin.destination;
	type = origin.type;
	startTime = origin.startTime;
	onTheWayTime = origin.onTheWayTime;
}

size_t Train::getNumber() const
{
	return number;
}

std::string Train::getDestination() const
{
	return destination;
}

Time Train::getStartTime() const
{
	return startTime;
}

TrainType Train::getType() const
{
	return type;
}

Time Train::getOnTheWayTime() const
{
	return onTheWayTime;
}

void Train::setNumber(const int32_t num)
{
	number = num;
}

void Train::setDestination(const std::string& newDest)
{
	destination = newDest;
}

void Train::setType(const TrainType& newType)
{
	type = newType;
}

void Train::setStartTime(const Time& newStTime)
{
	startTime = newStTime;
}

void Train::setOnTheWayTime(const Time& newTime)
{
	onTheWayTime = newTime;
}

Train& Train::operator=(const Train& origin)
{
	number = origin.number;
	destination = origin.destination;
	type = origin.type;
	startTime = origin.startTime;
	onTheWayTime = origin.onTheWayTime;
	return *this;
}

std::istream& operator>>(std::istream& in, Train& rhs)
{
	in >> rhs.number;
	in >> rhs.destination;
	in >> rhs.type;
	in >> rhs.startTime;
	in >> rhs.onTheWayTime;
	return in;
}

std::ostream& operator<<(std::ostream& out, Train& rhs)
{
	out << "\nNumber: " << rhs.number;
	out << "\nDestination: " << rhs.destination;
	out << "\nType: " << rhs.type;
	out << "\nStart time: " << rhs.startTime;
	out << "\nOn the way: " << rhs.onTheWayTime << '\n';
	return out;
}
