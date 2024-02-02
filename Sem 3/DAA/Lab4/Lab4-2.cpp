#include <iostream>

using namespace std;

int countingSort(int arr[],int size, int range);

int countingSort(int arr[],int size, int range)
{
    int hashmap[range+1] = {0};

    for(int i=0; i<size; i++)
    {
        hashmap[arr[i]]++;
        if(hashmap[arr[i]] > 1)
            return arr[i];
    }
    
    return -1;
}

int main()
{
    int n, submission, range = 0;
    cin>>n;

    cin>>submission;
    
    int arr[submission];

    for(int i=0; i<submission; i++)
    {
        cin>>arr[i];
        range = max(range, arr[i]);
    }

    cout<<endl;

    int repeat = countingSort(arr, submission, range);
    cout<<"Duplicate submission by student: "<<repeat<<endl;
}