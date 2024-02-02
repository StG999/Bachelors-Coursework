#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0; i<n; i++)    
        cin>>arr[i];
    
    sort(arr, arr+n);

    float avg = 0;
    float subSetSize;
    cin>>subSetSize;

    for(int i=0; i<subSetSize; i++)
        avg += arr[n-i-1];


    avg = avg/subSetSize;

    cout<<"Avg of subset of size "<<subSetSize<<" is "<<avg;
}

int partition(int arr[], int start, int end)
{
    int n = end - start + 1, pivot = start;

    for(int i=0; i<n; i++)
    {
        if(arr[start] > arr[start + i])
            pivot++;
    }

    swap(arr[start], arr[pivot]);

    int i = start, j = end;
    
    while(i < pivot && j > pivot)
    {
        while(arr[i] < arr[pivot])
            i++;

        while(arr[j] >= arr[pivot])
            j--;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    return pivot;
}

void quickSort(int arr[], int start, int end)
{
    if(end <= start)
        return;
    
    int pivot = partition(arr, start, end);
    
    quickSort(arr, start, pivot - 1);

    quickSort(arr, pivot + 1, end);

    return;
}