#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <algorithm>


void makeAllWords(std::ifstream& in, std::map<std::string, size_t>& allWords)
{
	std::string word;
	while(in >> word)
	{
		if (allWords.find(word) == allWords.end())
		{
			allWords.emplace(word, 1);
			continue;
		}

		allWords.find(word)->second++;	
	}
}

void printMap(const std::map<std::string, size_t>& allWords)
{
	for (auto i : allWords)
	{
		std::cout << i.first << ' ' << i.second << '\n';
	}
}

int main()
{
	std::ifstream in("src/resource/input.txt");
	std::map<std::string, size_t> allWords;

	makeAllWords(in, allWords);

	in.close();

	std::cout << "All words with count in file:\n";
	printMap(allWords);

	return 0;
}
