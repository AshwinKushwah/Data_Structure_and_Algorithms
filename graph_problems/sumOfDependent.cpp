#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[], int u,int v)
{
    adj[u].push_back(v);
}

int findSum(vector<int> adj[], int V)
{
    int sum = 0;

    for (int u = 0; u < V; u++)
        sum += adj[u].size();

    return sum;
}

int main()
{
    int V = 5; 
    vector<int >adj[V];
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,4,1);

    cout << "Sum of dependencies is " << findSum(adj, V);
    return 0;
}