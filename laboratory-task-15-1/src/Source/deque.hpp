#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <string.h>
#include <iostream>
#include <functional>


template <typename TInfo>
class TDeque /* дек – двусторонняя очередь */
{
protected:

struct TDequeItem // элемент дека
{
TInfo Info; // данные
TDequeItem* next; // указатель на следующий элемент
TDequeItem* prev; // указатель на предыдущий элемент
/* указатели на первый и последний элементы в списке */
};

TDequeItem *front, *rear;

int size; // количество элементов в деке

void Erase(); // удаление всех элементов

void Clone(const TDeque&);

void DeleteItem(TDequeItem*); // удаление элемента по указателю

void* PtrByIndex(size_t) const; // указатель на элемент с заданным индексом

public:
TDeque(); // конструктор
TDeque(const TDeque &); // конструктор копирования

virtual ~TDeque(); // деструктор

void InsFront(TInfo); // включить элемент в голову дека
void InsRear(TInfo); // включить элемент в хвост дека

void DelFront(); // исключить элемент из головы дека
void DelRear(); // исключить элемент из хвоста дека

const TDeque& operator = (const TDeque &);// оператор присваивания

const TInfo& GetByIndex(size_t)const; // получить элемент по индексу
void SetByIndex(TInfo, size_t); // изменить элемент по индексу

void BrowseWithModification(std::function<void(TInfo&)> func); // просмотр с изменением элементов

void BrowseWithoutModification(std::function<void(TInfo)> func) const; // просмотр без изменения элементов

};

#include "deque.inl"

#endif
