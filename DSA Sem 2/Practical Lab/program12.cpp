// 12. Write a program to implement a doubly-linked list.

#include<iostream>
using namespace std;

class Node 
{
    public:
        Node *prev;
        int data;
        Node * next;
};

class LinkedList
{
    Node * first;
    public:
        LinkedList();
        ~LinkedList();
        void Display();
        void Insert(int key);
        int Delete();
};

LinkedList::LinkedList()
{
    first = NULL;
}

LinkedList::~LinkedList()
{
    Node * p ;
    while(first != NULL)
    {
        p = first;
        first = first->next;
        delete p;
    }
}

void LinkedList:: Display()
{
    Node * p = first;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;   
}

void LinkedList::Insert(int key)
{
    if (first == NULL)
    {
        first = new Node ;
        first->data = key;
        first->next = NULL;
        first->prev  = NULL;
        return ;
    }
    
    else
    {
        Node * p = first;
        while(p->next != NULL)
        {
            p = p->next;
        }
        Node * t = new Node;
        t->data = key;
        t->next  =NULL;
        p->next = t;
        t->prev = p;
        
    }
}

int LinkedList::Delete()
{
    if (first ==NULL)
    {
      cout<<"LinkedList is empty"<<endl;
      return -1;
    }
    else{
        Node * p = first;
        Node *q;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        int x = p->data;
        delete p;
        return x;
    }
    
}

int main()
{
    LinkedList l;
    l.Insert(12);
    l.Display();
    l.Insert(13);
    l.Display();
    l.Insert(14);
    l.Display();
    l.Delete();
    l.Display();
  
  return 0;
}