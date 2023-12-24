/*
Вариант 1
В целочисленной квадратной матрице найти:
- максимальный элемент в тех столбцах, которые не содержат положительных
элементов;
- подсчитать количество отрицательных элементов в нижнем правом
треугольнике квадратной матрицы, включая диагональ.
*/


#include <iostream>
#include <iomanip>


size_t inputMtrxSize()
{
	size_t size;
	std::cout << "Input size of the matrix:\n";
	std::cin >> size;
	return size;
}

void allocateMemoryForMtrx(int32_t**& mtrx, size_t size)
{
	mtrx = new int32_t * [size];
	for (size_t i = 0; i < size; ++i)
	{
		mtrx[i] = new int32_t[size];
	}
}

int32_t inputType()
{
	std::cout << "How'd you like to input elements:\n1)Manually.\t2)Randomly.\n";
	int32_t inType;
	std::cin >> inType;
	if (inType != 1 && inType != 2)
	{
		throw std::exception("Invalid choice.");
	}
	return inType;
}

void mtrxFillManual(int32_t** mtrx, size_t size)
{
	std::cout << "Input elements of the matrix:\n";
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			std::cin >> mtrx[i][j];
}

void inputBorders(int32_t& lBord, int32_t& rBord)
{
	std::cout << "Input left and right border of random:\n";
	std::cin >> lBord >> rBord;
	if (lBord > rBord)
		std::swap(lBord, rBord);
}

void mtrxFillRandomly(int32_t** mtrx, size_t size)
{
	int32_t lBord, rBord;
	inputBorders(lBord, rBord);
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			mtrx[i][j] = lBord + rand() % (rBord - lBord + 1);
}

void printMtrx(int32_t** mtrx, size_t size, const char* message = "Generated matrix:")
{
	std::cout << message << '\n';
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			std::cout << std::setw(5) << mtrx[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void cleanMemory(int32_t**& mtrx, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		delete[] mtrx[i];
	delete[] mtrx;
}

bool isPositiveElementInColumn(int32_t** mtrx, size_t size, size_t col)
{
	bool isPositiveElements = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (mtrx[i][col] > 0)
		{
			isPositiveElements = true;
			break;
		}
	}
	return isPositiveElements;
}

int32_t maxElementInColumn(int32_t** mtrx, size_t size)
{
	int32_t max = INT32_MIN;
	for (size_t i = 0; i < size; ++i)
	{
		if (!isPositiveElementInColumn(mtrx, size, i))
		{
			for (size_t j = 0; j < size; ++j)
			{
				if (mtrx[j][i] > max)
					max = mtrx[j][i];
			}
		}
	}
	return max;
}

size_t countNegativeElementsInLowRightTriangle(int32_t** mtrx, size_t size)
{
	size_t k = 0, cnt = 0;
	for (int32_t i = size - 1; i >= 0; --i)
	{
		for (size_t j = k; j < size; ++j)
		{
			if (mtrx[i][j] < 0)
			{
				++cnt;
			}
		}
		k++;
	}
	return cnt;
}

void print(int32_t max, size_t cnt)
{
	if (max == INT32_MIN)
		std::cout << "There is no maximum element, that satisfies condition.\n";
	else
		std::cout << "Maximum element is " << max << ".\n";
	if (cnt != 0)
		std::cout << "Count of negative elements in right down triangle: " << cnt << ".\n";
	else
		std::cout << "There are no negative elements in right down triangle.\n";
}

int main()
{
	srand(time(NULL));
	int32_t** mtrx = nullptr;
	size_t size;
	try
	{
		size = inputMtrxSize();
		allocateMemoryForMtrx(mtrx, size);

		int32_t in_type = inputType();
		if (in_type == 1)
			mtrxFillManual(mtrx, size);
		else
			mtrxFillRandomly(mtrx, size);

		int32_t max = maxElementInColumn(mtrx, size);
		
		size_t cnt = countNegativeElementsInLowRightTriangle(mtrx, size);
		
		if (in_type != 1)
			printMtrx(mtrx, size);
		
		print(max,cnt);
		cleanMemory(mtrx, size);
	}
	catch (std::exception e)
	{
		std::cout << "An exception occurred: " << e.what();
		cleanMemory(mtrx, size);
	}
	return 0;
}