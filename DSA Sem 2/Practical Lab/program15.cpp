// 15. Write a program to implement a queue using an array.

#include<iostream>
using namespace std;

class Queue
{
    int front;
    int rear ;
    int size;
    int* arr;

    public:
        Queue(int size);
        ~Queue();
        void enqueue(int key);
        int Dequeue();
        int top();
        int back();
        bool IsEmpty();
        bool IsFull();
        void Display();
};

void Queue::Display()
{
    for (int i = front +1; i <= rear; i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    arr  = new int[size];
}

Queue::~Queue()
{
    delete [] arr;
}

bool Queue::IsEmpty()
{
    if (front == rear)
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
    if (rear == size -1)
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
        cout<<"Queue is full"<<endl;
        return;

    }

    else
    {
        rear ++;
        arr[rear] = key;

    }
    
}


int Queue::Dequeue()
{
    if (IsEmpty() == 1)
    {
        cout<<"Queue is Empty";
        return -1;
    }

    else
    {
        front ++;
        return arr[front];
    }
}

int Queue::back()
{
    if (IsEmpty() == 1)
    {
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    else 
    {
        return arr[rear];
    }
    
}

int Queue::top()
{
    if (IsEmpty() == 1)
    {
        cout<<"Queue is Empty";
        return -1;
    }
    else
    {
        return arr[front +1];
    }
    
}


int main()
{
  Queue q(10);
  q.enqueue(12);
  q.Display();
  q.enqueue(15);
  q.Display();
  q.enqueue(18);
  q.Display();
  q.Dequeue();
  q.Display();

  return 0;
}   