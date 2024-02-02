#include <iostream>

using namespace std;

void PWC(int arr[], int start, int end, int *counter)
{
    if(start >= end)
        return;
    
    int mid = (start+end)/2;
    (*counter)++;
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
    {
        cout<<"Peak Day: "<<mid<<endl<<"Comparisons: "<<*counter<<endl;
        return;
    }

    else if(arr[mid] < arr[mid-1])
        PWC(arr, start, mid-1, counter);
    
    else if(arr[mid] < arr[mid+1])
        PWC(arr, mid+1, end, counter);
}

int main(void)
{
    int n;
    int counter = 0;
    cin>>n;

    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    PWC(arr, 0, n-1, &counter);
}