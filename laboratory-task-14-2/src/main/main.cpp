#include <iostream>
#include <random>
#include "../Source/Student.hpp"
#include "../Source/StudentFirstSession.hpp"
#include "../Source/StudentYear.hpp"


// Функция для случайного заполнения динамического массива int32_t
int32_t* randomFillArray(size_t size) {
    // Выделение памяти под массив
    int32_t* array = new int32_t[size];
    
    // Инициализация генератора случайных чисел
    
    // Заполнение массива случайными значениями
    for (int i = 0; i < size; i++) {
        array[i] = 1 +rand() % 10; // Заполняем каждый элемент случайным числом
    }
    
    return array; // Возвращаем указатель на заполненный массив
}


int main()
{
    srand(time(NULL));
    int32_t* marksFirst1 = new int32_t[4];
    int32_t* marksFirst2 = new int32_t[4];
    int32_t* marksFirst3 = new int32_t[4];
    int32_t* marksFirst4 = new int32_t[4];

    int32_t* marksSecond1 = new int32_t[5];
    int32_t* marksSecond2 = new int32_t[5];
    int32_t* marksSecond3 = new int32_t[5];
    int32_t* marksSecond4 = new int32_t[5];

    marksFirst1 = randomFillArray(4);
    marksFirst2 = randomFillArray(4);
    marksFirst3 = randomFillArray(4);
    marksFirst4 = randomFillArray(4);

    marksSecond1 = randomFillArray(5);
    marksSecond2 = randomFillArray(5);
    marksSecond3 = randomFillArray(5);
    marksSecond4 = randomFillArray(5);

    StudentYear a(std::string("Bob"), 1, 2, 43, marksFirst1, marksSecond1);
    StudentYear b(std::string("John"), 2, 3, 1241, marksFirst2, marksSecond2);
    StudentYear c(std::string("Gortash"), 2, 2, 132, marksFirst3, marksSecond3);
    StudentYear d(std::string("Ivan"), 2, 2, 132, marksFirst4, marksSecond4);
    
    delete[] marksFirst1;
    delete[] marksFirst2;
    delete[] marksFirst3;
    delete[] marksFirst4;

    delete[] marksSecond1;
    delete[] marksSecond2;
    delete[] marksSecond3;
    delete[] marksSecond4;

    StudentYear** arr = new StudentYear*[4];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    arr[3] = &d;
    
    double marksFirstSessionSum = 0;
    double marksYearSum = 0;

    for (size_t i = 0; i < 4; ++i)
    {
        marksFirstSessionSum += arr[i]->StudentFirstSession::mediumMark();
        marksYearSum += arr[i]->StudentYear::mediumMark();
    }

    std::cout << "Medium marks for the first semester:\n" << marksFirstSessionSum / 4;

    std::cout << "\nMedium marks for the year:\n" << marksYearSum / 4 << '\n';

    return 0;
}
