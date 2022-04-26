#ifndef __STACK_H__
#define __STACK_H__

#include "../GenericLinkedList/linkedlist.h"
#include <stdexcept>
template <typename T>
class Stack
{
private:
    List<T> _list;

public:
    Stack();
    ~Stack();
    T pop();
    T peek() const;
    void push(const T &);
    bool isEmpty() const;
};

template <typename T>
Stack<T>::Stack() = default;

template <typename T>
Stack<T>::~Stack()
{
    _list.removeAll();
}

template <typename T>
T Stack<T>::pop()
{
    T return_value = peek();
    _list.removeAt(_list.GetCount() - 1);
    return return_value;
}

template <typename T>
T Stack<T>::peek() const
{
    if (isEmpty())
    {
        throw invalid_argument("Error! Stack is Empty");
    }
    return _list.getElement(_list.GetCount() - 1);
}

template <typename T>
void Stack<T>::push(const T &value)
{
    _list.Add(value);
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return _list.GetCount() == 0;
}

#endif // __STACK_H__