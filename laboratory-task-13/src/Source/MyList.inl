#include "MyList.hpp"


template <typename T>
struct MyList<T>::Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr)
    {}
};

// Конструктор по умолчанию
template <typename T>
MyList<T>::MyList() : first(nullptr), last(nullptr)
{}

// Конструктор копирования
template <typename T>
MyList<T>::MyList(const MyList<T>& rhs) {
    *this = rhs;
}

// Деструктор
template <typename T>
MyList<T>::~MyList()
{
    while (first != nullptr)
    {
        pop_front();
    }
}

// Оператор присваивания
template <typename T>
MyList<T>& MyList<T>::operator=(const MyList& rhs)
{
    if (this != &rhs && first != nullptr)
    {
        Node* current = new Node(rhs.first->data);
        first = current;
        Node* temp = rhs.first;
        while (temp->next)
        {
            temp = temp->next;
            Node* newEl = new Node(temp->data);
            current->next = newEl;
            current = newEl;
        }
    }
    return *this;
}

// Проверка на пустоту
template <typename T>
bool MyList<T>::isEmpty()
{
    return first == nullptr;
}

// Добавление жлемента в конец списка
template <typename T>
void MyList<T>::push_back(const T& val)
{
    Node* newEl = new Node(val);
    if (isEmpty())
    {
        first = newEl;
        last = newEl;
        return;
    }
    last->next = newEl;
    last = newEl;
}

// Добавление элемента в начало списка
template <typename T>
void MyList<T>::push_front(const T& val)
{
    Node* newEl = new Node(val);
    if (isEmpty())
    {
        first = newEl;
        last = newEl;
        return;
    }
    newEl->next = first;
    first = newEl;
}

// Удаление элемента из начала списка
template <typename T>
void MyList<T>::pop_front()
{
    if (isEmpty())
    {
        throw std::logic_error("List is already empty.");
    }

    Node* temp = first;
    first = first->next;
    delete temp;
}

// Удаление элемента из конца списка
template <typename T>
void MyList<T>::pop_back()
{
    if(isEmpty()) {
        throw std::logic_error("List is empty");
    }
    if(last == first) {
        pop_front();
        return;
    }
    Node* temp = first;
    while(temp->next != last){
        temp = temp->next;
    }
    temp->next = nullptr;
    delete last;
    last = temp;
}

// Удаление элемента по значению
template <typename T>
void MyList<T>::pop_value(const T& value)
{
    if (isEmpty())
    {
        throw std::logic_error("List is already empty.");
    }

    if (first->data == value)
    {
        pop_front();
        return;
    }
    
    if (last->data == value)
    {
        pop_back();
        return;
    }
    
    Node* slow = first;
    Node* fast = first->next;
    
    while (fast && fast->data != value)
    {
        slow = slow->next;
        fast = fast->next;
    }

    if (!fast)
    {
        throw std::logic_error("No such element to delete.");
    }

    slow->next = fast->next;
    delete fast;
}

// Поиск элемента с подсчётом количества сравнений
template <typename T>
bool MyList<T>::find(const T& value)
{
    if (isEmpty())
    {
        throw std::logic_error("List is empty.");
    }

    Node* current = first;
    size_t counter = 1;
    
    while (current && current->data != value)
    {
        current = current->next;
        ++counter;
    }

    if (!current)
    {
        std::cout << "Element not found. Number of comparisons: " << counter << '\n';
        return false;
    }

    std::cout << "Element found. Number of comparisons: " << counter << '\n';
    return true;
}

// Просмотр списка
template <typename T>
void MyList<T>::changePrint()
{
    Node* current = first;
    
    while (current != nullptr)
    {
        std::cout << "Current value: " << current->data << ". Enter new value:\n";
        std::cin >> current->data;
        current = current->next;
    }

}

// Просмотр списка с использование callback-функции
template <typename T>
void MyList<T>::callBackPrint(void func(T)) const
{
    Node* current = first;

    while(current != nullptr)
    {
        func(current->data);
        current = current -> next;
    }
}
