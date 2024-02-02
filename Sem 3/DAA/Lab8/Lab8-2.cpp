#include <bits/stdc++.h>
using namespace std;

void dfs_print(int **edges, int sv, bool *visited, int n)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            dfs_print(edges, i, visited, n);
        }
    }
}
int main()
{
    cout << "enter no of nodes and edges" << endl;
    int n;
    int e;
    cin >> n;
    cin >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        cout << "enter edge" << endl;
        int f;
        int s;
        cin >> f;
        cin >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs_print(edges, i, visited, n);
        }
        cout << endl;
    }
}