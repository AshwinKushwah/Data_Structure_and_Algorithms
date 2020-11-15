/*Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll>temp;
    queue<ll>temp2;
    int a=(q.size()-k);
    for(int i=0;i<k;i++)
    {
        temp.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++)
    {
        q.push(temp.top());
        temp.pop();
    }
    
    if(k<q.size())
    {
    for(int i=0;i<a;i++)
    {
        temp2.push(q.front());
        q.pop();
    }
    for(int i=0;i<a;i++)
    {
        q.push(temp2.front());
        temp2.pop();
    }
    }
    return q;
    
    //add code here.
}
