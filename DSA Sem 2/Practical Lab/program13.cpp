// 13. Write a program to implement a stack using an array.

#include <iostream>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack(int size);
    ~Stack();
    void push(int key);
    int pop();
    int topvalue();
    bool empty();
    bool full();
    void Display();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    arr = new int[size];
}

Stack::~Stack()
{
    delete [] arr;
}

void Stack::push(int key)
{
    if (full() == 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        arr[top]=  key;

    }
}

int Stack::pop()
{
    if (empty() == 1)
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else 
    {
        int x = arr[top];
        top--;
        return x;

    }
    
}
int Stack::topvalue()
{
    return arr[top];
}

bool Stack::full()
{
    if (top == size -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

bool Stack::empty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Stack::Display()
{
    for (int i = 0; i <= top; i++)
    {
        cout<<arr[i]<<" ";

    }
    
    cout<<endl;
}

int main()
{
    Stack stk(12);
    stk.push(12);
    stk.Display();
    stk.push(15);
    stk.Display();
    stk.push(18);
    stk.Display();
    stk.pop();
    stk.Display();
    cout<<stk.empty()<<endl;
    cout<<stk.full()<<endl;
    cout<<stk.topvalue()<<endl;

    return 0;
}