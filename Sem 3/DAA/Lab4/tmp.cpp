#include <iostream>

using namespace std;

int countingSort(int arr[],int size, int range)
{
    int counting[range+1] = {0};

    for(int i=0; i<size; i++)
        counting[arr[i]]++;

    int counter = 0, max = 0, maxIndex = 0;

    for(int i=0; i<range+1; i++)
        if(counting[i] != 0)
        {
            if(counting[i] > max)
            {
                maxIndex = i;
                max = counting[i];
            }
            arr[counter] = i;
            counter++;
            counting[i]--;
            i--;
        }
    
    return maxIndex;
}

float medianArr(int arr[], int size)
{
    if(size%2 != 0)
        return arr[size/2];
    
    return (arr[size/2] + arr[size/2-1])/2.0;
}

int main()
{
    int n, range = -1;
    cin>>n;

    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        range = max(range, arr[i]);
    }

    int fvalue = countingSort(arr, n, range);

    float median = medianArr(arr, n);

    cout<<"Frequent Value: "<<fvalue<<endl;
    cout<<"Median: "<<median<<endl;
    int difference = median - fvalue;
    
    if(difference>=0)
        cout<<"Difference: "<<difference<<endl;

    else
        cout<<"Difference: "<<-1 * difference<<endl;
        
}