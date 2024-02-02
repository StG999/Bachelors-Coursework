#include <iostream>

void merge(int arr[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int b[100];

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }
    }
    for (; i <= mid; i++)
    {
        b[k++] = arr[i];
    }
    for (; j <= h; j++)
    {
        b[k++] = arr[j];
    }
    for (int i = l; i <= h; i++)
    {
        arr[i] = b[i];
    }
}
void Recursive_MergeSort(int arr[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;

        Recursive_MergeSort(arr, l, mid);
        Recursive_MergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main(void)
{
    int array[]= {4, 2, 1, 5, 7, 8, 3, 6};
}