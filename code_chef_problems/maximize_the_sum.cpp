#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int sum=0;
        list <long long int> A;
        long long int a,b,c;
        for(long long int i=0;i<n;i++){
            cin>>a;
            A.push_back(a);
        }
        A.sort();
        while(A.size()){
            b=A.front();
            A.pop_front();
            c=A.back();
            A.pop_back();
            sum+=abs(b-c);
        }
        cout<<sum<<endl;
    }
    return 0;
}