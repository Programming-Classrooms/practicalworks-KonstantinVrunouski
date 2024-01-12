/*
    1.Написать программу, которая для заданного натурального числа:
    проверяет, различны ли цифры в записи числа (массив и строки не использовать)
*/


#include <iostream>


int32_t inputNumber(const char * message = "Input number:")
{
	int32_t num;
	
	std::cout << message << '\n';
	std::cin >> num;
	
	if (num <= 0){
		throw std::exception("Not a natural number.");
	}

	return num;
}

bool isReappearingDigits(int32_t num)
{
	int32_t cnt;
	int32_t temp;

	for (size_t i = 0; i <= 9; ++i) {
		cnt = 0;
		temp = num;
		while (temp != 0){
			if (temp % 10 == i){
				++cnt;
			}
			temp /= 10;
		}
		
		if (cnt >= 2){
			return true;
		}
	}

	return false;
}

int main()
{
	int32_t num = 0;
	bool dubl;

	try {
		num = inputNumber();
		dubl = isReappearingDigits(num);
		
		if(dubl){
			std::cout << "There are duplicates.";
		}
		else{
			std::cout << "There are no duplicates.";
		}
	}
	catch(std::exception e){
		std::cout << e.what();
	}

	return 0;
}
