#include<bits/stdc++.h>
using namespace std;
int V = 10;
void addEdge(vector<int>adj[], int v1, int v2)
{
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
	
}

void BFS(vector<int>adj[])
{
	bool visited[10];
	
	memset(visited,false, sizeof(visited));
	
	queue<int>q;
	q.push(0);
	visited[0] = true;
	
	vector<int>::iterator i; 
	
	cout<<0<<" ";
	while(q.empty() == false)
	{
		int j = q.front();
		
		
		q.pop();
		for(i=adj[j].begin(); i != adj[j].end(); i++)
		{    
		
			if(visited[*i] == false)
			{
				visited[*i] = true;
				cout<<*i<<"  ";
				q.push(*i);
			}
		}

	}
}
int main()
{
	
	vector<int>adj[10];
	addEdge(adj, 0, 1);
	addEdge(adj, 0,2);
	addEdge(adj, 1,2);
	addEdge(adj, 0,3);
	addEdge(adj, 3,4);
	addEdge(adj, 3,7);
	addEdge(adj, 4,5);
	addEdge(adj, 4,6);
	addEdge(adj, 5,6);
	addEdge(adj, 7,5);
	addEdge(adj, 7,8);
	addEdge(adj, 5,8);
	addEdge(adj, 8,9);
	
	
	BFS(adj);

 return 0;

}