// 8. Write a program to insert a node in a linked list and delete a node from a linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    Node *first;

public:
    LinkedList();
    ~LinkedList();
    void Insert(int key);
    int Delete(int index);
    void Display();
    int count();
};

void LinkedList::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    
}

int LinkedList::count()
{
    Node *p = first;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

LinkedList::LinkedList()
{
    first = NULL;
}

LinkedList::~LinkedList()
{
    while (first != NULL)
    {
        Node *p = first;
        first = first->next;
        delete p;
    }
}

void LinkedList::Insert(int key)
{
    if (first == NULL)
    {
        first = new Node;
        first->data = key;
        first->next = NULL;
    }
    else
    {
        Node *t = new Node;
        t->data = key;
        t->next = NULL;
        Node *p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    if (count() == 0)
    {
        cout << "linkedList is Empty" << endl;
        return -1;
    }
    else if (index > 0 && index <= count())
    {
        if (index == 1)
        {
            Node *p = first->next;
            int x = first->data;
            delete first;
            first = p;
            return x;
        }
        else
        {
            Node *p, *q;
            p = first;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            int x = p->data;
            q->next = p->next;
            delete p;
            return x;
        }
    }
    return -1;
}

int main()
{
    LinkedList l;
    l.Insert(12);
    l.Display();

    l.Insert(9);
    l.Display();

    l.Insert(5);
    l.Display();

    l.Delete(2);
    l.Display();

    return 0;
}