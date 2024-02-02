// 14. Write a program to implement a stack using a linked list.

#include<iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node * next;
};

class Stack
{
    Node * first;

    public:
        Stack();
        ~Stack();
        void push(int key);
        int pop();
        bool IsEmpty();
        bool IsFull();
        int top();
        void Display();

};

void Stack:: Display()
{
    Node * p = first;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

Stack::Stack()
{
    first = NULL;
}

Stack::~Stack()
{
    Node * p ;
    while (first != NULL)
    {
        p = first;
        first = first->next;
        delete p;
    }
    
}

bool Stack::IsEmpty()
{
    if (first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Stack ::IsFull()
{
    Node * t = new  Node ;
    if (t == NULL)
    {
       return 1;
    }
    else
    {
        return false;
    }
    
}

void Stack::push(int key)
{
    if (IsFull() ==  1)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    

    if (first == NULL)
    {
        first = new Node;
        first->data = key;
        first->next = NULL;
        return ;

    }
    else
    {
        Node * p = first;
        Node * t = new Node ;
        t->data =key;
        t->next = p;
        first = t;

    }
    
}

int Stack::pop()
{
    if (IsEmpty() == 1)
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else 
    {
        Node * p = first->next;
        int x = first->data;
        delete first;
        first = p;
        return x;
    }
    
}

int Stack::top()
{
    if (IsEmpty() == 1)
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else
    {
        return first->data;
    }
    
}

int main()
{
    Stack stk;
    stk.push(12);
    stk.Display();
    stk.push(15);
    stk.Display();
    stk.push(18);
    stk.Display();
    stk.pop();
    stk.Display();

  return 0;
}