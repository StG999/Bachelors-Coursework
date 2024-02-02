// 2. Write a program to insert one element in an array and delete an element from an array.

#include <iostream>
using namespace std;

class Array
{
public:
    int arr[10];
    int length;
    int size;

    Array(int arr1[], int length, int size);
    void Display();
    void Insert(int key, int index);
    int Delete(int index);
};

Array::Array(int arr1[], int length, int size)
{
    this->size = size;
    this->length = length;
    for (int i = 0; i < length; i++)
    {
        arr[i] = arr1[i];
    }
}

void Array::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::Insert(int key, int index)
{
    if (length == size)
    {
        cout << "Array is Full" << endl;
        return;
    }
    else if (index >= size || index < 0)
    {
        cout << "Wrong index" << endl;
    }
    else
    {
        for (int i = length - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        length++;
        arr[index] = key;
    }
}

int Array::Delete(int index)
{
    int x = -1;
    if (length == 0)
    {
        cout<<"Array is Empty"<<endl;
    }
    else if (index < 0 || index >= size)
    {
        cout<<"Wrong index"<<endl;
    }
    else  if( -1 < index < length)
    {
        x = arr[index];
        for (int i = index; i < length - 1; i++)
        {
           arr[i] = arr[i +1];
        }
        length --;
        
    }
    return x;
    
    
}
int main()
{
    int arr1[] = {1,3,5,7,9};
    Array a(arr1,5,10);
    cout<<"Intially the array : ";
    a.Display();
    cout<<"After the Insert : ";
    a.Insert(11,5);
    a.Display();
    cout<<"After the delete : ";
    a.Delete(0);
    a.Display();
    return 0;
}