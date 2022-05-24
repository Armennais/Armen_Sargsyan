#include <iostream>
#include <stdexcept>
#include "linkedlist.h"

using namespace std;

void List::Add(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node *new_node = head;
        while (new_node->next != nullptr)
        {
            new_node = new_node->next;
        }
        new_node->next = new Node(data);
    }
    count++;
}

void List::AddAt(int data, int position)
{
    if (position == 0)
    {
        head = new Node(data, head);
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < position - 1; i++)
        {
            prev = prev->next;
        }
        Node *newNode = new Node(data, prev->next);
        prev->next = newNode;
    }
    count++;
}
void List::removeAt(int position)
{
    if (position == 0)
    {
        Node *first = head;
        head = head->next;
        delete first;
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < position - 1; i++)
        {
            prev = prev->next;
        }
        Node *newPrev = prev->next;
        prev->next = newPrev->next;
        delete newPrev;
    }
    count--;
}
void List::removeAll()
{
    while (count)
    {
        Node *node = head;
        head = head->next;
        delete node;
        count--;
    }
}
int List::getElement(const int position)
{

    Node *check = head;
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

ostream &operator<<(ostream &out, const List &n)
{
    Node *temp;
    temp = n.head;
    while (temp != NULL)
    {
        out << temp->data << " ";
        temp = temp->next;
    }
    out << endl;
    return out;
}