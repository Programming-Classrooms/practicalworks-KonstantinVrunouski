#ifndef TDEQUE_HPP
#define TDEQUE_HPP
#include <iostream>
#include <functional>


template <class T>
class TDeque /* дек – двустороння очередь */
{
protected:
	struct TDequeItem //  элемент дека
	{
		T Info; // данные
		TDequeItem* next; // указатель на следующий элемент
		TDequeItem* prev; // указатель на предыдущий элемент
	};

	TDequeItem* front, * rear;
	int size; // количество элементов в деке
	void Erase(); //  удаление всех элементов
	void Clone(const TDeque&);
	void DeleteItem(TDequeItem*); // удаление элемента по указателю
	void* PtrByIndex(unsigned)const; // указатель на элемент с заданным индексом
public:
	TDeque(); // конструктор
	TDeque(const TDeque&); //  конструктор копирования
	virtual ~TDeque(); // деструктор
	void InsFront(T); //  включить элемент в голову дека
	void InsRear(T); // включить элемент в хвост дека
	bool DelFront(T&); // исключить элемент из головы дека
	bool DelRear(T&); // исключить элемент из хвоста дека
	const TDeque& operator = (const TDeque&);// оператор присваивания
	const T& GetByIndex(unsigned)const; // получить элемент по	индексу
	void SetByIndex(T, unsigned); // изменить элемент по индексу
	void Browse(std::function <void(T&)> func); // просмотр с изменением элементов
	void Browse(std::function <void(T&)> func) const; // просмотр без изменения 
};

#include "TDeque.inl"
#endif // !DEQUE_HPP
