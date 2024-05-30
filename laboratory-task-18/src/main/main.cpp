#include "../LibClass/library.hpp"


int main()
{
	try
	{
		Book BookHobbit("Hobbit", std::vector<std::string>{"J. R. R. Tolkien"}, 15.5, 4);
		Book Book1984("1.9.8.4.", std::vector<std::string>{"G. OrWell"}, 20.0, 1);
		Book BookSherlock("A Study in Scarlet", std::vector<std::string>{"A. C. Doyle"}, 9.9, 10);

		Library Lib;
		Lib.addBook(BookHobbit);
		Lib.addBook(Book1984);
		Lib.addBook(BookSherlock);

		Lib.addAuthor("AAAAAAAAAAAAA", "Me");

		std::cout << Lib.findBook("BAAAAAAAAAAAA") << '\n';

		Lib.removeBook("AAAAAAAAAAAAA");

		Lib.sortByTitle();
		Lib.browse();

		Lib.sortByISBN();
		Lib.browse();


		Lib.removeAuthor("CAAAAAAAAAAAA");
		Lib.browse();

		Lib.findBook("A");
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
