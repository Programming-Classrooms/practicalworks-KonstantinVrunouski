#ifndef MYLIST_HPP
#define MYLIST_HPP

#include <iostream>
#include <exception>


template <typename T>
class MyList
{
private:
    struct Node;
    Node* first;
    Node* last;

public:

    // Конструктр по умолчанию
    MyList();

    // Конструктор копирования
    MyList(const MyList<T>&);

    // Деструктор
    ~MyList();

    // Проверка на пустоту списка
    bool isEmpty();

    // Перегрузка оператора присваивания
    MyList<T>& operator=(const MyList<T>&);

    // Вставка элемента в конец списка
    void push_back(const T&);

    // Вставка элемента в начало списка
    void push_front(const T&);

    // Удаление элемента в начале списка
    void pop_front();

    // Удаление элемента в конце списка
    void pop_back();

    // Удаление элемента по значению
    void pop_value(const T&);

    // Поиск элемента с подсчётом количества сравнений
    bool find(const T&);

    // Просмотр списка
    void changePrint();

    // Просмотр списка с использование callback-функции
    void callBackPrint(void func(T)) const;
};

#include "MyList.inl"

#endif //MYLIST_HPP
