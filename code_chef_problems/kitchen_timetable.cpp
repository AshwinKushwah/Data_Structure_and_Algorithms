#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        A[0]=0;
        for(int i=1;i<n+1;i++){
            cin>>A[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            if((A[i+1]-A[i])>=k){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}