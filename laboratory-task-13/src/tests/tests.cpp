#include "../Source/Fraction.hpp"
#include "../Source/Matrix.hpp"
#include "../Source/MyList.hpp"
#include <stdexcept>
#include <gtest/gtest.h>

// Тест метода сокращения дроби
TEST(FractionTest, ReduceMethod) {
    Fraction f(6, 8, false);
    EXPECT_EQ(f.getNumerator(), 3);
    EXPECT_EQ(f.getDenominator(), 4);
}

// Тест конструктора по умолчанию
TEST(FractionTest, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(f.getNumerator(), 0);
    EXPECT_EQ(f.getDenominator(), 1);
    EXPECT_FALSE(f.getNegative());
}

// Тест конструктора по аргументам
TEST(FractionTest, ParameterizedConstructor) {
    Fraction f(3, 4, false);
    EXPECT_EQ(f.getNumerator(), 3);
    EXPECT_EQ(f.getDenominator(), 4);
    EXPECT_FALSE(f.getNegative());
}

// Тест оператора присваивания
TEST(FractionTest, AssignmentOperator) {
    Fraction f1(3, 4, false);
    Fraction f2 = f1;
    EXPECT_EQ(f2.getNumerator(), 3);
    EXPECT_EQ(f2.getDenominator(), 4);
    EXPECT_FALSE(f2.getNegative());
}

// Тест оператора сложения-присваивания
TEST(FractionTest, AdditionAssignmentOperator) {
    Fraction f1(1, 2, false);
    Fraction f2(1, 3, false);
    f1 += f2;
    EXPECT_EQ(f1.getNumerator(), 5);
    EXPECT_EQ(f1.getDenominator(), 6);
}

// Тест оператора сложения
TEST(FractionTest, AdditionOperator) {
    Fraction f1(1, 2, false);
    Fraction f2(1, 3, false);
    Fraction result = f1 + f2;
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 6);
}

// Тест оператора вычитания
TEST(FractionTest, SubtractionOperator) {
    Fraction f1(3, 4, false);
    Fraction f2(1, 4, false);
    Fraction result = f1 - f2;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

// Тест оператора умножения
TEST(FractionTest, MultiplicationOperator) {
    Fraction f1(1, 2, false);
    Fraction f2(2, 3, false);
    Fraction result = f1 * f2;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 3);
} 

// Тест оператора деления дробь / дробь
TEST(FractionTest, DivisionOperator_FractionByFraction) {
    Fraction f1(3, 4, false);
    Fraction f2(1, 2, false);
    Fraction result = f1 / f2;
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 2);
}

// Тест оператора деления дробь / целое число
TEST(FractionTest, DivisionOperator_FractionByInteger) {
    Fraction f1(3, 4, false);
    int divisor = 2;
    Fraction result = f1 / divisor;
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 8);
}

// Тест оператора деления дробь / 64-ёх битное число
TEST(FractionTest, DivisionOperator_FractionByInt64) {
    Fraction f1(3, 4, false);
    Fraction result = (f1 / 2);
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 8);
}

// Тест оператора деления дробь / число с плавающей точкой
TEST(FractionTest, DivisionOperator_FractionByDouble) {
    Fraction f1(3, 4, false);
    double divisor = 0.5;
    double result = f1 / divisor;
    EXPECT_DOUBLE_EQ(result, 1.5);
}

// Тест деления на ноль
TEST(FractionTest, DivisionByZero) {
    Fraction f(3, 4, false);
    Fraction zero(0, 1, false);
    EXPECT_THROW({
        try {
            Fraction result = f / zero;
        } catch (const std::logic_error& e) {
            EXPECT_STREQ(e.what(), "Division by zero.");
            throw;
        }
    }, std::logic_error);
}

// Тест оператора приведения к типу double
TEST(FractionTest, TypeConversionToDouble) {
    Fraction f(3, 4, false);
    double result = static_cast<double>(f);
    EXPECT_DOUBLE_EQ(result, 0.75);
}

// Тест оператора приведения к типу float
TEST(FractionTest, TypeConversionToFloat) {
    Fraction f(3, 4, false);
    float result = static_cast<float>(f);
    EXPECT_FLOAT_EQ(result, 0.75f);
}

// Тест оператора получения обратной дроби
TEST(FractionTest, InverseOperator) {
    Fraction f(3, 4, false);
    Fraction result = !f;
    EXPECT_EQ(result.getNumerator(), 4);
    EXPECT_EQ(result.getDenominator(), 3);
    EXPECT_FALSE(result.getNegative());
}

// Тест оператора унарного минуса
TEST(FractionTest, UnaryMinusOperator) {
    Fraction f(3, 4, false);
    Fraction result = -f;
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 4);
    EXPECT_TRUE(result.getNegative());
}

// Тест конструктора по умолчанию
TEST(MatrixTest, DefaultConstructor) {
    Matrix m;
    EXPECT_EQ(m.getRows(), 0);
    EXPECT_EQ(m.getCols(), 0);
}

// Тест конструктора по аргументам
TEST(MatrixTest, ParametrizedConstructor) {
    Matrix m(2, 3);
    EXPECT_EQ(m.getRows(), 2);
    EXPECT_EQ(m.getCols(), 3);
    EXPECT_NO_THROW(m.setElement(1, 2, 5.0)); // Установка значения элемента
    EXPECT_EQ(m.getElement(1, 2), 5.0); // Проверка установленного значения
    EXPECT_THROW(m.setElement(2, 3, 5.0), std::invalid_argument); // Проверка исключения на недопустимый доступ
}

// Тест оператора присваивания
TEST(MatrixTest, AssignmentOperator) {
    Matrix m1(2, 2);
    m1.setElement(0, 0, 1.0);
    m1.setElement(0, 1, 2.0);
    m1.setElement(1, 0, 3.0);
    m1.setElement(1, 1, 4.0);

    Matrix m2 = m1;
    EXPECT_EQ(m2.getRows(), 2);
    EXPECT_EQ(m2.getCols(), 2);
    EXPECT_EQ(m2.getElement(0, 0), 1.0);
    EXPECT_EQ(m2.getElement(0, 1), 2.0);
    EXPECT_EQ(m2.getElement(1, 0), 3.0);
    EXPECT_EQ(m2.getElement(1, 1), 4.0);
}

// Тест операторов сложения, вычитания и умножения
TEST(MatrixTest, ArithmeticOperators) {
    Matrix m1(2, 2);
    m1.setElement(0, 0, 1.0);
    m1.setElement(0, 1, 2.0);
    m1.setElement(1, 0, 3.0);
    m1.setElement(1, 1, 4.0);

    Matrix m2(2, 2);
    m2.setElement(0, 0, 2.0);
    m2.setElement(0, 1, 3.0);
    m2.setElement(1, 0, 4.0);
    m2.setElement(1, 1, 5.0);

    // Проверка сложения
    Matrix sum = m1 + m2;
    EXPECT_EQ(sum.getElement(0, 0), 3.0);
    EXPECT_EQ(sum.getElement(0, 1), 5.0);
    EXPECT_EQ(sum.getElement(1, 0), 7.0);
    EXPECT_EQ(sum.getElement(1, 1), 9.0);

    // Проверка вычитания
    Matrix diff = m2 - m1;
    EXPECT_EQ(diff.getElement(0, 0), 1.0);
    EXPECT_EQ(diff.getElement(0, 1), 1.0);
    EXPECT_EQ(diff.getElement(1, 0), 1.0);
    EXPECT_EQ(diff.getElement(1, 1), 1.0);

    // Проверка умножения на скаляр
    Matrix scaled = m1 * 2.0;
    EXPECT_EQ(scaled.getElement(0, 0), 2.0);
    EXPECT_EQ(scaled.getElement(0, 1), 4.0);
    EXPECT_EQ(scaled.getElement(1, 0), 6.0);
    EXPECT_EQ(scaled.getElement(1, 1), 8.0);
}

// Тест операторов сравнения
TEST(MatrixTest, ComparisonOperators) {
    Matrix m1(2, 2);
    m1.setElement(0, 0, 1.0);
    m1.setElement(0, 1, 2.0);
    m1.setElement(1, 0, 3.0);
    m1.setElement(1, 1, 4.0);

    Matrix m2(2, 2);
    m2.setElement(0, 0, 1.0);
    m2.setElement(0, 1, 2.0);
    m2.setElement(1, 0, 3.0);
    m2.setElement(1, 1, 4.0);

    Matrix m3(2, 2);
    m3.setElement(0, 0, 2.0);
    m3.setElement(0, 1, 3.0);
    m3.setElement(1, 0, 4.0);
    m3.setElement(1, 1, 5.0);

    EXPECT_TRUE(m1 == m2);
    EXPECT_FALSE(m1 == m3);
    EXPECT_TRUE(m1 != m3);
    EXPECT_FALSE(m1 != m2);
}

// Тест оператора умножения матриц
TEST(MatrixTest, MatrixMultiplication) {
    Matrix m1(2, 3);
    m1.setElement(0, 0, 1.0);
    m1.setElement(0, 1, 2.0);
    m1.setElement(0, 2, 3.0);
    m1.setElement(1, 0, 4.0);
    m1.setElement(1, 1, 5.0);
    m1.setElement(1, 2, 6.0);

    Matrix m2(3, 2);
    m2.setElement(0, 0, 7.0);
    m2.setElement(0, 1, 8.0);
    m2.setElement(1, 0, 9.0);
    m2.setElement(1, 1, 10.0);
    m2.setElement(2, 0, 11.0);
    m2.setElement(2, 1, 12.0);

    Matrix result = m1 * m2;
    EXPECT_EQ(result.getRows(), 2);
    EXPECT_EQ(result.getCols(), 2);
    EXPECT_EQ(result.getElement(0, 0), 58.0);
    EXPECT_EQ(result.getElement(0, 1), 64.0);
    EXPECT_EQ(result.getElement(1, 0), 139.0);
    EXPECT_EQ(result.getElement(1, 1), 154.0);
}

// Тест метода setElement для проверки исключения
TEST(MatrixTest, SetElementOutOfRange) {
    Matrix m(2, 2);
    EXPECT_THROW(m.setElement(2, 2, 5.0), std::invalid_argument);
}

// Тест конструктора по умолчанию для списка
TEST(MyListTest, DefaultConstructor) {
    MyList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

// Тест конструктора копированием
TEST(MyListTest, CopyConstructor) {
    MyList<int> original;
    original.push_back(1);
    original.push_back(2);
    MyList<int> copied(original);

    EXPECT_FALSE(copied.isEmpty());
    EXPECT_EQ(copied.find(1), true);
    EXPECT_EQ(copied.find(2), true);
}

// Тест для push_back() и push_front()
TEST(MyListTest, PushBackAndFront) {
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(3);

    EXPECT_EQ(list.find(1), true);
    EXPECT_EQ(list.find(2), true);
    EXPECT_EQ(list.find(3), true);
}

// Тест для pop_back() и pop_front()
TEST(MyListTest, PopFrontAndBack) {
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();
    EXPECT_EQ(list.find(1), false);

    list.pop_back();
    EXPECT_EQ(list.find(3), false);
}

// Тест удаления элемента по значению
TEST(MyListTest, PopValue) {
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_value(2);
    EXPECT_EQ(list.find(2), false);
}

// Тест find() для поиска элемента в списке
TEST(MyListTest, FindElement) {
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.find(2), true);
    EXPECT_EQ(list.find(4), false);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
