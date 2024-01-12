/*
    14.Написать программу, которая на заданном отрезке [a,b] натурального ряда чисел находит:
    числа, у которых сумма цифр равна квадрату максимальной цифры.
*/


#include <iostream>


void inputBorders(int32_t& numLeftBorder, int32_t& numRightBorder, const char* message = "Input left and right borders(Natural; Left border less than right border):")
{
	std::cout << message << '\n';
	std::cin >> numLeftBorder >> numRightBorder;

	if (numLeftBorder <= 0 || numRightBorder <= 0){
		throw std::exception("Invalid input. Check borders and restart the program.");
	}
}

void isNumberWithSumOfDigitsEqualToSquareOfMaxDigit(int32_t numLeftBorder, int32_t numRightBorder)
{
	int32_t temp; 
	int32_t max; 
	int32_t digitsSum;
	bool isPrinted;

	for (size_t i = numLeftBorder; i <= numRightBorder; ++i){
		temp = i, max = 0, digitsSum = 0;
		while (temp){
			if (max < temp % 10){
				max = temp % 10;
			}
			digitsSum += temp % 10;
			temp /= 10;
		}
		if (digitsSum == max * max){
			std::cout << i << '\t';
			isPrinted = true;
		}
	}
	std::cout << '\n';
	
	if (!isPrinted){
		std::cout << "No such numbers." << '\n';
	}
}

int main()
{
	try {
		int32_t numLeftBorder; 
		int32_t numRightBorder;

		inputBorders(numLeftBorder, numRightBorder);

		if (numRightBorder < numLeftBorder){
			std::swap(numLeftBorder, numRightBorder);
		}

		isNumberWithSumOfDigitsEqualToSquareOfMaxDigit(numLeftBorder, numRightBorder);
	}
	catch (std::exception e){
		std::cout << e.what();
	}
	return 0;
}
