#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
using namespace std;

class Node {
 public:
    int data;
    Node* next;
    Node(int data,Node* next=nullptr)
    {
        this->data = data; 
        this->next = next;
    }
};

class List{
    Node* head;
    int count;
    public:
        int GetCount(){return count;}
        void Add(int );
        void AddAt(int , int );
        void removeAt(int );
        void removeAll();
        int getElement(const int );
		friend ostream& operator << (ostream &out, const List&);
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