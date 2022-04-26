#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
private:
    T * arr;
    int size;
    int capacity;

public:
    MyVector()
    {
        arr = new T[1];
        capacity = 1;
        size = 0;
    }
    ~MyVector()
    {
        delete[] arr;
        arr = new T[1];
        capacity = 1;
        size = 0;
    }
    void AddBack(T);
    void AddFront(T);
    void AddAt(T , int);
    void RemoveAt(int );
    void RemoveAll();
    void RemoveFront();
    T operator [](int) const;
    template <typename Type>
    friend ostream &operator << (ostream &out, const MyVector<Type> &);
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
};

template<typename T>
void MyVector<T>::AddBack(T value)
{
    if (getSize() < getCapacity()) 
    {
        arr[getSize() + 1] = value;
        size++;
    }
    else
    {
        AddAt(value,getSize());
    }
}

template<typename T>
void MyVector<T>::AddFront(T value)
{
    AddAt(value, 0);
}

template<typename T>
void MyVector<T>::AddAt(T value, int index)
{
    if (getSize() > getCapacity()) 
    {
        capacity *= 2;
    }
    T* tempArr = new T[capacity];
    for (int i = 0; i < getSize(); i++) 
    {
        if (i < index)
        {
            tempArr[i] = arr[i];
        }
        else if (i > index)
        {
            tempArr[i] = arr[i - 1];
        }
    }
    tempArr[index] = value;
    delete[] arr;
    arr = tempArr;
    size++;
}

template<typename T>
void MyVector<T>::RemoveAt(int index)
{
    if (getSize() <= getCapacity() / 2 + 1) 
    {
        capacity /= 2;
    }
    T* tempArr = new T[capacity];
    for (int i = 0; i < getSize(); i++) 
    {
        if (i < index)
        {
            tempArr[i] = arr[i];
        }
        else if (i > index)
        {
            tempArr[i] = arr[i + 1];
        }
    }
    delete[] arr;
    arr = tempArr;
    size--;
}

template<typename T>
void MyVector<T>::RemoveAll()
{
    ~MyVector();
}

template<typename T>
void MyVector<T>::RemoveFront()
{
    RemoveAt(0);
}
template<typename T>
T MyVector<T>::operator [] (int index) const
{
    return this->arr[index];
}

template<typename T>
ostream &operator << (ostream &out, const MyVector<T> & n)
{
    for(int i = 0; i < n.getSize(); i++)
    {
        out << n[i] << " ";
    }
    return out;
}

