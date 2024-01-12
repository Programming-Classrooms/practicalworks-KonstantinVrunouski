/*
	Вычислить значение определенного интеграла с аналитически заданной подынтегральной
	функцией с заданной точностью eps.
	Методы подсчёта интегралов:
	-по формуле левых прямоугольников;
	-по формуле трапеций;
	Вариант и интегралы приложены на скриншоте.
*/


#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>


double inputEpsilon(double eps)
{
	std::cout << "Input epsilon:\n";
	std::cin >> eps;
	if (eps <= 0 || eps >= 1){
		throw std::exception("Invalid epsilon.");
	}
	return eps;
}

int32_t chooseIntegral(int32_t chIntgrl)
{
	std::cout << "Choose an integral:" << '\n';
	std::cout << "1)First" << ' ' << "2)Second" << ' ' << "3)Third" << '\n';
	std::cin >> chIntgrl;
	if (chIntgrl < 1 || chIntgrl > 3){
		throw std::exception("Invalid integral.");
	}
	return chIntgrl;
}

int32_t chooseMethod(int32_t chMethod)
{
	std::cout << "Choose a method to calculate integral:" << '\n';
	std::cout << "1)Left rectangles" << ' ' << "2)Trapezoids" << '\n';
	std::cin >> chMethod;
	if (chMethod < 1 || chMethod > 2){
		throw std::exception("Invalid method.");
	}
	return chMethod;
}

double calcFirstFunc(double x)
{
	return sqrt(exp(x) - 1);
}

double calcSecondFunc(double x)
{
	return exp(x)*sin(x);
}

double calcThirdFunc(double x)
{
	return (x*x-1)*pow(10,-2*x);
}

double calcStep(double right_brdr, double left_brdr, int n)
{
	double h;
	h = (right_brdr - left_brdr) / n;
	return h;
}

double calcX(double left_brdr, double right_brdr, int n, int i)
{
	double x = left_brdr + i * calcStep(right_brdr, left_brdr, n);
	return x;
}

long double calcFirstIntegralRectangle(double left_brdr, double right_brdr, int n)
{
	double h, xi, xiPlusOne, integralValue{ 0 };
	for (int i = 0; i < n; ++i){
		xi = calcX(left_brdr, right_brdr, n, i);
		xiPlusOne = calcX(left_brdr, right_brdr, n, i+1);
		integralValue += calcFirstFunc(xi) * (xiPlusOne - xi);
	}
	return integralValue;
}

long double calcSecondIntegralRectangle(double left_brdr, double right_brdr, int n)
{
	double xi, xiPlusOne, s2{ 0 };
	for (int i = 0; i < n; ++i){
		xi = calcX(left_brdr, right_brdr, n, i);
		xiPlusOne = calcX(left_brdr, right_brdr, n, i + 1);
		s2 += calcSecondFunc(xi) * (xiPlusOne - xi);
	}
	return s2;
}

long double calcThirdIntegralRectangle(double left_brdr, double right_brdr, int n)
{
	double xi, xiPlusOne, s3{ 0 };
	for (int i = 0; i < n; ++i){
		xi = calcX(left_brdr, right_brdr, n, i);
		xiPlusOne = calcX(left_brdr, right_brdr, n, i + 1);
		s3 += calcThirdFunc(xi) * (xiPlusOne - xi);
	}
	return s3;
}

long double calcFirstIntegralTrapezoid(double leftBrdr, double rightBrdr, int n)
{
	const double width = (rightBrdr - leftBrdr) / n;

	double s = 0;
	for (int step = 0; step < n; step++){
		const double x1 = leftBrdr + step * width;
		const double x2 = leftBrdr + (step + 1) * width;

		s += 0.5 * (x2 - x1) * (calcFirstFunc(x1) + calcFirstFunc(x2));
	}
	return s;
}

long double calcSecondIntegralTrapezoid(double leftBrdr, double rightBrdr, int n)
{
	const double width = (rightBrdr - leftBrdr) / n;

	double s = 0;
	for (int step = 0; step < n; step++){
		const double x1 = leftBrdr + step * width;
		const double x2 = leftBrdr + (step + 1) * width;

		s += 0.5 * (x2 - x1) * (calcSecondFunc(x1) + calcSecondFunc(x2));
	}
	return s;
}

long double calcThirdIntegralTrapezoid(double leftBrdr, double rightBrdr, int n)
{
	const double width = (rightBrdr - leftBrdr) / n;

	double s = 0;
	for (int step = 0; step < n; step++){
		const double x1 = leftBrdr + step * width;
		const double x2 = leftBrdr + (step + 1) * width;

		s += 0.5 * (x2 - x1) * (calcThirdFunc(x1) + calcThirdFunc(x2));
	}
	return s;
}

void print(long double s, const char* message = "Value of the integral:")
{
	std::cout << message << '\n';
	std::cout << s << '\n';
}


int main()
{
	double rightBrdrFirst = { 2.1 };
	double rightBrdrSecond = { M_PI / 2 };
	double rightBrdrThird = { 0.5 }; 
	double leftBrdrFirst = { 0.2 }; 
	double leftBrdrSecond = { 0 }; 
	double leftBrdrThird = { 0 };
	long double eps = { 0 }; 
	long double xi; 
	long double xiPlusOne;
	long double integralValue = { 1 };  
	long double h; 
	long double h_plus_one;
	const double intgrlFirst = { 2.8658854 }; 
	const double intgrlSecond = { 2.9052387 }; 
	const double intgrlThird = { -0.18714606 };
	int32_t chIntgrl = { 0 };
	int32_t chMethod = { 0 };

	try {
		eps = inputEpsilon(eps);
		chMethod = chooseMethod(chMethod);
		chIntgrl = chooseIntegral(chIntgrl);

		switch (chMethod) {
			case 1: {
				switch (chIntgrl) {
					case 1: {
						int32_t divs = 4;
						while (fabs(intgrlFirst - integralValue) > eps){
							integralValue = calcFirstIntegralRectangle(leftBrdrFirst, rightBrdrFirst, divs);
							divs *= 2;
						}
						print(integralValue);
						break;

					}
					
					case 2: {
						int32_t divs = 4;
						while (fabs(intgrlSecond - integralValue) > eps){
							integralValue = calcSecondIntegralRectangle(leftBrdrSecond, rightBrdrSecond, divs);
							divs *= 2;
						}

						print(integralValue);
						break;
					}

					case 3: {
						int32_t divs = 4;
						while (fabs(intgrlThird - integralValue) > eps){
							integralValue = calcThirdIntegralRectangle(leftBrdrThird, rightBrdrThird, divs);
							divs *= 2;
						}
						print(integralValue);
						break;
					}
				}
				break;
			}

			case 2: {
				switch (chIntgrl) {
					case 1: {
						int32_t divs = 4;
						while (fabs(intgrlFirst - integralValue) > eps) {
							integralValue = calcFirstIntegralTrapezoid(leftBrdrFirst, rightBrdrFirst, divs);
							divs *= 2;
						}
						print(integralValue);
						break;
					}
					break;

					case 2: {
						int32_t divs = 4;
						while (fabs(intgrlSecond - integralValue) > eps) {
							integralValue = calcSecondIntegralTrapezoid(leftBrdrSecond, rightBrdrSecond, divs);
							divs *= 2;
						}
						print(integralValue);
						break;
					}

					case 3: {
						int32_t divs = 4;
						while (fabs(intgrlThird - integralValue) > eps) {
							integralValue = calcThirdIntegralTrapezoid(leftBrdrThird, rightBrdrThird, divs);
							divs *= 2;
						}
						print(integralValue);
						break;
					}
				}
				break;
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what();
	
		return 0;
	}

	return 0;	
}
