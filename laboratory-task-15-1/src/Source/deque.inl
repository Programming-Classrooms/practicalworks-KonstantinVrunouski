#include "deque.hpp"

template<typename TInfo>
void TDeque<TInfo>::Erase()
{
    TDequeItem* temp = rear;

    while (temp != nullptr)
    {
        temp = temp->prev;
        delete temp->next;
        --size;
    }
}

template<>
void TDeque<char*>::Erase()
{
    TDequeItem* temp = rear;

    while (temp != nullptr)
    {
        delete[] temp->Info;
        temp = temp->prev;
        delete temp->next;
        --size;
    }
}

template<>
void TDeque<int>::Erase()
{
    TDequeItem* temp = rear;
    
    while (temp != nullptr)
    {
        temp = temp->prev;
        delete temp->next;
        --size;
    }
}

template <typename TInfo>
void TDeque<TInfo>::Clone(const TDeque & rhs)
{
    if (this != &rhs)
    {
        *this(rhs);
    }
}

template <typename TInfo>
void TDeque<TInfo>::DelFront()
{
    front = front->next;
    delete front->prev;
    front->prev = nullptr;
}


template <>
void TDeque<char*>::DelFront()
{
    front = front->next;
    delete[] front->prev->Info;
    delete front->prev;
    front->prev = nullptr;
}

template <typename TInfo>
void TDeque<TInfo>::DelRear()
{
    rear = rear->prev;
    delete rear->next;
    rear->next = nullptr;
}

template <>
void TDeque<char*>::DelRear()
{
    rear = rear->prev;
    delete[] rear->next->Info;
    delete rear->next;
    rear->next = nullptr;
}

template <typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem* item)
{
    if (item->prev == nullptr && item->next != nullptr)
    {
        this->DelFront();
    }
    else if (item->prev != nullptr && item->next == nullptr)
    {
        this->DelRear();
    }
    else
    {
        item->prev->next = item->next;
        delete item;
    }
}

template <>
void TDeque<char*>::DeleteItem(TDequeItem* item)
{
    if (item->prev == nullptr && item->next != nullptr)
    {
        this->DelFront();
    }
    else if (item->prev != nullptr && item->next == nullptr)
    {
        this->DelRear();
    }
    else
    {
        item->prev->next = item->next;
        delete[] item->Info;
        delete item;
    }
}

template <typename TInfo>
void* TDeque<TInfo>::PtrByIndex(size_t ind) const
{
    TDequeItem* temp = front; 
    
    for (size_t i = 0; i < ind; ++i)
    {
        temp = temp->next;
    }

    return temp;
}

template <typename TInfo>
TDeque<TInfo>::TDeque()
{
    front = nullptr;
    rear = nullptr;
    size = 0;
}

template <>
TDeque<char*>::TDeque(const TDeque & origin)
{
    if (origin.front == nullptr)
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
        return;
    }

    size = origin.size;

    TDequeItem* tempOrigin = origin.front;
    TDequeItem* temp = nullptr;
    front = temp;

    while (tempOrigin != nullptr)
    {
        temp = new TDequeItem;
        strcpy(temp->Info, tempOrigin->Info);
        temp = temp->next;
        tempOrigin = tempOrigin->next;
    }
    rear = temp;
}

template<typename TInfo>
TDeque<TInfo>::~TDeque()
{
    this->Erase();
}

template <typename TInfo>
void TDeque<TInfo>::InsFront(const TInfo val)
{
    TDequeItem* temp = new TDequeItem;
    temp->Info = val;
    temp->next = front;
    front = temp;
}

template <>
void TDeque<char*>::InsFront(char* val)
{
    TDequeItem* temp = new TDequeItem;
    strcpy(temp->Info, val);
    temp->next = front;
    front = temp;
}

template <typename TInfo>
void TDeque<TInfo>::InsRear(TInfo val)
{
    TDequeItem* temp = new TDequeItem;
    temp->Info = val;
    temp->prev = rear;
    rear = temp;
}

template <>
void TDeque<char*>::InsRear(char* val)
{
    TDequeItem* temp = new TDequeItem;
    strcpy(temp->Info, val);
    temp->prev = rear;
    rear = temp;
}

template<typename TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque<TInfo>& source)
{
    if(this == &source) {
        throw std::invalid_argument("Self-education...");
    }
    this->Clone(source);
    return *this;
}

template<typename TInfo>
const TInfo& TDeque<TInfo>::GetByIndex(size_t index) const
{
    return PtrByIndex(index)->info;
}

template<typename TInfo>
void TDeque<TInfo>::SetByIndex(TInfo value, size_t index)
{
    PtrByIndex(index)->info = value;
}

template<typename TInfo>
void TDeque<TInfo>::BrowseWithModification(std::function<void(TInfo&)> func)
{
    TDequeItem* item = this->rear;
    while (item != nullptr) {
        func(item->info);
        item = item->next;
    }
}

// Просмотр без изменения элементов
template<typename TInfo>
void TDeque<TInfo>::BrowseWithoutModification(std::function<void(TInfo)> func) const
{
    TDequeItem* item = this->rear;
    while (item != nullptr) {
        func(item->info);
        item = item->next;
    }
}