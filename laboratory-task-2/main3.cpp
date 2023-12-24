/*
    17.Напечатать в порядке возрастания все простые несократимые
    дроби, заключенные между 0 и 1, знаменатели которых меньше
    заданного числа.
*/


#include <iostream>


int32_t get_number()
{
    int32_t num;
    std::cout << "Enter natural number:\n";
    std::cin >> num;
    if (num <= 0)
    {
        throw "Invalid number.";
    }
    return num;
}

int32_t factorial(int32_t factor) {
    int32_t res = 1;
    for (size_t i = 1; i <= factor; i++) {
        res *= i;
    }
    return res;
}

void fract_out(int32_t num, int32_t denominator)
{
    for (size_t j = denominator; j > 2; --j)
    {
        int32_t numerator = denominator - j;
        int32_t temp_denominator = denominator;

        for (size_t i = denominator; i >= 1; --i)
        {
            if (temp_denominator % i == 0 && numerator % i == 0)
            {
                numerator /= i;
                temp_denominator /= i;
            }
        }
        if (temp_denominator <= num && numerator != 0)
        {
            std::cout << numerator << '/' << temp_denominator << '\t';
        }
    }
}

int main() 
{
    try
    {
        int32_t num = get_number();
        int32_t denominator = factorial(num);
        fract_out(num, denominator);
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }
    return 0;
}