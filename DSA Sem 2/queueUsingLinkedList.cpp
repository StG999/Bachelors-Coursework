#include <iostream>
using namespace std;
 
struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};
 
struct Queue {
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
 
    void enQueue(int x)
    {
        QNode* temp = new QNode(x);

        if(real == NULL)
        {
               temp = ;

        }