#include <iostream>

using namespace std;

typedef struct road
{
    int head;
    int tail;
};

typedef struct city
{
    int name;
    bool visited = false;
};

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    city cities[n];
    road roads[n-1];

    cities[0].visited = true;

    for(int i=0; i<n; i++)
    {
        cities[i].name = i;
    }

    for(int i =0; i<n-1; i++)
    {
        cin>>roads[i].tail>>roads[i].head;
    }

    
}