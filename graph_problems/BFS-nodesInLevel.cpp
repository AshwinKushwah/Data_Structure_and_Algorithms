//Author - Ashwin Kushwah
//BFS Algorithm Implementation - Finding the number of nodes on particular level

//Problem Description -
/*
You have been given a Tree consisting of N nodes. A tree is a fully-connected graph consisting of N nodes and  edges.
The nodes in this tree are indexed from 1 to N. Consider node indexed 1 to be the root node of this tree.
The root node lies at level one in the tree. You shall be given the tree and a single integer x .
You need to find out the number of nodes lying on level x. */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,a,b,x,process, count = 0;
	cin>>n;
	bool graph_matrix [n+1][n+1];
    int queue[n+1], level [n+1], parent[n+1];
	
	memset(level, -1, sizeof(level));
	memset(parent, -1, sizeof(parent));
	
	//marking all the edges as false
	memset(graph_matrix, false, sizeof(graph_matrix));

	for(int i=1; i<=n-1; i++)
     	{
	    cin>>a>>b;
	    graph_matrix[a][b] = true;
	    graph_matrix[b][a] = true;
    	}
        cin>>x;
    //start with Root Node 1;
    
    level[1] = 1; 
    queue[1] = 1;
    
    //Set the initial conditions for quque
    int top = 1;
    int bottom = 1;
    
    //inserting root element into queue
    
    queue[bottom] = 1;
    bottom = bottom + 1;
    
    while(top != bottom)
    {
        process = queue[top];
        top = top +1;          //Removing the head element of queue
    
            for(int j=1; j<n+1; j++)
            {
                if(graph_matrix[process][j] == true || graph_matrix[j][process == true])
                {
                    if(level[j] == -1){
                        level[j] = level[process] + 1;
                        parent[j] = process;
                        
                        //Adding child node to the queue
                        queue[bottom] = j;
                        bottom = bottom + 1;
                        
                    }
                }
            }
       
    }
    for(int i=0; i<n+1; i++){
     if(level[i] == x){
         count = count + 1;
     }
    }
    
    //printing the number of Nodes on Particular level x
    cout<<count;
	return 0;
}
