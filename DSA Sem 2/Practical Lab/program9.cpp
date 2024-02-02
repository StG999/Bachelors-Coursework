// 9. Write a program to print the elements of a linked list in reverse order without disturbing the linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class LinkedList
{
    Node *first;

public:
    LinkedList(int arr[], int n);
    ~LinkedList();
    void Display();
    void ReverseDiplay();
};

LinkedList::LinkedList(int arr[], int n)
{
    first = new Node;
    first->data = arr[0];
    first->prev = NULL;
    first->next = NULL;

    Node *p = first;

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = arr[i];
        t->next = NULL;
        p->next = t;
        t->prev = p;
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

void LinkedList::ReverseDiplay()
{
    Node * p = first;
    while (p->next != NULL)
    {
         p = p->next;

    }
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p ->prev;
    }
    cout<<endl;
    
}

int main()
{
    int arr[] = {1,4,7,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    LinkedList l(arr,n);
    cout<<"Original order : ";
    l.Display();
    cout<<"Reverse Order : ";
    l.ReverseDiplay();

    return 0;
}