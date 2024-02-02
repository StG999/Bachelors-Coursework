// 3. Write a program to search for a number in an array.

#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[], int n, int key)
{
    int l = 0;
    int h = n - 1;
    int mid = (l + h) / 2;
    while (l <= h)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            h = mid - 1;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 2, 6, 4, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = LinearSearch(arr, n, 2);

    if (x != -1)
    {
        cout << "Element is found at " << x << " index" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    int y = BinarySearch(arr,n,6);
     if (y != -1)
    {
        cout << "Element is found at " << y << " index" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
