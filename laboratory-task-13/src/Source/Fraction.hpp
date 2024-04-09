#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cstdint>


class Fraction
{
private:
	uint64_t numerator;
    uint64_t denominator;
    bool isNegative;

    void reduce(); //Приватный метод сокращения дроби
public:
    /*###### Конструкторы #######*/
	Fraction();
    Fraction(const uint64_t, const uint64_t, const bool);
    Fraction(const Fraction&);
    Fraction(Fraction&&) noexcept;
    explicit Fraction(const int64_t);

    /*###### Деструктор ######*/
    ~Fraction(){}

    /*###### Оператор присваивания ######*/
    Fraction& operator=(const Fraction&);

    /*###### Составные операторы присваивания ######*/
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);

    /*###### Гетеры #######*/    
    uint64_t getNumerator() const;
    uint64_t getDenominator() const;
    bool getNegative() const;

    /*###### Сетеры #######*/
    void setNumerator(const uint64_t);
    void setDenominator(const uint64_t);
    void setNegative(const bool);

    /*###### Приведение дроби к другим типам ######*/
    explicit operator double() const;
    explicit operator float() const;

    /*###### Сложение дробь + дробь ######*/
    Fraction operator+(const Fraction&) const;

    /*###### Сложение дробь + число ######*/
    Fraction operator+(const int) const;
    Fraction operator+(const int64_t) const;
    double operator+(const double) const;

    /*###### Сложение число + дробь ######*/
    friend Fraction operator+(const int, const Fraction&);
    friend Fraction operator+(const int64_t, const Fraction&);
    friend double operator+(const double, const Fraction&);

    /*###### Вычитание дробь - дробь ######*/
    Fraction operator-(const Fraction&) const;

    /*###### Вычитание дробь - число ######*/
    Fraction operator-(const int) const;
    Fraction operator-(const int64_t) const;
    double operator-(const double) const;

    /*###### Вычитание число - дробь ######*/
    friend Fraction operator-(const int, const Fraction&);
    friend Fraction operator-(const int64_t, const Fraction&);
    friend double operator-(const double, const Fraction&);

    /*###### Умножение дробь * дробь ######*/
    Fraction operator*(const Fraction&) const;

    /*###### Умножение дробь * число ######*/
    Fraction operator*(const int) const;
    Fraction operator*(const int64_t) const;
    double operator*(const double) const;

    /*###### Умножение число * дробь ######*/
    friend Fraction operator*(const int, const Fraction&);
    friend Fraction operator*(const int64_t, const Fraction&);
    friend double operator*(const double, const Fraction&);

    /*###### Деление дробь / дробь ######*/
    Fraction operator/(const Fraction&) const;

    /*###### Деление дробь / число ######*/
    Fraction operator/(const int) const;
    Fraction operator/(const int64_t) const;
    double operator/(const double) const;

    /*###### Деление дробь / число ######*/
    friend Fraction operator/(const int, const Fraction&);
    friend Fraction operator/(const int64_t, const Fraction&);
    friend double operator/(const double, const Fraction&);

    /*###### Операторы сравнения ######*/
    bool operator==(const Fraction&) const;

    bool operator!=(const Fraction&) const;

    bool operator<(const Fraction&) const;

    bool operator<=(const Fraction&) const;

    bool operator>(const Fraction&) const;

    bool operator>=(const Fraction&) const;

    /*###### Оператор получения обратной дроби*/
    Fraction operator-() const;

    /*###### Оператор получения отрицательной дроби ######*/
    Fraction operator!() const;

    /*###### Оператор вывода в поток*/
    friend std::ostream& operator<<(std::ostream&, const Fraction&);

    /*###### Оператор ввода в поток*/
    friend std::istream& operator>>(std::istream&, Fraction&);
};

#endif //FRACTION_HPP
