// 10. Write a program to reverse a linked list.

#include<iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node* next;
};

class LinkedList
{
    Node * first;

    public:
        LinkedList(int arr[],int n);
        ~LinkedList();
        void reverse();
        void Display();
};

LinkedList::LinkedList(int arr[],int n)
{
    first = new Node ;
    first->data = arr[0];
    first->next = NULL;
    Node * p = first;

    for (int i = 1; i < n; i++)
    {
        Node * t = new Node;
        t->data = arr[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
    
}

LinkedList::~LinkedList()
{
    Node *p;
    while (first != NULL)
    {
        p = first;
        first = first->next;
        delete p;
    }
}

void LinkedList::reverse()
{
    int count = 0;
    Node * p = first;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    p = first;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }
    p = first;
    for (int i = 0; i < count; i++)
    {
        p->data = arr[count-i-1];
        p = p->next;
    }
    
    
}

void LinkedList::Display()
{
    Node * p = first;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    int arr[] = {3,5,4,8,6,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    LinkedList l(arr,n);
    cout<<"Original order : ";
    l.Display();
    cout<<"After Reverse : ";
    l.reverse();
    l.Display();

 
 return 0;
}