#include "TDeque.hpp"

template <class T>
void TDeque<T>::Erase()
{
	while (size > 0)
	{
		DeleteItem(front);
	}
}

template <class T>
void TDeque<T>::Clone(const TDeque &rhs)
{
	TDequeItem* temp = rhs.front;
	while (temp != nullptr) {
		InsRear(temp->Info);
		temp = temp->next;
	}
}

template<class T>
void TDeque<T>::DeleteItem(TDequeItem* rhs)
{
	if (rhs->next == nullptr && rhs->prev == nullptr)
	{
		front = rear = nullptr;
	}
	if (rhs->next == nullptr && rhs->prev != nullptr)
	{
		rear = rhs->prev;
		rhs->prev->next = nullptr;
	}
	if (rhs->next != nullptr && rhs->prev == nullptr)
	{
		front = rhs->next;
		rhs->next->prev = nullptr;
	}
	if (rhs->next != nullptr && rhs->prev != nullptr) {
		rhs->next->prev = rhs->prev;
		rhs->prev->next = rhs->next;
	}

	delete rhs;
	--size;
}

template<class T>
void* TDeque<T>::PtrByIndex(unsigned index) const
{
	if (index >= size) {
		return nullptr;
	}
	TDequeItem* temp = front;
	while (index > 0) {
		temp = temp->next;
		--index;
	}
	return temp;
}

template<class T>
TDeque<T>::TDeque() : front(nullptr), rear(nullptr), size(0)
{
}

template<class T>
TDeque<T>::TDeque(const TDeque& rhs) : front(nullptr), rear(nullptr), size(0)
{
	Clone(rhs);
}

template<class T>
TDeque<T>::~TDeque()
{
	Erase();
}

template<class T>
void TDeque<T>::InsFront(T info)
{
	TDequeItem* item = new TDequeItem;
	item->Info = info;
	item->next = front;
	item->prev = nullptr;
	if (front != nullptr) {
		front->prev = item;
	}
	front = item;
	if (rear == nullptr) {
		rear = item;
	}
	++size;
}

template<class T>
void TDeque<T>::InsRear(T info)
{
	TDequeItem* item = new TDequeItem;
	item->Info = info;
	item->next = nullptr;
	item->prev = rear;
	if (rear != nullptr) {
		rear->next = item;
	}
	rear = item;
	if (front == nullptr) {
		front = item;
	}
	++size;
}

template<class T>
bool TDeque<T>::DelFront(T& info)
{
	if (front == nullptr) {
		return false;
	}
	info = front->Info;
	DeleteItem(front);
	return true;
}

template<class T>
bool TDeque<T>::DelRear(T& info)
{
	if (rear == nullptr) {
		return false;
	}
	info = rear->Info;
	DeleteItem(rear);
	return true;
}

template<class T>
const TDeque<T>& TDeque<T>::operator=(const TDeque& rhs)
{
	if (this != &rhs) {
		Erase();
		Clone(rhs);
	}
	return *this;
}

template<class T>
const T& TDeque<T>::GetByIndex(unsigned index) const
{
	TDequeItem* item = static_cast<TDequeItem*>(PtrByIndex(index));
	return item->Info;
}

template<class T>
void TDeque<T>::SetByIndex(T info, unsigned index)
{
	TDequeItem* item = static_cast<TDequeItem*>(PtrByIndex(index));
	if (item != nullptr) {
		item->Info = info;
	}
}

template<class T>
void TDeque<T>::Browse(std::function <void(T&)> func)
{
	TDequeItem* temp = front;
	while (temp != nullptr) {
		func(temp->Info);
		temp = temp->next;
	}
}


template<class T>
void TDeque<T>::Browse(std::function <void(T&)> func) const
{
	TDequeItem* temp = front;
	while (temp != nullptr) {
		func(temp->Info);
		temp = temp->next;
	}
}
