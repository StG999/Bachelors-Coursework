// 5. Write a program to merge two sorted arrays.

#include <iostream>
using namespace std;

int *Merge(int arr1[], int n1, int arr2[], int n2)
{
    int *arr3 = new int[n1 + n2];
    int i, j, k;
    i = j = k = 0;
    while (i != n1 && j != n2)
    {
        if (arr1[i] > arr2[j])
        {
            arr3[k++] = arr2[j++];
        }
        else
        {
            arr3[k++] = arr1[i++];
        }
    }
    for (; i < n1; i++)
    {
        arr3[k++] = arr1[i];
    }
    for (; j < n2; j++)
    {
        arr3[k++] = arr2[j];
    }
    return arr3;
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
    int arr1[] = {23, 65, 121, 340, 875, 2589};
    int arr2[] = {42, 54, 110, 441, 523, 990, 2233};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int n1 = sizeof(arr2) / sizeof(arr2[0]);
    int *arr = Merge(arr1, n, arr2, n1);
    cout << "Ist sorted array : ";
    Display(arr1, n);
    cout << "2nd Sorted array : ";
    Display(arr2, n1);
    cout << "Merged array : ";
    Display(arr, n + n1);
    delete [] arr;

    return 0;
}