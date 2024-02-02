// I have done this assignment on my own. I have not copied any code from
// another student or any online source. I understand if my code is found
// similar to somebody else's code, my case can be sent to the Disciplinary
// committee of the institute for appropriate action.

#include <bits/stdc++.h>
using namespace std;

class point
{
    public:
        int x, y;
};

int swap(point arr[], int j, int i)
{
    point temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

// QuickSort in X
int patrition_x(point arr[], int l, int r)
{
    int pivot = arr[r].x;
    int j = l - 1;

    for (int i = l; i < r; i++)
    {

        if (arr[i].x < pivot)
        {
            j++;
            swap(arr, j, i);
        }
    }
    swap(arr, j + 1, r);
    return j + 1;
}

int quicksort_x(point arr[], int l, int r)
{
    if (l < r)
    {
        int partition = patrition_x(arr, l, r);
        quicksort_x(arr, l, partition - 1);
        quicksort_x(arr, partition + 1, r);
    }
}

// QuickSort in Y
int patrition_y(point arr[], int l, int r)
{
    int pivot = arr[r].y;
    int j = l - 1;

    for (int i = l; i < r; i++)
    {

        if (arr[i].y < pivot)
        {
            j++;
            swap(arr, j, i);
        }
    }
    swap(arr, j + 1, r);
    return j + 1;
}

int quicksort_y(point arr[], int l, int r)
{
    if (l < r)
    {
        int partition = patrition_y(arr, l, r);
        quicksort_y(arr, l, partition - 1);
        quicksort_y(arr, partition + 1, r);
    }
}

float dist(point p1, point p2)
{
    return (abs(p1.x - p2.x) + abs(p1.y - p2.y));
}

float bruteforce(point p[], int n)
{
    float min_dist = FLT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            min_dist = min(dist(p[i], p[j]), min_dist);
        }
    }

    return min_dist;
}

float stripMin(point strip[], int n, float d)
{
    float minDist = d;

    quicksort_y(strip, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            minDist = min(dist(strip[i], strip[j]), minDist);
        }
    }

    return minDist;
}

float closestH(point p[], int n)
{
    if (n <= 3)
        return bruteforce(p, n);

    int mid = n / 2;
    point midpoint = p[mid];

    float dleft = closestH(p, mid);
    float dright = closestH(p + mid, n - mid);

    float d = min(dleft, dright);

    // creating strip array
    point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(p[i].x - midpoint.x) < d)
        {
            strip[j] = p[i];
            j++;
        }
    }

    float min_strip = stripMin(strip, j, d);

    return min(min_strip, d);
}

float closetPair(point p[], int n)
{
    quicksort_x(p, 0, n - 1);

    return closestH(p, n);
}

int main()
{
    int n;
    cin >> n;

    point p[n];
    // Input coordinates
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }

    cout << closetPair(p, n);
}
