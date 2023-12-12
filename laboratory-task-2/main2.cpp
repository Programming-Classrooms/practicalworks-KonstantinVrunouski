/*
14. числа, у которых сумма цифр равна квадрату максимальной
цифры; (22, 112, 333, 233)
*/

#include <iostream>

void getBorders(int32_t& num_left_border, int32_t& num_right_border)
{
	std::cout << "Input left and right borders(Natural; Left border less than right border):\n";
	std::cin >> num_left_border >> num_right_border;
	if (num_left_border <= 0 || num_right_border <= 0)
	{
		throw std::exception("Invalid input. Check borders and restart the program.");
	}
}

void findNumSumDigitsMoreSquare(int32_t num_left_border, int32_t num_right_border)
{
	int32_t temp, max, digits_sum;
	bool is_out;
	for (size_t i = num_left_border; i <= num_right_border; i++)
	{
		temp = i, max = 0, digits_sum = 0;
		while (temp != 0)
		{
			if (max < temp % 10)
			{
				max = temp % 10;
			}
			digits_sum += temp % 10;
			temp /= 10;
		}
		if (digits_sum == max * max)
		{
			std::cout << i << '\t';
			is_out = true;
		}
	}
	if (!is_out)
	{
		std::cout << "No such numbers";
	}
}

int main()
{
	try
	{
		int32_t num_left_border, num_right_border, digits_sum = 0, temp, max;
		bool is_out = false;
		getBorders(num_left_border, num_right_border);
		if (num_right_border < num_left_border)
		{
			std::swap(num_left_border, num_right_border);
		}
		findNumSumDigitsMoreSquare(num_left_border, num_right_border);
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
	return 0;
}