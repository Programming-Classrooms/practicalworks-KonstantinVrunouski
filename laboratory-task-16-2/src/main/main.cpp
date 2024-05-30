#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


bool isInVector(const std::vector<int>& arr, int element)
{
	for (int i : arr)
	{
		if (i == element)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	try
	{
		setlocale(LC_ALL, "ru");
		std::vector<int> arr;
		int temp;
		while (std::cin >> temp)
		{
			arr.push_back(temp);
		}
	
		size_t size = arr.size();
		if (size == 0)
		{
			throw std::runtime_error("No numbers in vector.");
		}

		int sum = 0;
		sum = std::accumulate(arr.begin(), arr.end(), 0);
		std::cout << "Сумма элементов: " << sum << '\n';

		std::cout << "Размер вектора: " << size << '\n';

		size_t quantityEqual = 0;
		auto countIfEqual = [&quantityEqual](int a, int b) { (a == b) ? ++quantityEqual : quantityEqual; };

		for (int element : arr)
		{
			countIfEqual(element, 3);
		}

		std::cout << "Кол-во элементов равных 3-ём: " << quantityEqual << '\n';
	
		size_t quantityGreater = 0;
		auto countIfGreater = [&quantityGreater](int a, int b) {(a > b) ? ++quantityGreater : quantityGreater; };

		for (int element : arr)
		{
			countIfGreater(element, 2);
		}

		std::cout << "Кол-во элементов больших чем 2: " << quantityGreater << '\n';


		int medium = sum / size;
		auto replaceIfEqual = [](int& a, int b) {(a == 0 ? a = b : a = a); };

		for (int& element : arr)
		{
			replaceIfEqual(element, medium);
		}

		std::cout << "Содержимое:\n";
		for (int element : arr)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';

		size_t l_bord, r_bord;
		std::cout << "Введите нижнюю и верхнюю границы:\n";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> l_bord >> r_bord;

		if (l_bord >= size || r_bord >= size)
		{
			throw std::out_of_range("Wrong index.");
		}

		int sumInterval = 0;
		sumInterval = std::accumulate(arr.begin() + l_bord, arr.begin() + r_bord + 1, 0);

		for (int& element : arr)
		{
			element += sumInterval;
		}

		std::cout << "Содержимое:\n";
		for (int element : arr)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';

		int minEl = arr[0];
		int maxEl = arr[0];

		int diff = *std::max(arr.begin(), arr.end()) - *std::min(arr.begin(), arr.end());

		auto replaceIfEven{ [diff](int& a) {(!static_cast<bool>(a & 0x1)) ? a = diff : a = a; } };

		for (int& element : arr)
		{
			replaceIfEven(element);
		}

		std::cout << "Содержимое:\n";
		for (int element : arr)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	
		std::vector<int>elementAppeared(size);

		for (size_t i = 0; i < arr.size(); ++i)
		{
			if (isInVector(elementAppeared, arr[i]))
			{
				arr.erase(arr.begin() + i);
			}
			else
			{
				elementAppeared.push_back(arr[i]);
			}
		}

		if (isInVector(elementAppeared, arr[arr.size() - 1]))
		{
			arr.erase(arr.begin() + arr.size() - 1);
		}

		std::cout << "Содержимое:\n";
		for (int element : arr)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';

	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
