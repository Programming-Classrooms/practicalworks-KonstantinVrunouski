/*
	Строки текстового файла input.txt состоят из слов, 
	разделенных одним или несколькими пробелами. 
	Перед первым, а также после последнего слова строки пробелы могут отсутствовать. 
	Требуется на основе исходного файла построить предметный указатель и 
	вывести его в файл output.txt. 
	Каждая строка предметного указателя содержит слово и номера строк текстового  файла,
	в которых это слово встречается, разделенные одним пробелом. 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>


void checkFile(std::istream& fin)
{
	if (!fin.good()) {
		throw "File does not exist.";
	}
	if (!fin) {
		throw "File is not opened.";
	}
	if (fin.peek() == EOF) {
		throw "File is empty.";
	}
}

void createSubjectIndex(std::vector<std::string>& subjectIndex, std::string word, size_t& subjectIndexLen, bool& isFind, size_t lineNum)
{
	for (size_t i = 0; i < subjectIndexLen; ++i) {
		if (subjectIndex[i].find(word) != -1) {
			isFind = true;
			if (subjectIndex[i].find(' ' + std::to_string(lineNum)) == -1) {
				subjectIndex[i] += ' ' + std::to_string(lineNum);
			}
		}
	}
	if (!isFind) {
		subjectIndex.push_back(word + ' ' + std::to_string(lineNum));
		++subjectIndexLen;
	}
}

void divideLineByWords(std::string line, std::vector<std::string>& subjectIndex, size_t lineNum, size_t& subjectIndexLen)
{
	std::string word;
	std::string delims = " \t";
	std::string::size_type begInd;
	bool isFind = false;

	begInd = line.find_first_not_of(delims);
	while (begInd != std::string::npos) {
		isFind = false;
		std::string::size_type endInd;
		endInd = line.find_first_of(delims, begInd);
		if (endInd == std::string::npos) {
			endInd = line.length();
		}
		word = line.substr(begInd, endInd - begInd);

		createSubjectIndex(subjectIndex, word, subjectIndexLen, isFind, lineNum);

		begInd = line.find_first_not_of(delims, endInd);
	}
}

void print(std::ofstream& fout, std::vector<std::string>& subjectIndex, size_t subjectIndexLen)
{
	if (subjectIndexLen == 0) {
		throw "There are no words in file.";
	}
	for (size_t i = 0; i < subjectIndexLen; ++i) {
		fout << subjectIndex[i] << '\n';
	}
}

int main()
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	try {
		checkFile(fin);

		size_t lineNumber = { 1 };
		size_t subjectIndexLen = { 0 };
		std::string str;
		std::vector<std::string> subjectIndex;

		while (fin) {
			getline(fin, str);
			divideLineByWords(str, subjectIndex, lineNumber, subjectIndexLen);
			++lineNumber;
		}

		fin.close();

		print(fout, subjectIndex, subjectIndexLen);

		fout.close();
	}
	catch (const char* e) {
		std::cout << e << '\n';
		fin.close();
		fout.close();
	}

	return 0;
}
