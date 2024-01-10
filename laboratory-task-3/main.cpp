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


size_t inputSize(const char* message = "Elements quantity:")
{
	size_t size = 0;
	std::cout << message << '\n';
	std::cin >> size;
	if (size <= 0){
		throw std::exception("Invalid quantity.");
	}
	return size;
}

bool inputType(const char * message = "Input manually or randomly?\n0) Manual; 1) Random")
{
	bool ans;
	std::cout << message << '\n';
	std::cin >> ans;
	if (!ans && ans){
		throw std::exception("Invalid choice.");
	}
	return ans;
}

void inputArrayManual(int32_t* arr, size_t size)
{
	std::cout << "Input elements:\n";
	for (int i = 0; i < size; ++i){
		std::cin >> arr[i];
	}
}

void inputArrayRandom(int32_t* arr, size_t size)
{
	size_t lBord, rBord;
	std::cout << "Input range of random numbers:\n";
	std::cin >> lBord >> rBord;
	for (size_t i = 0; i < size; ++i){
		arr[i] = lBord + rand() % (rBord - lBord + 1);
	}
}


size_t findingMaxNumIndex(int32_t* arr, size_t size)
{
	int32_t maxNum = arr[0]; 
	size_t maxNumIndex = 0;
	for (int i = 0; i < size; ++i){
		if (arr[i] > maxNum){
			maxNum = arr[i];
			maxNumIndex = i;
		}
	}
	return maxNumIndex;
}

int32_t calcMultiplicationResult(int32_t* arr, size_t size, size_t maxNumIndex)
{
	double multiplicationResult = 1;
	for (size_t i = maxNumIndex + 1; i < size; ++i){
		multiplicationResult *= arr[i];
	}
	return multiplicationResult;
}

size_t countDistinct(int32_t* arr, size_t n)
{
	size_t counter = 1;

	for (size_t i = 1; i < n; ++i){
		size_t j = 0;
		for (j = 0; j < i; ++j){
			if (arr[i] == arr[j]){
				break;
			}
		}
		if (i == j){
			counter++;
		}
	}
	return counter;
}

void printArray(int32_t* arr, int32_t size)
{
	std::cout << "Starting array:" << '\n';
	for (size_t i = 0; i < size; ++i){
		std::cout << arr[i] << ' ';
	}
}

void selectionSort(int32_t* arr, size_t n)
{
    size_t i, j, minInd;
 
    for (i = 0; i < n - 1; i++){
 
        minInd = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[minInd])
                minInd = j;
        }
 
        if (minInd != i){
            std::swap(arr[minInd], arr[i]);
		}
	}
}

void print(int32_t* arr, size_t size, size_t maxNumIndex, int32_t multiplicationResult)
{
	std::cout << "\nNumber of the unique elements and result of multiplication of the elements after maximum:\n" << countDistinct(arr, size);
	if (maxNumIndex != size-1){
		std::cout << '\t' << multiplicationResult << '\n'; 
	}
	else{
		std::cout << '\t' << "There's no multiplication." << '\n';
	}
	std::cout << "Sorted array:\n";
	for (size_t i = 0; i < size; ++i){
		std::cout << arr[i] << ' ';
	}
}

int main()
{
	srand(time(NULL));

	try{
		int32_t size = inputSize();
		bool inType = inputType();
		int32_t* arr = new int32_t[size];

		if (!inType){
			inputArrayManual(arr, size);
		}
		else
		{
			inputArrayRandom(arr, size);
		}

		printArray(arr, size);

		int32_t maxNumIndex = findingMaxNumIndex(arr, size);

		int32_t multiplicationResult = calcMultiplicationResult(arr, size, maxNumIndex);

		selectionSort(arr, size);

		print(arr, size, maxNumIndex, multiplicationResult);

		delete[] arr;
	}
	catch(std::exception e){
		std::cout << e.what() << '\n';
	}
	return 0;
}
