#include <iostream>
#include "Matrix.hpp"

// Конструктор по умолчанию
Matrix::Matrix() : rows(0), cols(0), data(nullptr) {}

// Конструктор по аргументам
Matrix::Matrix(size_t numRows, size_t numCols) : rows(numRows), cols(numCols) {
    data = new double*[rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols]();
    }
}

// Конструктор копированием
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double*[rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Конструктор пермещением
Matrix::Matrix(Matrix&& other) noexcept {
    std::swap(cols, other.cols);
    std::swap(rows, other.rows);
    std::swap(data, other.data);
}

// Деструктор
Matrix::~Matrix() {
    if (data != nullptr) {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = rhs.rows;
        cols = rhs.cols;
        data = new double* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rhs.data[i][j];
            }
        }
    }
    return *this;
}

// Операторы составного присваивания
Matrix& Matrix::operator+=(const Matrix& rhs)
{
    return *this = *this + rhs;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    return *this = *this - rhs;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
    return *this = *this * rhs;
}

Matrix& Matrix::operator*=(const int32_t rhs)
{
    return *this = *this * rhs;
}

Matrix& Matrix::operator*=(const double rhs)
{
    return *this = *this * rhs;
}

Matrix& Matrix::operator/=(const int32_t rhs)
{
    return *this = *this / rhs;
}

Matrix& Matrix::operator/=(const double rhs)
{
    return *this = *this / rhs;
}

// Сетер
void Matrix:: setElement(size_t row, size_t col, double value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = value;
    }
    else {
        throw std::invalid_argument("Error: Index out of range.");
    }
}

// Гетеры
double Matrix::getElement(size_t row, size_t col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return data[row][col];
    }
    throw std::invalid_argument("Error: Index out of range.");
}

size_t Matrix::getRows() const {
    return rows;
}

size_t Matrix::getCols() const {
    return cols;
}

// Оператор сложения
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Error: Matrices must have the same dimensions for addition.");
    }

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Оператор вычитания
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Error: Matrices must have the same dimensions for subtraction.");
    }

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Операторы умножения
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.");
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(const double rhs) const
{
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * rhs;
        }
    }
    return result;
}

Matrix operator*(const double rhs, const Matrix& origin)
{
    Matrix result(origin.rows, origin.cols);
    for (size_t i = 0; i < origin.rows; ++i) {
        for (size_t j = 0; j < origin.cols; ++j) {
            result.data[i][j] = origin.data[i][j] * rhs;
        }
    }
    return result;
}

Matrix Matrix::operator*(const int32_t rhs) const
{
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * rhs;
        }
    }
    return result;
}

Matrix operator*(const int32_t rhs, const Matrix& origin)
{
    Matrix result(origin.rows, origin.cols);
    for (size_t i = 0; i < origin.rows; ++i) {
        for (size_t j = 0; j < origin.cols; ++j) {
            result.data[i][j] = origin.data[i][j] * rhs;
        }
    }
    return result;
}

// Операторы деления
Matrix Matrix::operator/(const int32_t rhs) const
{
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] / rhs;
        }
    }
    return result;
}

Matrix Matrix::operator/(const double rhs) const
{
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] / rhs;
        }
    }
    return result;
}

// Операторы сравнения
bool Matrix::operator==(const Matrix& rhs) const
{
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (data[i][j] != rhs.data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& rhs) const
{
    return !(*this == rhs);
}

// Оператор ввода
std::istream& operator>>(std::istream& is, const Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

// Оператор вывода 
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    if (matrix.data == nullptr) {
        os << "Matrix is empty.\n";
        return os;
    }
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << std::setw(5) << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
