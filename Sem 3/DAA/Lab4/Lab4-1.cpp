#include <iostream>

using namespace std;

int countingSort(int arr[],int size, int range);
float medianArr(int arr[], int size);

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

    int mode = countingSort(arr, n, range);

    float median = medianArr(arr, n);

    cout<<"Frequent Value: "<<mode<<endl;
    cout<<"Median: "<<median<<endl;
    cout<<"Diff: "<<abs(median-mode)<<endl;
}

float medianArr(int arr[], int size)
{
    if(size%2 != 0)
        return arr[size/2];
    
    return (arr[size/2] + arr[size/2-1])/2.0;
}

int countingSort(int arr[],int size, int range)
{
    int hashmap[range+1] = {0};

    for(int i=0; i<size; i++)
        hashmap[arr[i]]++;

    int counter = 0, max = 0, maxIndex = 0;

    for(int i=0; i<range+1; i++)
        if(hashmap[i] != 0)
        {
            if(hashmap[i] > max)
            {
                maxIndex = i;
                max = hashmap[i];
            }
            arr[counter] = i;
            counter++;
            hashmap[i]--;
            i--;
        }
    
    return maxIndex;
}