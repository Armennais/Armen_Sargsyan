#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

using namespace std;
#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T>(T data, Node<T> *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

template <class T>
class List
{
    Node<T> *head;
    int count;

public:
    int GetCount() const { return count; }
    void Add(T);
    void AddAt(T, int);
    void removeAt(int);
    void removeAll();
    T getElement(const int) const;
    
    template <class Type>
    friend ostream &operator<<(ostream &out, const List<Type> &);

    List()
    {
        count = 0;
        head = nullptr;
    }
    ~List()
    {
        removeAll();
    }
};
#endif // __LINKEDLIST_H__