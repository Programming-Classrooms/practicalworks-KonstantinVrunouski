/*
	Вычислить значение определенного интеграла с аналитически заданной подынтегральной
	функцией с заданной точностью eps.
	-по формуле левых прямоугольников;
	-по формуле трапеций;
	Вариант и интегралы приложены на скриншоте.
*/


#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>


double getEpsilon(double eps)
{
	std::cout << "Input epsilon:\n";
	std::cin >> eps;
	if (eps <= 0 || eps >= 1)
	{
		throw "Invalid epsilon.";
	}
	return eps;
}

int32_t chooseIntegral(int32_t chIntgrl)
{
	std::cout << "Choose an integral:" << '\n';
	std::cout << "1)First" << ' ' << "2)Second" << ' ' << "3)Third" << '\n';
	std::cin >> chIntgrl;
	if (chIntgrl != 1 && chIntgrl != 2 && chIntgrl != 3)
	{
		throw "Invalid integral.";
	}
	return chIntgrl;
}

int32_t chooseMethod(int32_t chMethod)
{
	std::cout << "Choose a method to calculate integral:" << '\n';
	std::cout << "1)Left rectangles" << ' ' << "2)Trapezoids" << '\n';
	std::cin >> chMethod;
	if (chMethod != 1 && chMethod != 2)
	{
		throw "Invalid method.";
	}
	return chMethod;
}

double funcCalcFirst(double x)
{
	return sqrt(exp(x) - 1);
}

double funcCalcSecond(double x)
{
	return exp(x)*sin(x);
}

double funcCalcThird(double x)
{
	return (x*x-1)*pow(10,-2*x);
}

double calc_step(double right_brdr, double left_brdr, int n)
{
	double h;
	h = (right_brdr - left_brdr) / n;
	return h;
}

double calc_x(double left_brdr, double right_brdr, int n, int i)
{
	double x = left_brdr + i * calc_step(right_brdr, left_brdr, n);
	return x;
}

long double calc_integral1rectangle(double left_brdr, double right_brdr, int n)
{
	double h, xi, xiPlusOne, integralValue{ 0 };
	for (int i = 0; i < n; ++i)
	{
		xi = calc_x(left_brdr, right_brdr, n, i);
		xiPlusOne = calc_x(left_brdr, right_brdr, n, i+1);
		integralValue += funcCalcFirst(xi) * (xiPlusOne - xi);
	}
	return integralValue;
}

long double calc_integral2rectangle(double left_brdr, double right_brdr, int n)
{
	double xi, xiPlusOne, s2{ 0 };
	for (int i = 0; i < n; ++i)
	{
		xi = calc_x(left_brdr, right_brdr, n, i);
		xiPlusOne = calc_x(left_brdr, right_brdr, n, i + 1);
		s2 += funcCalcSecond(xi) * (xiPlusOne - xi);
	}
	return s2;
}

long double calc_integral3rectangle(double left_brdr, double right_brdr, int n)
{
	double xi, xiPlusOne, s3{ 0 };
	for (int i = 0; i < n; ++i)
	{
		xi = calc_x(left_brdr, right_brdr, n, i);
		xiPlusOne = calc_x(left_brdr, right_brdr, n, i + 1);
		s3 += funcCalcThird(xi) * (xiPlusOne - xi);
	}
	return s3;
}

long double calcIntegral1Trapezoid(double leftBrdr, double rightBrdr, int n)
{
	const double width = (rightBrdr - leftBrdr) / n;

	double s = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = leftBrdr + step * width;
		const double x2 = leftBrdr + (step + 1) * width;

		s += 0.5 * (x2 - x1) * (funcCalcFirst(x1) + funcCalcFirst(x2));
	}
	return s;
}

long double calcIntegral2Trapezoid(double leftBrdr, double rightBrdr, int n)
{
	const double width = (rightBrdr - leftBrdr) / n;

	double s = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = leftBrdr + step * width;
		const double x2 = leftBrdr + (step + 1) * width;

		s += 0.5 * (x2 - x1) * (funcCalcSecond(x1) + funcCalcSecond(x2));
	}
	return s;
}

long double calcIntegral3Trapezoid(double leftBrdr, double rightBrdr, int n)
{
	const double width = (rightBrdr - leftBrdr) / n;

	double s = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = leftBrdr + step * width;
		const double x2 = leftBrdr + (step + 1) * width;

		s += 0.5 * (x2 - x1) * (funcCalcThird(x1) + funcCalcThird(x2));
	}
	return s;
}

void printValue(long double s)
{
	std::cout << "Value of the integral:" << '\n';
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
	try
	{
		eps = getEpsilon(eps);
		chMethod = chooseMethod(chMethod);
		chIntgrl = chooseIntegral(chIntgrl);
		switch (chMethod)		
		{
		case 1:
		{
			switch (chIntgrl)
			{
			case 1:
			{
				int32_t divs = 4;
				while (fabs(intgrlFirst - integralValue) > eps)
				{
					integralValue = calc_integral1rectangle(leftBrdrFirst, rightBrdrFirst, divs);
					divs *= 2;
				}
				printValue(integralValue);
				break;
			}
			case 2:
			{
				int32_t divs = 4;
				while (fabs(intgrlSecond - integralValue) > eps)
				{
					integralValue = calc_integral2rectangle(leftBrdrSecond, rightBrdrSecond, divs);
					divs *= 2;
				}

				printValue(integralValue);
				break;
			}
			case 3:
			{
				int32_t divs = 4;
				while (fabs(intgrlThird - integralValue) > eps)
				{
					integralValue = calc_integral3rectangle(leftBrdrThird, rightBrdrThird, divs);
					divs *= 2;
				}
				printValue(integralValue);
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (chIntgrl)
			{
				case 1:
				{
					int32_t divs = 4;
					while (fabs(intgrlFirst - integralValue) > eps)
					{
						integralValue = calcIntegral1Trapezoid(leftBrdrFirst, rightBrdrFirst, divs);
						divs *= 2;
					}
					printValue(integralValue);
					break;
				}
				break;
				case 2:
				{
					int32_t divs = 4;
					while (fabs(intgrlSecond - integralValue) > eps)
					{
						integralValue = calcIntegral2Trapezoid(leftBrdrSecond, rightBrdrSecond, divs);
						divs *= 2;
					}
					printValue(integralValue);
					break;
				}
				case 3:
				{
					int32_t divs = 4;
					while (fabs(intgrlThird - integralValue) > eps)
					{
						integralValue = calcIntegral3Trapezoid(leftBrdrThird, rightBrdrThird, divs);
						divs *= 2;
					}
					printValue(integralValue);
					break;
				}
			}
			break;
		}
		}
	}
	catch (const char* e)
	{
		std::cout << "An exception occurred: " << e;
		return -1;
	}
	return 0;	
}
