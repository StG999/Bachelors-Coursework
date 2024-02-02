#include <iostream>

using namespace std;

typedef struct leaf
{
    int city;
    int *Lbranch = NULL;
    int *Rbranch = NULL;
};

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    int arr[n][2];

    for(int i = 0; i <n; i++)
    {
        for(int j =0; j<2; j++)
        {
            arr[i][j] = -1;
        }
    }

    for(int i =0; i <n-1; i++)
    {
        int t, w;
        cin>>t>>w;
        for(int j =0; j<2; j++)
        {
            if(arr[t][j] == -1)
            {
                arr[t][j] = w;
                break;
            }
        }
    }
    
    leaf head;
    leaf *root = &head;
    head.city = 1;

    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<2; j++)
        {
            if(arr[i][j] != -1)
            {
                
            }
        }
    }
    // if(arr[1][0] != -1)
    // {
    //     head.Lbranch = arr[1][0];
    // }
    
    // if(arr[1][1] != -1)
    // {
    //     head.Rbranch = arr[1][1];
    // }

    // if(arr[1][2] != -1)
    // {
    //     head.Cbranch = arr[1][2];
    // }
}

// typedef struct road
// {
//     int head;
//     int tail;
// };

// typedef struct city
// {
//     int name;
//     bool visited = false;
// };

// int main(void)
// {
//     int n;
//     cout<<"n: ";
//     cin>>n;

//     city cities[n];
//     road roads[n-1];

//     cities[0].visited = true;

//     for(int i=0; i<n; i++)
//     {
//         cities[i].name = i;
//     }

//     for(int i =0; i<n-1; i++)
//     {
//         cin>>roads[i].tail>>roads[i].head;
//     }

    
// }