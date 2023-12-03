/*
Нет доступа к условию.
*/

#include <iostream>

int32_t getNumber(int32_t num)
{
	std::cout << "Input number:\n";
	std::cin >> num;
	if (num <= 0)
	{
		throw std::exception("Not a natural number.");
	}
	return num;
}

bool findReappearingDigits(int32_t num, int32_t temp, int32_t cnt, bool dubl)
{
	for (size_t i = 0; i <= 9; i++)
	{
		temp = num;
		cnt = 0;
		while (temp != 0)
		{
			if (temp % 10 == i)
			{
				cnt++;
			}
			temp /= 10;
		}
		if (cnt >= 2)
		{
			dubl = true;
			break;
		}
	}
	return dubl;
}

void output(bool dubl)
{
	if (dubl == true)
	{
		std::cout << "There are duplicates.";
	}
	else
	{
		std::cout << "There are no duplicates.";
	}
}

int main()
{
	int32_t num, temp, cnt = 0;
	bool dubl = false;
	try
	{
		num = getNumber(num);
		dubl = findReappearingDigits(num, temp, cnt, dubl);
		output(dubl);
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
	return 0;
}