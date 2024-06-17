#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <stdexcept>
#include <string.h>
#include <cstring>

// Структура, представляющая студента с именем и идентификатором
struct Student {
    std::string name;   // Имя студента
    int32_t id;         // Идентификатор студента

    // Конструктор, принимающий имя и идентификатор и инициализирующий соответствующие поля
    Student(const std::string& n, int32_t i) : name(n), id(i) {}

    bool operator==(const Student& rhs) const;
    bool operator<(const Student& rhs) const;

    std::string getName() const;
    int32_t getID() const;

    friend std::ostream& operator<<(std::ostream& out, const Student& rhs);

};

// Шаблонный класс, реализующий упорядоченный связанный список
template <class T>
class OrderedLinkedList {
private:
    // Внутренняя структура, представляющая узел списка
    struct Node {
        T data;         // Данные узла типа T
        Node* next;     // Указатель на следующий узел
    };

    Node* head;         // Указатель на голову списка

public:
    // Конструктор по умолчанию
    OrderedLinkedList();

    // Конструктор копирования
    OrderedLinkedList(const OrderedLinkedList& other);

    // Деструктор
    ~OrderedLinkedList();

    // Оператор присваивания
    OrderedLinkedList& operator=(const OrderedLinkedList& other);

    // Оператор индексации [], возвращает ссылку на элемент списка по индексу
    T& operator[](int32_t index);

    // Метод для добавления элемента в список
    void addElement(const T& value);

    // Метод для удаления элемента из списка
    void removeElement(const T& value);

    // Метод для объединения двух списков
    void mergeLists(OrderedLinkedList& otherList);

    // Метод для удаления повторяющихся элементов из списка
    void keepUnique();

};

#include "Student.inl"

#endif  // STUDENT_HPP
