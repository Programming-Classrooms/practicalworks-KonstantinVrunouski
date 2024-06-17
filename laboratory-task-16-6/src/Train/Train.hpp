#ifndef TRAIN_HPP
#define TRAIN_HPP


#include <iostream>
#include <string>
#include <fstream>
#include "../Time/Time.hpp"


enum class TrainType {Passenger, Fast};

class Train
{
private:
	size_t number;
	std::string destination;
	TrainType type;
	Time startTime;
	Time onTheWayTime;

public:
	Train();
	Train(const size_t, const std::string&, const TrainType&, const Time&, const Time&);
	Train(const Train&);
	~Train() {}

	size_t getNumber() const;
	std::string getDestination() const;
	TrainType getType() const;
	Time getStartTime() const;
	Time getOnTheWayTime() const;

	void setNumber(const int32_t);
	void setDestination(const std::string&);
	void setType(const TrainType&);
	void setStartTime(const Time&);
	void setOnTheWayTime(const Time&);

	Train& operator=(const Train&);

	friend std::istream& operator>>(std::istream&, Train&);
	friend std::ostream& operator<<(std::ostream&, Train&);
};


#endif