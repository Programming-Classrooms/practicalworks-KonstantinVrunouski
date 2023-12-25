/*
	Строка состоит из слов. За один просмотр символов строки найти все
	самые длинные слова и занести их в новую строку. Слова в новой строке
	должны разделяться точкой с запятой и одним пробелом.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


void isEmptyLine(char string[])
{
	if (!strlen(string)){
		throw "Line is empty.";
	}
}

void inputLine(char string[301], const char* message = "Input line:")
{
	std::cout << message << '\n';
	std::cin.getline(string, 301);
	isEmptyLine(string);
}

char* divideLineByWords(char str[301], char div[301])
{
	char* word = strtok(str, div);
	char* newString = new char[301];
	size_t lenWord;
	size_t lenMaxWord = { 0 };
	while (word != NULL){
		lenWord = strlen(word);

		if (lenWord > lenMaxWord){
			lenMaxWord = lenWord;
			strcpy(newString, word);
			strcat(newString, "; ");
		}
		else if (lenWord == lenMaxWord){
			strcat(newString, word);
			strcat(newString, "; ");
		}

		word = strtok(NULL, div);
	}
	return newString;
}

void print(char* str)
{
	std::cout << str << '\n';
}

int main()
{
	try{
		char string[301];
		char delimeters[301];
		char* newString = new char[301];

		inputLine(delimeters, "Input dividers:");
		
		inputLine(string);
		
		strcpy(newString, divideLineByWords(string, delimeters));
		
		print(newString);
	}
	catch (const char* e){
		std::cout << e;
	}
	return 0;
}
