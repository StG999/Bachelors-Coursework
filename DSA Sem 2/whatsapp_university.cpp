#include <iostream>
using namespace std;

void insert(int arr[][10], int n, int head, int insert); //in res

bool search(int arr[][10], int i, int n, int toSearch); //in inp

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    
    // cout<<"0000\n";
    
    int res[n][10];

    // cout<<"0212\n";
    for(int i=1;i<=n;i++)
    {
        res[i][0] = i;

        for(int j=1;j<=n;j++){
            res[i][j]=-1;
            // cout<<res[i][j]<<endl;
        }
    }

    // cout<<"111111111\n";
    
    int inp[m][10];
    
    // cout<<"12121\n";
    for(int i=0;i<m;i++)
    {
        // cout<<"54545\n";
        for(int j=0;j<n;j++)
        {
            // cout<<"878787\n";
            inp[i][j] == -1;
        }
    }
    // cout<<"222222222\n";

    for(int i=1; i<=m;i++)
    {
        // cout<<"333333333\n";
        cin>>inp[i][0];

        if(inp[i][0] == 0)
        {
            continue;
        }

        for(int j=1; j <= inp[i][0]; j++)
        {
            cin>>inp[i][j];
        }
    }

    for(int z=1; z<=n; z++) //searching for that person
    {
        for(int i=1; i<=m; i++) //seaching in every grp (row)
        {
            if(search(inp, i, inp[i][0], z))
            {
                for(int j = 1; j <= inp[i][0]; j++)
                {
                    insert(res, inp[i][0], z, inp[i][j]);

                    // for(int k = 1; k <= n; k++)
                    // {
                    //     if(res[z][k] == inp[k][j])
                    //     {
                    //         break;
                    //     }

                    //     if(res[z][k] == -1)
                    //     {
                    //         res[z][k] = inp[k][j];
                    //         break;
                    //     }
                    // }
                }
            }
        }
    }
    cout<<"here\n";
    // cout<<"final res:\n";
    // for(int i =1; i<=n; i++)
    // {
    //     for (int j=0; j<n; j++)
    //     {
    //         cout<<res[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }
    

    for(int i =1; i<=n; i++)
    {
        for(int j=1; res[i][j] != -1; j++)
        {
            for(int k = 0; res[res[i][j]][k] != -1; k++)
            {
                insert(res, n, i, res[res[i][j]][k]);
                
                // for(int k = 1; k <= n; k++)
                // {
                //     if(res[i][k] == res[res[i][j]][k])
                //     {
                //         break;
                //     }

                //     if(res[i][k] == -1)
                //     {
                //         res[i][k] = res[res[i][j]][k];
                //         break;
                //     }
                // }
            }
        }
    }

    // PRINTING RES
    cout<<"final res:\n";
    for(int i =1; i<=n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<res[i][j]<<" ";
        }

        cout<<endl;
    }
    
    cout<<"ans:\n";
    for(int i =1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(res[i][j] == -1)
            {
                cout<<j<<" ";
                break;
            }
        }
    }
}

bool search(int arr[][10], int i, int n, int toSearch) //in inp
{
    for(int j = 1; j <= n+1; j++)
    {
        if(arr[i][j] == toSearch)
        {
            return true;
        }

        if(arr[i][j] == -1)
        {
            return false;
        }
    }

    return false;
}

void insert(int arr[][10], int n, int head, int ins) //in res
{
    for(int i = 0; i <= n; i++)
    {
        if(arr[head][i] == ins)
        {
            return;
        }

        if(arr[head][i] == -1)
        {
            arr[head][i] = ins;
            return;
        }
    }
}

//OLD VERSIONS OF FUNCTIONS

// void insert(int res[], int n, int head, int insert) //in res
// {
//     for(int i = 1; i <= n; i++)
//     {
//         if(res[head*n + i] == insert)
//         {
//             return;
//         }

//         if(res[head*n + i] == -1)
//         {
//             res[head*n + i] = insert;
//             return;
//         }
//     }
// }

// bool search(int arr[], int i, int n, int toSearch) //in inp
// {
//     for(int j = 1; j <= n+1; j++)
//     {
//         if(arr[i*n + j] == toSearch)
//         {
//             return true;
//         }

//         if(arr[i*n + j] == -1)
//         {
//             return false;
//         }
//     }
// }