/*
    1.Написать программу, которая для заданного натурального числа:
    проверяет, различны ли цифры в записи числа (массив и строки не использовать)
*/


#include <iostream>


int32_t getNumber()
{
	int32_t num;
	std::cout << "Input number:\n";
	std::cin >> num;
	if (num <= 0){
		throw "Not a natural number.";
	}
	return num;
}

bool findReappearingDigits(int32_t num)
{
	int32_t cnt;
	for (size_t i = 0; i <= 9; i++){
		cnt = 0;
		while (num != 0){
			if (num % 10 == i){
				cnt++;
			}
			num /= 10;
		}
		if (cnt >= 2){
			return true;
		}
	}
	return false;
}

void output(bool dubl)
{
	if (dubl)
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
	int32_t num = 0;
	bool dubl;
	try
	{
		num = getNumber();
		dubl = findReappearingDigits(num);
		output(dubl);
	}
	catch(const char* e)
	{
		std::cout << e;
	}
	return 0;
}
