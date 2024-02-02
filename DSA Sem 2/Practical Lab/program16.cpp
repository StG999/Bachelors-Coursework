// 16. Write a program to implement a queue using a linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
    Node *front = NULL;
    Node *rear = NULL;

public:
    ~Queue();
    void enqueue(int);
    int dequeue(void);
    bool IsEmpty(void);
    bool IsFull(void);
    void Display(void);
};

bool Queue::IsEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::IsFull()
{
    Node *t = new Node;
    if (t == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::enqueue(int key)
{
    if (IsFull() == 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        Node *t = new Node;
        t->data = key;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (IsEmpty() == 1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        Node *p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

Queue::~Queue()
{
    Node *p = front;
    Node *t = NULL;
    while (p != NULL)
    {
        t = p;
        p = p->next;
        delete t;
    }
}

void Queue::Display()
{
    Node *p = front;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    
}

int main()
{
    Queue l;
    l.enqueue(9);
    l.enqueue(8);
    l.enqueue(7);
    l.Display();
    l.dequeue();
    l.Display();
    cout<<l.IsEmpty()<<endl;
    cout<<l.IsFull()<<endl;
    
    return 0;

}