#include <iostream>
#include <cmath>
#include <exception>

void input(int32_t& k, double& x)
{
	std::cout << "Input X and K:\n";
	std::cin >> x >> k;
	if (x <= 0 || x >= 1)
	{
		throw std::exception("Invalid x.");
	}
}

double cntTaylorSeries(double term, double eps, double res_right, double x, double part)
{
	double i = 3.0;
	while (fabs(term) >= eps)
	{
		res_right += term;
		part = i / (i + 1);
		term *= -(x * part);
		i += 2;
	}
	return res_right;
}

void output(double res_left, double res_right)
{
	std::cout << "Value of the left:  ";
	printf("%.10LF", res_left);
	std::cout << '\n';
	std::cout << "Value of the right: ";
	printf("%.10LF", res_right);
}

int main()
{
	try
	{
		int32_t k;
		double part{ 0 }, x, eps, res_left, term, res_right{ 1.0 };
		input(k, x);
		term = -x / 2;
		eps = pow(10, -k);
		res_left = 1.0 / sqrt(x + 1);
		res_right = cntTaylorSeries(term, eps, res_right, x, part);
		output(res_left, res_right);
	}
	catch (std::exception e)
	{
		std::cout << "An exception occurred: " << e.what();
	}
	return 0;
}