/*
	Вариант 18
	В одномерном массиве, состоящем из п целых элементов, вычислить:
	- количество различных элементов.
	- произведение элементов массива, расположенных после максимального по модулю
	элемента.
	Преобразовать массив таким образом, чтобы сначала располагались все отрицательные
	элементы, а потом — все положительные (элементы, равные 0, считать положительными).
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


int32_t inputSize()
{
	int32_t size = 0;
	std::cout << "Elements quantity:\n";
	std::cin >> size;
	if (size <= 0)
	{
		throw "Invalid quantity.";
	}
	return size;
}

bool inputType()
{
	bool ans;
	std::cout << "Input manually or randomly?\n0) Manual; 1) Random\n";
	std::cin >> ans;
	if (!ans && ans){
		throw "Invalid choice.";
	}
	return ans;
}

void inputArrayManual(int32_t size)
{
	int32_t* arr = new int32_t[size];
	std::cout << "Input elements:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
}

void inputArrayRandom(int32_t size)
{
	int32_t* arr = new int32_t[size];
	int32_t lBord, rBord;
	std::cout << "Input range of random numbers:\n";
	std::cin >> lBord >> rBord;
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = lBord + rand() % (rBord - lBord + 1);
	}
}


int32_t findingMaxIndex(int32_t* arr, int32_t size)
{
	int32_t maxNum = arr[0], maxNumIndex = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > maxNum)
		{
			maxNum = arr[i];
			maxNumIndex = i;
		}
	}
	return maxNumIndex;
}

int32_t calcMultiplicationResult(int32_t* arr, int32_t size, int32_t maxNumIndex)
{
	double multiplicationResult = 1;
	if (maxNumIndex == size - 1)
	{
		return 0;
	}
	else
	{
		for (size_t i = maxNumIndex + 1; i < size; ++i)
		{
			multiplicationResult *= arr[i];
		}
		return multiplicationResult;
	}
}

int32_t countDistinct(int32_t* arr, int32_t n)
{
	int32_t counter = 1;

	for (size_t i = 1; i < n; ++i) {
		size_t j = 0;
		for (j = 0; j < i; ++j)
			if (arr[i] == arr[j])
				break;

		if (i == j)
			counter++;
	}
	return counter;
}

void startingArray(int32_t* arr, int32_t size)
{
	std::cout << "Starting array:\n";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	return;
}



void print(int32_t* arr, int32_t size, int32_t maxNumIndex, int32_t multiplicationResult)
{
	std::cout << "\nNumber of the unique elements and result of multiplication of the elements after maximum:\n" << countDistinct(arr, size) << '\t' << multiplicationResult << '\n' << "Sorted array:\n";

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	return;
}

int main()
{
	srand(time(NULL));

	try
	{
		int32_t size = inputSize();
		bool inType = inputType();
		int32_t* arr = new int32_t[size];		
		if (!inType)
		{
			inputArrayManual(size);
		}
		else
		{
			inputArrayRandom(size);
		}

		
		startingArray(arr, size);

		int32_t maxNumIndex = findingMaxIndex(arr, size);

		int32_t multiplicationResult = calcMultiplicationResult(arr, size, maxNumIndex);

		arr = bubbleSort(arr, size);

		print(arr, size, maxNumIndex, multiplicationResult);

		delete[] arr;
	}
	catch(const char* e)
	{
		std::cout << e << '\n';
	}
	return 0;
}
