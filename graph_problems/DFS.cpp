#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int source, int parent, vector<int> adj[], bool visited[])
{
    if (visited[source])
        return;
    visited[source] = true;

    cout << source << " ";

    for (int next : adj[source])
    {
        if (next == parent)
            continue;
        dfs(next, source, adj, visited);
    }
}

int main()
{
    vector<int> adj[10];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    addEdge(adj, 7, 5);
    addEdge(adj, 7, 8);
    addEdge(adj, 5, 8);
    addEdge(adj, 8, 9);

    bool visited[10];
    memset(visited, 0, sizeof visited);

    dfs(0, -1, adj, visited);

    return 0;
}