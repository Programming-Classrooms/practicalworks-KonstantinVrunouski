#include "../Train/Train.hpp"
#include <vector>
#include <algorithm>

void printInRangeStTime(const std::vector<Train>& arr, const Time& lBord, const Time& rBord)
{
	for (Train i : arr)
	{
		if (i.getStartTime() < rBord && lBord < i.getStartTime())
		{
			std::cout << i;
		}
	}
}

void findFirstTrainWithDest(const std::vector<Train>& arr, const std::string dest)
{
	for (Train i : arr)
	{
		if (i.getDestination() == dest)
		{
			std::cout << i;
			return;
		}
	}
}

struct
{
	bool operator()(Train& a, Train& b) const 
	{ 
		return a.getStartTime() < b.getStartTime(); 
	}
} sortStartTime;

struct
{
	bool operator()(Train& a, Train& b) const
	{
		return a.getOnTheWayTime() < b.getOnTheWayTime();
	}
} sortOnTheWayTime;

int main()
{
	std::ifstream in("src/files/input.txt");
	
	Train temp;
	std::vector<Train> arr;
	while (in >> temp)
	{
		arr.push_back(temp);
	}
	in.close();

	std::sort(arr.begin(), arr.end(), sortStartTime);
	
	std::cout << "Input time boundaries:\n";
	Time lBord, rBord;
	std::cin >> lBord >> rBord;

	std::cout << "\nTrains in that time range:\n";
	printInRangeStTime(arr, lBord, rBord);
	

	std::cout << "\nInput destination:\n";
	std::string tempDest;
	std::cin >> tempDest;

	std::cout << "\nTrains with that destination:\n";
	for (Train& i : arr)
	{
		if (i.getDestination() == tempDest)
		{
			std::cout << i;
		}
	}


	std::cout << "\nInput destination:\n";
	std::cin >> tempDest;

	std::cout << "\nFast trains with that destination:\n";
	for (Train& i : arr)
	{
		if (i.getDestination() == tempDest && i.getType() == TrainType::Fast)
		{
			std::cout << i;
		}
	}

	std::sort(arr.begin(), arr.end(), sortOnTheWayTime);

	std::cout << "\nInput destination:\n";
	std::cin >> tempDest;

	std::cout << "\nFastest train with that destination:\n";
	findFirstTrainWithDest(arr, tempDest);

	return 0;
}
