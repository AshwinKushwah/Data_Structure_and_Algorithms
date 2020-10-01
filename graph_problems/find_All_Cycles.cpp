#include<bits/stdc++.h>

#define ll long long
#define fo(i,n) for(i = 0;i < n;i++)
using namespace std;

//Caution : Does not work well if there are
//multiple cycles having same node.

//This algorithm is used to find cycles
//in a graph. It uses coloring method.
//All nodes are initially colored 0
//When we start DFS on any node we mark
//it as 1, whenever we finish DFS of any node
//we mark it as 2. So a cycle is present in the
//graph if we arrive at a node which is marked 1,
//that means its DFS is not complete and we still
//reached it. So now we know the cycle , we need to 
//mark all the parents of it to 2, so we need a parent
//hash array that stores the indices of the parents.
//Also we need the parent array if we need to print 
//the cycles.


const ll N = 1e5+5;
ll parent[N];
ll color[N];
ll mark[N];
vector<ll> adj[N];
vector<ll> cycles[N];

void DFS(ll cur_parent, ll ind,
                ll &total_cylces){

    if(color[ind] == 2)
        return;
    else if(color[ind] == 1){
        ll cur = cur_parent;
        mark[cur] = total_cylces;
        while(cur != ind){
            cur = parent[cur];
            mark[cur] = total_cylces;
        }
        total_cylces++;
    }else{
        parent[ind] = cur_parent;
        color[ind] = 1;
        for(int i : adj[ind]){
            if(i != cur_parent)DFS(ind,i,total_cylces);
        }
        color[ind] = 2;
        return ;
    }

}

void All_cycles(ll n,ll &total_cylces,bool printCycles){
    DFS(0,1,total_cylces);
    //Nodes are numbered from 1 to n
    for(ll i = 1;i <= n;i++){
        if(mark[i] != -1)
            cycles[mark[i]].push_back(i);
    }
    if(printCycles){
        for(ll i = 0;i < total_cylces;i++){
            cout<<"Cycle : "<<i+1<<" is : ";
            for(int v = 0;v < cycles[i].size();v++){
                cout<<cycles[i][v]<<" "; 
            }
            cout<<endl;
        }
    }
}

int main(){
    ll n,e,i;
    cin>>n>>e;
    fo(i,n+2)
        adj[i].clear(),color[i] = mark[i] = -1;

    //This graph must be a connected graph
    //if not then we need to just add a 
    //for loop and put the cycle functions inside.
    fo(i,e){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll total_cylces = 0;
    bool printCycles = false;

    All_cycles(n,total_cylces, printCycles);
    cout<<total_cylces<<endl;
    return 0;
}
/*
13 14
1 2
2 3 
3 4 
4 6
4 7 
5 6 
3 5
7 8 
6 10 
5 9
10 11 
11 12 
11 13 
12 13

 */
