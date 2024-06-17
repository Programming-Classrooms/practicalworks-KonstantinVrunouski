#include "../Source/Fraction.hpp"
#include "../Source/Matrix.hpp"
#include "../Source/MyList.hpp"


int main()
{
	Fraction a(4, 10, true);
	Fraction b;
	std::cout << "Input Second fraction:\n";
	std::cin >> b;

	std::cout << "First fraction:\n" << a << '\n';
	std::cout << "Second fraction:\n" << b << '\n';

	std::cout << "Reversed First: " << !a << '\n' << "Negative First: " << -a << '\n' << '\n';

	std::cout << "First + second:\n" << (a + b) << '\n';
	std::cout << "First - second:\n" << (a - b) << '\n';
	std::cout << "First * second:\n" << (a * b) << '\n';
	std::cout << "First / second:\n" << (a / b) << '\n' << '\n';

	std::cout << "First * 2:\n" << (a * 2) << '\n';
	std::cout << "First / 2:\n" << (a / 2) << '\n';

	if(a < b) {
		std::cout << a << " is lesser than " << b << '\n';
	} 
	if(b > a) {
		std::cout << b << " is greater than " << a << '\n';
	}
	if(a <= b) {
		std::cout << a << " is lesser than (or equal to) " << a << '\n';
	}
	if(b >= a) {
		std::cout << b << " is greater than (or equal to) " << a << '\n';
	}
	if(a == a) {
		std::cout << a << " is equal to " << a << '\n';
	}
	if(b != a) {
		std::cout << b << " isn't equal to " << a << '\n';
	}

	std::cout << "\n==========================================================\n";

	Matrix mat = Matrix();
    std::cout << mat;
    
    mat = Matrix(3, 3);
    Matrix tempMat(3, 3);
    
    std::cout << "Input first matrix:\n";
    std::cin >> mat;
    
    std::cout << "Input second matrix:\n";
    std::cin >> tempMat;
    
    std::cout << "First + Second:\n" << mat + tempMat;
    std::cout << "First - Second:\n" << mat - tempMat;
    std::cout << "First * Second:\n" << mat * tempMat;
    
    std::cout << "First multiplied by 5:\n" << mat * 5;
    std::cout << "First multiplied by 2.5:\n" << mat * 2.5;
    std::cout << "First multiplied by 5 (reversed):\n" << 5 * mat;
    std::cout << "First multiplied by 2.5 (reversed):\n" << mat * 2.5;
    
    std::cout << "First divided by 5:\n" << mat / 5;
    std::cout << "First divided by 2.5:\n" << mat / 2.5;

    mat.setElement(0, 0, 65);
    std::cout << "Changed element:\n" << mat.getElement(0, 0) << '\n';
    
    if (mat == mat) {
        std::cout << mat << "is equal to\n" << mat;
    }

    if (mat != tempMat) {
        std::cout << mat << "isn't equal to\n" << tempMat;
    }

	std::cout << "\n==========================================================\n";

	MyList<int32_t> testList;
	testList.push_back(2);
	testList.push_front(1);
	testList.push_back(3);
	testList.push_back(4);
	testList.push_back(5);

	testList.pop_back();
	testList.pop_front();
	testList.pop_value(3);

	testList.find(4);

	testList.changePrint();
	return 0;
}
