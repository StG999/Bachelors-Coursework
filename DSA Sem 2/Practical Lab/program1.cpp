// 1. Write a program to find the mean and the median of the numbers stored in an array

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

int main()
{
    int n;
    cout << "Enter the number of numbers you wanted in your array" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " element in the array" << endl;
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    float mean = sum / n;

    BubbleSort(arr, n);
    float median;
    if (n % 2 == 0)
    {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
    else if (n % 2 != 0)
    {
        median = arr[(n - 3) / 2];
    }

    cout<<"Mean of the input array is "<<mean<<endl;
    cout<<"Median of the input array is "<<median<<endl;

    return 0;
}