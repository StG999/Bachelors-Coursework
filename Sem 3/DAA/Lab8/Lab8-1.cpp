#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &edges, int source)
{
    vector<int> ans;
    unordered_map<int, vector<int>> umap;
    for (auto x : edges)
    {
        vector<int> v1 = x;
        int a = v1[0];
        int b = v1[1];
        umap[a].push_back(b);
        umap[b].push_back(a);
    }
    int z = umap.size();
    vector<bool> visited(z, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int temp = q.front();
        ans.push_back(q.front());
        q.pop();
        vector<int> v = umap[temp];
        for (int i = 0; i < v.size(); i++)
        {
            if (visited[v[i]])
            {
                continue;
            }
            q.push(v[i]);
            visited[v[i]] = true;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges;
    cout << "enter no of edges";
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        vector<int> temp;
        int x;
        int y;
        cout << "enter edge";
        cin >> x;
        temp.push_back(x);
        cin >> y;
        temp.push_back(y);
        edges.push_back(temp);
    }
    vector<int> fin;
    fin = bfs(edges, 0);
    for (auto x : fin)
    {
        cout << x;
    }
}