#include "func.hpp"


Employee::~Employee()
{
}

template<typename T>
void universalQsort(T* arr, size_t left, size_t right, bool (*comp)(T, T))
{
	size_t begin = left;
	size_t end = right;
	size_t mid = (left + right) / 2;

	T pivot = arr[mid];
	while (end > begin) 
    {
		while (comp(arr[begin], pivot)) 
        {
			++begin;
		}
		while (comp(pivot, arr[end])) 
        { 
			--end;
		}
		if (begin < end) 
        {
			std::swap(arr[end], arr[begin]);
			--end;
			++begin;
		}
	}
	if (end < right) 
    {
		universalQsort(arr, right, end, comp);
	}
	if (begin > left) {
		universalQsort(arr, begin, left, comp);
	}
}

bool checkFile(std::ifstream& file, std::string path)
{
	if (!file.good()) {
		std::string mes = "File not found. Path: ";
		mes.append(path); 
		throw std::invalid_argument(mes);
	}
	if (!file) {
		std::string mes = "File is bad. Path: ";
		mes.append(path); 
		throw std::ios_base::failure(mes);
	}
	if (file.peek() == EOF) {
		std::string mes = "File is empty. Path: ";
		mes.append(path); 
		throw std::runtime_error(mes);
	}
	return true;
}

std::string getMainText(std::string path)
{
	std::ifstream fin(path);
	std::string line, text;

	if (checkFile(fin, path)) {
		std::getline(fin, line);
		while (std::getline(fin, line)) {
			text.append(line);
			text.append(" ");
		}
		fin.close();
		return text;
	}
}

void printArr(int32_t* arr, int32_t size)
{
	if (size <= 0) {
		throw std::out_of_range("Bad size.");
	}
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

std::string toUpper(std::string word)
{
	for (size_t i = 0; i < word.size(); ++i) {
		word[i] = std::toupper(word[i]);
	}
	return word;
}

bool compForStructToUpper(Employee firstPerson, Employee secondPerson)
{
	if (toUpper(firstPerson.surname) == toUpper(secondPerson.surname)) {
		return firstPerson.surname < secondPerson.surname;
	}
	return toUpper(firstPerson.surname) < toUpper(secondPerson.surname);
}

bool isDigit(std::string word)
{
	size_t size = word.size();
	if (word[0] == '-' || isdigit(word[0])) {
		for (size_t i = 1; i < size; ++i) {
			if (!isdigit(word[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void fillingArr(int32_t* arr, std::string text, std::string delims)
{
	
	if (text.size() == 0 || delims.size() == 0) {
		throw std::out_of_range("Bad size of string...");
	}

	std::string word;
	size_t begin = 0;
	size_t end = 0;
	size_t i = 0;


	begin = text.find_first_not_of(delims, end);
	end = text.find_first_of(delims, begin);
	bool textHaveNumbers = false;
	while (begin < end) {
		word = text.substr(begin, (end - begin));
		if (isDigit(word)) {
			textHaveNumbers = true;
			arr[i++] = std::stoi(word);
		}
		begin = text.find_first_not_of(delims, end);
		end = text.find_first_of(delims, begin);
	}
}


void copySortArrays(int32_t* mainArr, int32_t* sortArr, int32_t size)
{
	if (size <= 0) {
		throw std::out_of_range("Bad size...");
	}
	size_t j = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (mainArr[i] % 2 == 0) {
			sortArr[j++] = mainArr[i];
		}
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (mainArr[i] % 2 != 0) {
			sortArr[j++] = mainArr[i];
		}
	}
}


size_t getSizeForArrNumbers(std::string text, std::string delimiters)
{
	std::string word;
	size_t begin = 0;
	size_t end = 0;
	size_t size = 0;
	if (text.size() == 0 || delimiters.size() == 0) {
		throw std::invalid_argument("Bad arguments.");
	}

	begin = text.find_first_not_of(delimiters, end);
	end = text.find_first_of(delimiters, begin);
	while (begin < end) {
		word = text.substr(begin, (end - begin));
		if (isDigit(word)) {
			++size;
		}
		begin = text.find_first_not_of(delimiters, end);
		end = text.find_first_of(delimiters, begin);
	}
	return size;
}

size_t getSizeForArrSurenames(std::string text, std::string delimiters)
{
	std::string word;
	size_t begin = 0;
	size_t end = 0;
	size_t size = 0;
	if (text.size() == 0 || delimiters.size() == 0) {
		throw std::invalid_argument("Bad arguments.");
	}

	begin = text.find_first_not_of(delimiters, end);
	end = text.find_first_of(delimiters, begin);
	while (begin < end) {
		word = text.substr(begin, (end - begin));
		if (isWord(word)) {
			++size;
		}
		begin = text.find_first_not_of(delimiters, end);
		end = text.find_first_of(delimiters, begin);
	}
	return size;
}

bool isWord(std::string word)
{
	size_t size = word.size();
	if (isupper(word[0])) {
		for (size_t i = 1; i < size; ++i) {
			if (!isalpha(word[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void printArr(std::string* arr, int32_t size)
{
	if (size <= 0) {
		throw std::out_of_range("Bad arguments.");
	}
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void qsortString(std::string* arr, size_t left, size_t right)
{
	size_t begin = left;
	size_t end = right;
	size_t mid = (left + right) / 2;


	while (end > begin) {
		while (compairStrings(arr[begin], arr[mid])) {
			++begin;
		}
		while (compairStrings(arr[mid], arr[end])) {
			--end;
		}
		if (begin < end) {
			std::swap(arr[end], arr[begin]);
			--end;
			++begin;
		}
	}

	if (end < right) {
		qsortString(arr, right, end);
	}
	if (begin > left) {
		qsortString(arr, begin, left);
	}
}

size_t inputChildren(std::string message)
{
	size_t count = 0;
	do 
    {
		std::cout << "Please enter a count of children for -- " << message << std::endl;
		std::cin >> count;
	} while (count > 9);
	return count;
}

void fillingArrOfStruct(Employee* arrOfStruct, int32_t* arrOfChildren, std::string* arrOfSurnames,
	int64_t sizeOfSurenames, int64_t sizeOfChildren)
{
	if (sizeOfSurenames <= 0 || sizeOfChildren <= 0){
		throw std::invalid_argument("Bad arguments.");
	}
	bool isNumber;
	size_t j = 0;
	for (size_t i = 0; i < sizeOfSurenames; ++i)
	{
		isNumber = false;
		arrOfStruct[i].surname = arrOfSurnames[i];
		for (; j < sizeOfChildren; ++j) {
			if (arrOfChildren[j] < 10 && arrOfChildren[j] >= 0) {
				isNumber = true;
				arrOfStruct[i].childrenAmount = arrOfChildren[j];
				++j;
				break;
			}
		}
		if (!isNumber) {
			arrOfStruct[i].childrenAmount = inputChildren(arrOfStruct[i].surname);
		}
	}
}

void printArr(Employee* arr, int32_t size)
{
	if (size <= 0) {
		throw std::out_of_range("Bad argument.");
	}
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i].surname << ' ' << arr[i].childrenAmount << std::endl;
	}
}

void menu(Employee* employees, size_t size)
{
	bool (*funcOfSort[2])(Employee firstPerson, Employee secondPerson) = { compForStructToLower, compForStructToUpper };
	size_t variant = 0;
	do 
    {
		std::cout << "Please enter a sort method:\n0 - descending;\n1 - ascending;\n " << std::endl;
		std::cin >> variant;
	} while (variant > 2);
	switch (variant) {
	case 0:
		universalQsort(employees, 0, size - 1, compForStructToLower);
		break;
	case 1:
		universalQsort(employees, 0, size - 1, compForStructToUpper);
		break;
	}
}


void swapLinesInBinaryFile(std::ofstream& fout, size_t pointerToLast, struct Employee employeeLast, struct Employee employeeFirst)
{
	fout.seekp(0);
	fout.write(reinterpret_cast<char*>(&employeeLast), sizeof(employeeLast));
	fout.seekp(pointerToLast - sizeof(employeeLast));
	fout.write(reinterpret_cast<char*>(&employeeFirst), sizeof(employeeFirst));
	std::cout << "Bin file with swap lines saved..." << std::endl;
}

size_t getPointerLast(std::ifstream& fin, struct Employee& employeeLast, struct Employee& employeeFirst)
{
	size_t pointerToLast = 0;

	fin.read(reinterpret_cast<char*>(&employeeFirst), sizeof(Employee));
	while (fin.read(reinterpret_cast<char*>(&employeeLast), sizeof(Employee))) {
		pointerToLast = fin.tellg();
	}

	return pointerToLast;
}

void writeArrOfStructToBin(std::ofstream& fout, Employee* arr, int64_t size)
{
	if (size <= 0) {
		throw std::invalid_argument("Bad size...");
	}
	for (size_t i = 0; i < size; ++i) {
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Employee));
	}
	std::cout << "Bin file is save!!!" << std::endl;
	fout.close();
}

void writeArrOfStruct(std::ofstream& fout, Employee* arr, int64_t size)
{
	if (size <= 0) {
		throw std::invalid_argument("Bad size...");
	}
	
	if (fout.is_open()) {
		for (size_t i = 0; i < size; ++i) {
			fout << arr[i].surname << " " << arr[i].childrenAmount << std::endl;
		}
		std::cout << "File is save!!!" << std::endl;
		fout.close();
	}
}

bool compForStructToLower(Employee firstPerson, Employee secondPerson)
{
	if (toUpper(firstPerson.surname) == toUpper(secondPerson.surname)) {
		return firstPerson.surname > secondPerson.surname;
	}
	return toUpper(firstPerson.surname) > toUpper(secondPerson.surname);
}

bool compairStrings(std::string first, std::string second)
{
	first = toUpper(first);
	second = toUpper(second);
	for (size_t i = 0; i < first.size() && i < second.size(); ++i) {
		if (first[i] < second[i]) {
			return true;
		} 
		else if (first[i] > second[i]) {
			return false;
		}
	}
	return first.size() < second.size();
}

void fillingArr(std::string* arr, std::string text, std::string delims)
{
	std::string word;
	size_t begin = 0;
	size_t end = 0;
	size_t i = 0;

	begin = text.find_first_not_of(delims, end);
	end = text.find_first_of(delims, begin);
	while (begin < end) {
		word = text.substr(begin, (end - begin));
		if (isWord(word)) {
			arr[i++] = word;
		}
		begin = text.find_first_not_of(delims, end);
		end = text.find_first_of(delims, begin);
	}
}

std::string getDelimiters(std::string path)
{
	std::ifstream fin(path);
	std::string delimiters{};

	if (checkFile(fin, path)) {
		std::getline(fin, delimiters);
		if (delimiters.size() == 0) {
			throw std::invalid_argument("Delimiters must be not empty...");
		}
		fin.close();
		return delimiters;
	}
}