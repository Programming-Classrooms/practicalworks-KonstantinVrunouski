/*
	Строка состоит из слов, разделённых знаками препинания. Найти все
	самые длинные слова-палиндромы и занести их в новую строку, разделяя
	запятой.
*/


#include <iostream>
#include <string.h>


void checkStringEmtiness(std::string string, const char* message = "Line is empty.")
{
	if (string.empty()){
		throw std::exception(message);
	}
}

std::string inputString(const char* message = "Input line:")
{
	std::string string;
	std::cout << message << '\n';

	getline(std::cin, string);
	
	checkStringEmtiness(string);

	return string;
}

bool isPalindrome(std::string line)
{
	size_t len = line.length();
	for (size_t i = 0; i < len; ++i){
		if (line[i] != line[len - i - 1]){
			return false;
		}
	}
	return true;
}

void createNewPalindromesLine(std::string word, size_t wordLen, size_t& wordMaxLen, std::string& newLine)
{
	if (wordLen > wordMaxLen){
		wordMaxLen = wordLen;
		if (isPalindrome(word)){
			newLine = word;
		}
	}
	else if (wordLen == wordMaxLen){
		if (isPalindrome(word)){
			newLine += ", ";
			newLine += word;
		}
	}
}

std::string transformString(std::string line, std::string delims)
{
	std::string word; 
	std::string wordRev; 
	std::string newLine = "";
	size_t wordLen; 
	size_t wordMaxLen = { 0 };

	std::string::size_type begInd = line.find_first_not_of(delims);
	while (begInd != std::string::npos){
		std::string::size_type endInd;
		endInd = line.find_first_of(delims, begInd);
		if (endInd == std::string::npos){
			endInd = line.length();
		}
		word = line.substr(begInd, endInd - begInd);
		wordLen = word.length();

		createNewPalindromesLine(word, wordLen, wordMaxLen, newLine);

		begInd = line.find_first_not_of(delims, endInd);
	}
	return newLine;
}

void print(std::string string, const char* message = "Line with the longest palindromes:")
{
	std::cout << message << '\n';
	std::cout << string << '\n';
}

int main()
{
	try{
		std::string delims = " .?!,;:"; 
		std::string line = inputString();
		std::string newLine;
		
		newLine = transformString(line, delims);
		
		checkStringEmtiness(newLine, "There are no palindromes in line.");
		
		print(newLine);
	}
	catch (std::exception e){
		std::cout << e.what();
	}

	return 0;
}
