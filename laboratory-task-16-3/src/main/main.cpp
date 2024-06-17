#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string>arr;
	std::string word;

	std::ifstream fin("src/files/input.txt");

	while (fin >> word)
	{
		arr.push_back(word);
	}

	fin.close();

	std::sort(arr.begin(), arr.end());

	std::cout << "Элементы после сортировки:\n";
	for (std::string i : arr)
	{
		std::cout << i << '\n';
	}

	std::cout << "Введите букву для вывода слов начинающихся с неё:\n";
	std::string buff;
	std::getline(std::cin, buff);
	char letter = buff[0];
	
	std::cout << "Слова начинающиеся с введённой буквы:\n";
	for (std::string i : arr)
	{
		if (i[0] == letter)
		{
			std::cout << i << ' ';
		}
	}
	std::cout << '\n';
	
	std::cout << "Удаление слов по введённой букве:\n";
	std::getline(std::cin, buff);
	letter = buff[0];
	
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i][0] == letter)
		{
			arr.erase(arr.begin() + i);
			--i;
		}
	}

	if (arr[arr.size() - 1][0] == letter)
	{
		arr.erase(arr.begin() + arr.size() - 1);
	}

	std::cout << "Итоговый вектор:\n";
	for (std::string i : arr)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	return 0;
}
