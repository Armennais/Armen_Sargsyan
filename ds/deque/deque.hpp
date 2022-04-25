#ifndef __DEQUE_H__
#define __DEQUE_H__

#include "../GenericLinkedList/linkedlist.h"

template <typename T>
class Deque
{
private:
    List<T> _list;

public:
    Deque() = default;
    ~Deque()
    {
        _list.removeAll();
    }

    void pushFront(T);
    void pushBack(T);

    T popFront();
    T popBack();

    T firstData() const;
    T lastData() const;

    bool isEmpty() const;
};

template <typename T>
void Deque<T>::pushFront(T)
{
    _list.Add(0);
}

template <typename T>
void Deque<T>::pushBack(T value)
{
    _list.Add(value);
}

template <typename T>
T Deque<T>::popFront()
{
    T return_value = firstData();
    _list.removeAt(0);
    return return_value;
}

template <typename T>
T Deque<T>::popBack()
{
    T return_value = lastData();
    _list.removeAt(_list.GetCount() - 1);
    return return_value;
}

template <typename T>
T Deque<T>::firstData() const
{
    return _list.getElement(0);
}

template <typename T>
T Deque<T>::lastData() const
{
    return _list.getElement(_list.GetCount() - 1);
}

template <typename T>
bool Deque<T>::isEmpty() const
{
    return _list.GetCount() == 0;
}

#endif // __DEQUE_H__