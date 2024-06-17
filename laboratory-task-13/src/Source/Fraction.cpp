#include <numeric>
#include "Fraction.hpp"

// Метод сокращения дроби
void Fraction::reduce()
{
    size_t tempGcd = std::gcd(this->numerator, this->denominator); 
    if (tempGcd != 1)
    {
        this->numerator /= tempGcd;
        this->denominator /= tempGcd;
    }
}

// Конструктор по умолчанию
Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
    this->isNegative = false;
}

// Конструктор по аргументам
Fraction::Fraction(const uint64_t newNumerator, 
                   const uint64_t newDenominator, 
                   const bool newNegative)
{
    if (!newDenominator)
    {
        throw std::logic_error("Division by zero.");
    }
    this->numerator = newNumerator;
    this->denominator = newDenominator;
    this->isNegative = newNegative;
    this->reduce();
}

// Конструктор копированием
Fraction::Fraction(const Fraction& rhs) : numerator(rhs.numerator),
                                          denominator(rhs.denominator),
                                          isNegative(rhs.isNegative)
{}

// Конструктор перемещением
Fraction::Fraction(Fraction&& rhs) noexcept
{
    std::swap(this->numerator, rhs.numerator);
    std::swap(this->denominator, rhs.denominator);
    std::swap(this->isNegative, rhs.isNegative);
}

// Конструктор преобразования int к дроби
Fraction::Fraction(const int64_t rhs) : numerator(std::abs(rhs)), 
                                        denominator(1),
                                        isNegative(rhs < 0) 
{}

// Оператор "Присваивание"
Fraction& Fraction::operator=(const Fraction& rhs)
{
    if (this != &rhs)
    {
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
        this->isNegative = rhs.isNegative;
    }
    return (*this);
}

// Оператор "Сложение-присваивание"
Fraction& Fraction::operator+=(const Fraction& rhs)
{
    return *this = *this + rhs;
}

// Оператор "Вычитание-присваивание"
Fraction& Fraction::operator-=(const Fraction& rhs)
{
    return *this = *this - rhs;
}

// Оператор "Умножение-присваивание"
Fraction& Fraction::operator*=(const Fraction& rhs)
{
    return *this = *this * rhs;
}

// Оператор "Деление-присваивание"
Fraction& Fraction::operator/=(const Fraction& rhs)
{
    return *this = *this / rhs;
}


// Получение числителя
uint64_t Fraction::getNumerator() const
{
    return this->numerator;
}

// Получение знаменателя
uint64_t Fraction::getDenominator() const
{
    return this->denominator;    
}

// Получение знака 
bool Fraction::getNegative() const
{
    return this->isNegative;
}


// Замена числителя
void Fraction::setNumerator(const uint64_t newNumerator)
{
    this->numerator = newNumerator;
    this->reduce();
}

// Замена знаменателя
void Fraction::setDenominator(const uint64_t newDenominator)
{
    if (!newDenominator)
    {
        throw std::logic_error("Division by zero.");
    }
    this->denominator = newDenominator;
    this->reduce();
}

// Замена знака
void Fraction::setNegative(const bool newNegative)
{
    this->isNegative = newNegative;
}


// Преобразование к типу double
Fraction::operator double() const
{
    return (static_cast<double>(this->numerator) / this-> denominator * (this->isNegative ? -1 : 1));
}

// Преобразование к типу float
Fraction::operator float() const
{
    return (static_cast<float>(this->numerator) / this-> denominator * (this->isNegative ? -1 : 1));    
}

// Оператор "Сложение дробь + дробь"
Fraction Fraction::operator+(const Fraction& rhs) const
{
    int64_t tempNumerator = (this->numerator * (this->isNegative ? -1 : 1)) * rhs.denominator + (rhs.numerator * (rhs.isNegative ? -1 : 1)) * this->denominator;
    uint64_t tempDenominator = this->denominator * rhs.denominator;
    Fraction tmpFraction = Fraction(std::abs(tempNumerator), tempDenominator, tempNumerator < 0);
    tmpFraction.reduce();
    return tmpFraction;
}

// Оператор "Сложение дробь + целое число"
Fraction Fraction::operator+(const int rhs) const
{
    return (*this + Fraction(rhs));
}

// Оператор "Сложение дробь + 64-ёх битное число"
Fraction Fraction::operator+(const int64_t rhs) const
{
    return (*this + Fraction(rhs));
}

// Оператор "Сложение дробь + число с плавающей точкой"
double Fraction::operator+(const double rhs) const
{
    return (static_cast<double>(*this) * (this->isNegative ? -1 : 1) + rhs);
}

// Оператор "Сложение число + дробь"
Fraction operator+(const int rhs, const Fraction& origin)
{
    return (origin + Fraction(rhs));
}

// Оператор "Сложение 64-ёх битное число + дробь"
Fraction operator+(const int64_t rhs, const Fraction& origin)
{
    return (origin + Fraction(rhs));
}

// Оператор "Сложение число с плавающей точкой + дробь"
double operator+(const double rhs, const Fraction& origin)
{
    return (static_cast<double>(origin) * (origin.isNegative ? -1 : 1) + rhs);
}

// Оператор "Вычитание дробь - дробь"
Fraction Fraction::operator-(const Fraction& rhs) const
{
    Fraction tmpFraction = *this + (-rhs);
    return tmpFraction;
}

// Оператор "Вычитание дробь - целое число"
Fraction Fraction::operator-(const int rhs) const
{
    return (*this - Fraction(rhs));
}

// Оператор "Вычитание дробь - 64-ёх битное число"
Fraction Fraction::operator-(const int64_t rhs) const
{
    return (*this - Fraction(rhs));
}

// Оператор "Вычитание дробь - число с плавающей точкой"
double Fraction::operator-(const double rhs) const
{
    return (static_cast<double>(*this) * (this->isNegative ? -1 : 1) - rhs);
}

// Оператор "Вычитание целое число - дробь"
Fraction operator-(const int rhs, const Fraction& origin)
{
    return (origin - Fraction(rhs));
}

// Оператор "Вычитание 64-ёх битное число - дробь"
Fraction operator-(const int64_t rhs, const Fraction& origin)
{
    return (origin - Fraction(rhs));
}

// Оператор "Вычитание число с плавающей точкой - дробь"
double operator-(const double rhs, const Fraction& origin)
{
    return (static_cast<double>(origin) * (origin.isNegative ? -1 : 1) - rhs);
}


// Оператор "Умножение дробь * дробь"
Fraction Fraction::operator*(const Fraction& rhs) const
{
    int64_t tempNumerator = this->numerator * rhs.numerator;
    
    if (this->isNegative)
    {
        tempNumerator *= -1;
    }
    if (rhs.isNegative)
    {
        tempNumerator *= -1;
    } 

    uint64_t tempDenominator = this->denominator * rhs.denominator;
    
    Fraction tmpFraction = Fraction(std::abs(tempNumerator), tempDenominator, tempNumerator < 0);
    tmpFraction.reduce();
    
    return tmpFraction;
}

// Оператор "Умножение дробь * целое число"
Fraction Fraction::operator*(const int rhs) const
{
    return (*this * Fraction(rhs));
}

// Оператор "Умножение дробь * 64-ёх битное число"
Fraction Fraction::operator*(const int64_t rhs) const
{
    return (*this * Fraction(rhs));
}

// Оператор "Умножение дробь * число с плавающей точкой"
double Fraction::operator*(const double rhs) const
{
    return (static_cast<double>(*this) * (this->isNegative ? -1 : 1) * rhs);
}

// Оператор "Умножение целое число * дробь"
Fraction operator*(const int rhs, const Fraction& origin)
{
    return (origin * Fraction(rhs));
}

// Оператор "Умножение 64-ёх битное число * дробь"
Fraction operator*(const int64_t rhs, const Fraction& origin)
{
    return (origin * Fraction(rhs));
}

// Оператор "Умножение число с плавающей точкой * дробь"
double operator*(const double rhs, const Fraction& origin)
{
    return (static_cast<double>(origin) * (origin.isNegative ? -1 : 1) * rhs);
}


// Оператор "Деление дробь / дробь"
Fraction Fraction::operator/(const Fraction& rhs) const
{
    if (rhs == Fraction(0))
    {
        throw std::logic_error("Division by zero.");
    }

    Fraction tmpFraction = *this * (!rhs);
    tmpFraction.reduce();
    
    return tmpFraction;
}

// Оператор "Деление дробь / целое число"
Fraction Fraction::operator/(const int rhs) const
{
    return(*this / Fraction(rhs));
}

// Оператор "Деление дробь / 64-ёх битное число"
Fraction Fraction::operator/(const int64_t rhs) const
{
    return(*this / Fraction(rhs));
}

// Оператор "Деление дробь / число с плавающей точкой"
double Fraction::operator/(const double rhs) const
{
    return (static_cast<double>(*this) * (this->isNegative ? -1 : 1) / rhs);
}

// Оператор "Деление целое число / дробь"
Fraction operator/(const int rhs, const Fraction& origin)
{
    return (Fraction(rhs) / origin);
}

// Оператор "Деление 64-ёх битное число / дробь"
Fraction operator/(const int64_t rhs, const Fraction& origin)
{
    return (Fraction(rhs) / origin);
}

// Оператор "Деление число с плавающей точкой / дробь"
double operator/(const double rhs, const Fraction& origin)
{
    return (rhs / static_cast<double>(origin));
}


bool Fraction::operator==(const Fraction &rhs) const
{
    return this->numerator == rhs.numerator && this->denominator == rhs.denominator;
}

// Оператор "неравно"
bool Fraction::operator!=(const Fraction& rhs) const
{
    return !(*this == rhs);
}

// Оператор "меньше"
bool Fraction::operator<(const Fraction &rhs) const
{
    return this->numerator * rhs.denominator < rhs.numerator * this->denominator;
}

// Оператор "больше"
bool Fraction::operator>(const Fraction &rhs) const
{
    return *this != rhs && !(*this < rhs);
}

// Оператор "меньше или равно"
bool Fraction::operator<=(const Fraction& rhs) const
{
    return !(*this > rhs);
}

// Оператор "больше или равно"
bool Fraction::operator>=(const Fraction& rhs) const
{
    return !(*this < rhs);
}

// Оператор "Унарный минус"
Fraction Fraction::operator-() const
{
    return Fraction(this->numerator, this->denominator, !this->isNegative);
}

// Оператор получения обратной дроби
Fraction Fraction::operator!() const
{
    if (!this->numerator)
    {
        throw std::logic_error("Division by zero.");
    }
    return Fraction(this->denominator, this->numerator, this->isNegative);
}


// Оператор "Вывод"
std::ostream& operator<<(std::ostream& out, const Fraction& rhs)
{
    if (rhs == Fraction(0))
    {
        out << 0;
        return out;
    }
    
    if (rhs.isNegative)
    {
        out << '-';
    }

    out << rhs.numerator << '/' << rhs.denominator;
    
    return out;
}


// Оператор "Ввод"
std::istream& operator>>(std::istream& in, Fraction& rhs)
{
    int64_t tmpNumerator, tmpDenominator;
    in >> tmpNumerator >> tmpDenominator;
    if (tmpDenominator == 0)
    {
        throw std::logic_error("Division by zero.");
    }
    rhs.numerator = tmpNumerator;
    rhs.denominator = tmpDenominator;
    rhs.isNegative = (tmpNumerator < 0 ? true : false);
    return in;
}