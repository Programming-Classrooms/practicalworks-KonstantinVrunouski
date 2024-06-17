#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <iomanip>


void selectionSort(std::vector<std::vector<int>>& arr, const size_t size)
{
	size_t max;
	std::vector<int> temp;
	for (size_t i = 0; i < size - 1; i++)
	{
		max = i; 
		
		for (size_t j = i + 1; j < size; j++)  
		{
			if (std::accumulate(arr[j].begin(), arr[j].end(), 0) > std::accumulate(arr[max].begin(), arr[max].end(), 0))
				max = j;       
		}

		if (max != i)
		{
			temp = arr[i];      
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	std::cout << "Введите кол-во столбцов и строк:\n";
	size_t cols, rows;
	std::cin >> cols >> rows;
	if (cols == 0 || rows == 0)
	{
		throw std::invalid_argument("Invalid size.");
	}

	std::cout << "Введите границы:\n";
	int lBord, rBord;
	std::cin >> lBord >> rBord;
	
	if (lBord > rBord)
	{
		throw std::invalid_argument("Invalid borders.");
	}
	
	std::vector<std::vector<int>>matrix(rows);
	
	int temp;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			temp = lBord + rand() % (rBord - lBord + 1);
			matrix[i].push_back(temp);
		}
	}
	
	size_t maxElementRow = 0, maxElementCol = 0;
	int max = matrix[0][0];
	
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
				maxElementRow = i;
				maxElementRow = j;
			}
		}
	}


	matrix[maxElementRow].erase(matrix[maxElementRow].begin() + maxElementCol);
	matrix.erase(matrix.begin() + maxElementRow);
	
	--rows;
	--cols;

	selectionSort(matrix, rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << '\n';
	}

	return 0;
}
