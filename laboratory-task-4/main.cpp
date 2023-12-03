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

size_t get_mtrx_size()
{
	size_t size;
	std::cout << "Input size of the matrix:\n";
	std::cin >> size;
	return size;
}

void declare_mtrx(int32_t**& mtrx, size_t size)
{
	mtrx = new int32_t * [size];
	for (size_t i = 0; i < size; ++i)
	{
		mtrx[i] = new int32_t[size];
	}
}

int32_t input_type()
{
	std::cout << "How'd you like to input elements:\n1)Manually.\t2)Randomly.\n";
	int32_t in_type;
	std::cin >> in_type;
	if (in_type != 1 && in_type != 2)
	{
		throw std::exception("Invalid choice.");
	}
	return in_type;
}

void fill_mtrx_man(int32_t** mtrx, size_t size)
{
	std::cout << "Input elements of the matrix:\n";
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			std::cin >> mtrx[i][j];
}

void get_borders(int32_t& l_bord, int32_t& r_bord)
{
	std::cout << "Input left and right border of random:\n";
	std::cin >> l_bord >> r_bord;
	if (l_bord > r_bord)
		std::swap(l_bord, r_bord);
}

void fill_mtrx_rand(int32_t** mtrx, size_t size)
{
	int32_t l_bord, r_bord;
	get_borders(l_bord, r_bord);
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			mtrx[i][j] = l_bord + rand() % (r_bord - l_bord + 1);
}

void mtrx_out(int32_t** mtrx, size_t size)
{
	std::cout << "Generated matrix:\n";
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			std::cout << std::setw(5) << mtrx[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void mem_cleanse(int32_t**& mtrx, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		delete[] mtrx[i];
	delete[] mtrx;
}

bool find_positive_in_col(int32_t** mtrx, size_t size, size_t col)
{
	bool is_pos = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (mtrx[i][col] > 0)
		{
			is_pos = true;
			break;
		}
	}
	return is_pos;
}

int32_t max_el_col(int32_t** mtrx, size_t size)
{
	int32_t max = INT32_MIN;
	for (size_t i = 0; i < size; ++i)
	{
		if (!find_positive_in_col(mtrx, size, i))
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

void out(int32_t max, size_t cnt)
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

size_t cnt_neg_el_low_rgt_triangle(int32_t** mtrx, size_t size)
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

int main()
{
	srand(time(NULL));
	int32_t** mtrx = nullptr;
	size_t size;
	try
	{
		size = get_mtrx_size();
		declare_mtrx(mtrx, size);

		int32_t in_type = input_type();
		if (in_type == 1)
			fill_mtrx_man(mtrx, size);
		else
			fill_mtrx_rand(mtrx, size);

		int32_t max = max_el_col(mtrx, size);
		
		size_t cnt = cnt_neg_el_low_rgt_triangle(mtrx, size);
		
		if (in_type != 1)
			mtrx_out(mtrx, size);
		
		out(max,cnt);
		mem_cleanse(mtrx, size);
	}
	catch (std::exception e)
	{
		std::cout << "An exception occurred: " << e.what();
		mem_cleanse(mtrx, size);
	}
	return 0;
}