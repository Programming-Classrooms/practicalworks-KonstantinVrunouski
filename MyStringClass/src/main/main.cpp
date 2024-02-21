#include "../MyString/MyString.hpp"

int main()
{
	MyString s("Avas");
	std::cout << s.findLast('s') << '\n';
	std::cout << s.findLast('A') << '\n';
	std::cout << s.findLast('o') << '\n';
	std::cout << s.findFirst('v') << '\n';
	std::cout << s.findFirst('a') << '\n';
	std::cout << s.findFirst('u') << '\n';
	std::cout << s.getLength() << '\n';	
	return 0;
}
