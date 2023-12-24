/*
    17.Напечатать в порядке возрастания все простые несократимые
    дроби, заключенные между 0 и 1, знаменатели которых меньше
    заданного числа.
*/


#include <iostream>


int32_t inputNumber(const char* message = "Enter natural number:")
{
    int32_t num;

    std::cout << message << '\n';
    std::cin >> num;

    if (num <= 0){
        throw "Invalid number.";
    }

    return num;
}

int32_t factorial(int32_t factor) 
{
    int32_t result = 1;

    for (size_t i = 1; i <= factor; i++){
        result *= i;
    }

    return result;
}

void fractPrint(int32_t num, int32_t denominator)
{
    for (size_t j = denominator; j > 2; --j){
        int32_t numerator = denominator - j;
        int32_t tempDenominator = denominator;
        
        for (size_t i = denominator; i >= 1; --i){
            if (tempDenominator % i == 0 && numerator % i == 0){
                numerator /= i;
                tempDenominator /= i;
            }
        }

        if (tempDenominator <= num && numerator != 0){
            std::cout << numerator << '/' << tempDenominator << '\t';
        }
    }
}

int main() 
{
    try{
        int32_t num = inputNumber();
        int32_t denominator = factorial(num);

        fractPrint(num, denominator);
    }
    catch (const char* e){
        std::cout << e;
    }
    return 0;
}
