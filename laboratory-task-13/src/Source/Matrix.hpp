#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <iomanip>

class Matrix {
private:
    size_t rows;
    size_t cols;
    double** data;

public:
    // Конструктор по умолчанию
    Matrix();

    // Конструктор по аргументам
    Matrix(size_t, size_t);

    // Конструктор копированием
    Matrix(const Matrix&);

    // Конструктор перемещением
    Matrix(Matrix&&) noexcept;

    // Деструктор
    ~Matrix();

    // Оператор присваивания
    Matrix& operator=(const Matrix&);

    // Составные операторы присваивания
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(const int32_t);
    Matrix& operator*=(const double);
    Matrix& operator/=(const int32_t);
    Matrix& operator/=(const double);

    // Сетер
    void setElement(size_t, size_t, double);

    // Гетеры
    double getElement(size_t, size_t) const;
    size_t getRows() const;
    size_t getCols() const;

    // Оператор сложения
    Matrix operator+(const Matrix&) const;

    // Оператор вычитания
    Matrix operator-(const Matrix&) const;

    // Операторы умножения
    Matrix operator*(const Matrix&) const;
    Matrix operator*(const int32_t) const;
    friend Matrix operator*(const int32_t, const Matrix&);
    Matrix operator*(const double) const;
    friend Matrix operator*(const double, const Matrix&);

    // Операторы деления
    Matrix operator/(const int32_t) const;
    Matrix operator/(const double) const;

    // Операторы сравнения
    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;

    // Оператор ввода
    friend std::istream& operator>>(std::istream&, const Matrix&);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix&);
};

#endif
