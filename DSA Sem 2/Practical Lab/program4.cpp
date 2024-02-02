// 4. Write a program to sort an array.

#include <iostream>
using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                flag++;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}
void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12,3,45,67,32,43,98,76};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array befor Sorting : ";
    Display(arr, n);
    cout<<"Array after Sorting : ";
    BubbleSort(arr, n);
    Display(arr, n);

    return 0;
}