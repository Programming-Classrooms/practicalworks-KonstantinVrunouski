#include "Student.hpp"

bool Student::operator==(const Student& rhs) const
{
    return (id == rhs.id && name == rhs.name);
}

bool Student::operator<(const Student& rhs) const
{
    return (id < rhs.id);
}

std::string Student::getName() const
{
    return name;
}

int32_t Student::getID() const
{
    return id;
}

std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
    out << "ID: " << rhs.id << "\nName: " << rhs.name;
    return out;  
}


// Конструктор по умолчанию
template <class T>
OrderedLinkedList<T>::OrderedLinkedList() : head(nullptr) {}

// Конструктор копирования
template <class T>
OrderedLinkedList<T>::OrderedLinkedList(const OrderedLinkedList& other) {
    Node* current = other.head;
    while (current) {
        addElement(current->data);
        current = current->next;
    }
}

// Деструктор
template <class T>
OrderedLinkedList<T>::~OrderedLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Оператор присваивания
template <class T>
OrderedLinkedList<T>& OrderedLinkedList<T>::operator=(const OrderedLinkedList& other) {
    if (this == &other) {
        return *this;
    }
    
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    Node* otherCurrent = other.head;
    while (otherCurrent) {
        addElement(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }

    return *this;
}

// Оператор индексации [], возвращает ссылку на элемент списка по индексу
template <class T>
T& OrderedLinkedList<T>::operator[](int index) {
    Node* current = head;
    int currentIndex = 0;

    while (current) {
        if (currentIndex == index) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }

    throw std::out_of_range("Index out of range");
}

// Метод для добавления элемента в список
template <class T>
void OrderedLinkedList<T>::addElement(const T& value) {
    Node* newNode = new Node(value);
    if (!head || value < head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next && !(value < current->next->data)) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Метод для удаления элемента из списка
template <class T>
void OrderedLinkedList<T>::removeElement(const T& value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current && !(current->data == value)) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        }
        else {
            head = current->next;
        }
        delete current;
    }
}

// Метод для объединения двух списков
template <class T>
void OrderedLinkedList<T>::mergeLists(OrderedLinkedList& other) {
    Node* current = head;
    Node* otherCurrent = other.head;

    if (!current) {
        head = other.head;
        other.head = nullptr;
        return;
    }

    if (!otherCurrent) {
        return;
    }

    if (otherCurrent->data < current->data) {
        head = other.head;
        other.head = nullptr;
        merge(other);
        return;
    }

    while (current && otherCurrent) {
        if (current->next && otherCurrent->data > current->next->data) {
            current = current->next;
        }
        else {
            Node* tempNext = current->next;
            current->next = otherCurrent;
            otherCurrent = otherCurrent->next;
            current->next->next = tempNext;
            current = current->next;
        }
    }
}

// Метод для удаления повторяющихся элементов из списка
template <class T>
void OrderedLinkedList<T>::keepUnique() {
    if (!head) {
        return;
    }

    Node* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* nextNext = current->next->next;
            delete current->next;
            current->next = nextNext;
        }
        else {
            current = current->next;
        }
    }
}
