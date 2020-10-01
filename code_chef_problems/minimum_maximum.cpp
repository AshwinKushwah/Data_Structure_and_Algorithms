// My first approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>V;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            V.push_back(a);
        }
        sort(V.begin(), V.end());
        int total_cost=0;
        for(int i=1;i<n;i++){
            V.pop_back();
            total_cost=total_cost+V.at(0);
        }
        cout<<total_cost<<endl;
    }
    return 0;
}





// Best approach
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long minimum_element = LONG_MAX;
        for(long long i=0;i<n;i++){
            long long a;
            cin>>a;
            if(a<=minimum_element)
                minimum_element = a;
        }
        cout<<minimum_element*(n-1)<<endl;
    }
}