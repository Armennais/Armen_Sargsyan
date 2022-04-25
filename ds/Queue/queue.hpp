#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../GenericLinkedList/linkedlist.h"

template <typename T>
class Queue
{
private:
    List<T> _list;

public:
    Queue() = default;
    ~Queue()
    {
        _list.removeAll();
    }
    void push(T);
    T pop();
    T front() const;
    T back() const;
    bool isEmpty() const;
};
template <typename T>
void Queue<T>::push(T value)
{
    _list.Add(value);
}

template <typename T>
T Queue<T>::pop()
{
    T return_value = front();
    _list.removeAt(_list.GetCount() - 1);
    return return_value;
}

template <typename T>
T Queue<T>::front() const
{
    return _list.getElement(0);
}

template <typename T>
T Queue<T>::back() const
{
    return _list.getElement(_list.GetCount() - 1);
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return _list.GetCount() == 0;
}

#endif // __QUEUE_H__