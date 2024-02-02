// "I have done this assignment on my own. I have not copied any code from another student or
// any online source. I understand if my code is found similar to somebody else's code, my case can
// be sent to the Disciplinary committee of the institute for appropriate action."

#include <bits/stdc++.h>
using namespace std;

// DFS based
void toposort(int node, vector<vector<int>> &adj, stack<int> &s, vector<int> &ans, bool vis[])
{
    vis[node] = 1;

    for (auto neigh : adj[node])
    {
        if (!vis[neigh])
        {
            toposort(neigh, adj, s, ans, vis);
        }
    }

    s.push(node);

    return;
}

int main()
{
    int e, v;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < e; i++)
    {
        char x, y;
        cin >> x >> y;
        // int(x);
        // int(y);
        // x=x-97;
        // y=y-97;
        adj[int(x) - 97].push_back(int(y) - 97);
    }

    bool vis[v] = {false};

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            cout << "here" << endl;
            toposort(i, adj, s, ans, vis);
        }
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    for (auto i : ans)
    {
        cout << char(i + 97) << " ";
    }

    return 0;
}

// Time c = O(V+E)   for loop on v in main() + for loop in toposort()
// space c = O(N) - linear