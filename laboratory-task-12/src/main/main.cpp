#include "../MyString/MyString.hpp"

int main()
{
	MyString testStrEmpty = MyString();

	MyString testStr1("Hello world!");
	std::cout << testStr1 << '\n';
	
	MyString testStr2("And again, ");
	MyString testStr = testStr2 + testStr1;
	std::cout << testStr << '\n';

	testStr += MyString(" The end of the line.");
	std::cout << testStr << '\n';  
	
	if (testStr == testStr)
	{
		std::cout << "Strings are equal.\n";
	}

	if (testStr1 != testStr2)
	{
		std::cout << "Strings aren't equal.\n";
	}

	if (testStr2 < testStr1)
	{
		std::cout << testStr2 << " lesser than " << testStr1 << '\n';  
	}

	if (testStr1 > testStr2)
	{
		std::cout << testStr2 << " greater than " << testStr1 << '\n';  
	}

	if (testStr2 <= testStr1)
	{
		std::cout << testStr2 << " lesser or equal than " << testStr1 << '\n';  
	}

	if (testStr1 >= testStr2)
	{
		std::cout << testStr2 << " greater or equal than " << testStr1 << '\n';  
	}

	if (testStrEmpty.isEmpty())
	{
		std::cout << "String is empty.\n";
	}

	std::cout << testStr1.findFirst('e') << '\n';
	std::cout << testStr2.findLast('n') << '\n';

	testStr1.stringToLow();
	std::cout << testStr1 << '\n';

	testStr1.stringToUp();
	std::cout << testStr1 << '\n';

	std::cout << testStr1.count('!') << '\n';

	MyString testStrInput;
	std::cin >> testStrInput;
	std::cout << testStrInput << '\n';

	return 0;
}
