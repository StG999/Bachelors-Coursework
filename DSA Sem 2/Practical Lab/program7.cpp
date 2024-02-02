// 7. Write a program to implement a linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int main()
{
    Node *head = new Node;
    head->data = 4;
    head->next = NULL;
    cout << head->data << endl;

    return 0;
}