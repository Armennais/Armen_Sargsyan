#include <iostream>
#include "linkedlist.h"
using namespace std;
template<class T>
void List<T>::Add( T data) {
    if (head == NULL) {
            head = new Node<T>(data);   
    }else
    {
        Node<T>* new_node = head;
        while (new_node->next != nullptr)
        {
            new_node = new_node->next;
        }
        new_node->next = new Node<T>(data);
    }
    count++;
}
template<class T>
void List<T>::AddAt(T data, int position) 
    {
        if (position == 0)
        {
            head = new Node<T>(data,head);
        }else
        {
            Node<T> * prev = head;
            for (int i = 0; i < position-1; i++)
            {
                prev = prev->next;    
            }
            Node<T> * newNode = new Node<T>(data,prev->next);
            prev->next = newNode;
        }   
        count++;    
    }
template<class T>
void List<T>::removeAt(int position)
{
    if(position == 0)
    {
        Node<T>* first = head;
        head = head->next;
        delete first;
    }else
    {
        Node<T> * prev = head;
        for (int i = 0; i < position - 1; i++)
        {
            prev = prev->next;
        }
        Node<T> * newPrev = prev->next;
        prev->next = newPrev->next;
        delete newPrev;
        
    }
    count--;
}
template<class T>
void List<T>::removeAll()
{
    while (count)
    {
        Node<T> * node = head;
        head = head->next;
        delete node;
     count--;
    }
  
}
template<class T>
T List<T>::getElement(const int position)
{
    Node<T> * check = head;
    int count = 0;
    while (check != nullptr)
    {
        if (count == position)
        {
            return (check->data);
        }
        count++;
        check = check->next;
    }
    return 0;
}
template<class T>
void List<T>::printList( List<T>& n) {
    Node<T>* temp;
    temp = n.head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
template<class T>
ostream& operator << (ostream &out, const List<T>& n)
{
    Node<T> * temp;
    temp = n.head;
    while (temp != NULL) {
        out << temp->data << " ";
        temp = temp->next;
    }
    out << endl;
return out;
}