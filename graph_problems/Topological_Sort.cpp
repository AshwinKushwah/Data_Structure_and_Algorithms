#include<bits/stdc++.h>

#define ll long long
#define fo(i,n) for(i = 0;i < n;i++)
using namespace std;

//Topological sort is the ordering 
//of vertices of a Directed Acyclic Graph (DAG)
//such that for any edge from A -> B, A comes 
//before B in the Topological ordering of vertices.

#define N 200005
vector<ll> adj[N];
bool vis[N];
stack<ll> st;

ll n;
ll e;


void Topological_Sort_Util(ll vertex){
    cout<<"GG\n";
    vis[vertex] = 1;
    for(ll v : adj[vertex]){
        if(!vis[v])
            Topological_Sort_Util(v);
    }
    st.push(vertex);
    cout<<"pp\n";
}

vector<ll> Topological_Sort(){
    cout<<"WE\n";
    for(ll v = 1;v <= n;v++){
        if(!vis[v])
            Topological_Sort_Util(v);
    }
    vector<ll> vec;
    while(st.size()){
        vec.push_back(st.top());
        st.pop();
    }
    return vec;
    cout<<"WE2\n";
}

int main(){
    memset(vis,0,sizeof vis);    
    cout<<"Enter the number of Vertices : ";
    cin>>n;
    
    cout<<"Enter the number of Edges : ";
    cin>>e;

    while(e--){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    vector<ll> topo = Topological_Sort();

    for(ll v : topo){
        cout<<v<<", ";
    }
    cout<<endl;

    return 0;
}
